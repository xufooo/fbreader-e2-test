/*
 * FBReader -- electronic book reader
 * Copyright (C) 2004-2006 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include <abstract/ZLInputStream.h>

#include "FB2BookReader.h"
#include "Base64EncodedImage.h"
#include "../../bookmodel/BookModel.h"
#include "../../model/Paragraph.h"

FB2BookReader::FB2BookReader(BookModel &model) : myModelReader(model) {
	myInsideCoverpage = false;
	myParagraphsBeforeBodyNumber = (size_t)-1;
	myInsidePoem = false;
	mySectionDepth = 0;
	myBodyCounter = 0;
	myCurrentImage = 0;
	myProcessingImage = false;
	mySectionStarted = false;
	myInsideTitle1 = false;
}

void FB2BookReader::characterDataHandler(const char *text, int len) {
	if ((len > 0) && (myProcessingImage || myModelReader.paragraphIsOpen())) {
		std::string str(text, len);
		if (myProcessingImage) {
			myImageBuffer.push_back(str);
		} else {
			myModelReader.addData(str);
			myModelReader.addContentsData(str);
		}
	}
}

static const char *reference(const char **xmlattributes) {
	while (*xmlattributes != 0) {
		int len = strlen(*xmlattributes);
		bool useNext = (len >= 5) && (strcmp((*xmlattributes) + len - 5, ":href") == 0);
		++xmlattributes;
		if (*xmlattributes == 0) {
			return 0;
		}
		if (useNext) {
			break;
		}
		++xmlattributes;
	}
	const char *ref = *xmlattributes;
	return ((ref != 0) && (*ref == '#')) ? ref + 1 : 0;
}
	
void FB2BookReader::startElementHandler(int tag, const char **xmlattributes) {
	const char *id = attributeValue(xmlattributes, "id");
	if (id != 0) {
		if (myBodyCounter > 1) {
			myModelReader.setFootnoteTextModel(id);
		} else {
			myModelReader.addHyperlinkLabel(id);
		}
	}
	switch (tag) {
		case _P:
			if (mySectionStarted) {
				myModelReader.beginContentsParagraph();
				if (!myInsideTitle1) {
					myModelReader.endContentsParagraph();
				}
				mySectionStarted = false;
			} else if (myInsideTitle1) {
				static const std::string SPACE = " ";
				myModelReader.addContentsData(SPACE);
			}
			myModelReader.beginParagraph();
			break;
		case _V:
			myModelReader.pushKind(VERSE);
			myModelReader.beginParagraph();
			break;
		case _SUBTITLE:
			myModelReader.pushKind(SUBTITLE);
			myModelReader.beginParagraph();
			break;
		case _TEXT_AUTHOR:
			myModelReader.pushKind(AUTHOR);
			myModelReader.beginParagraph();
			break;
		case _DATE:
			myModelReader.pushKind(DATE);
			myModelReader.beginParagraph();
			break;
		case _CITE:
			myModelReader.pushKind(CITE);
			break;
		case _SECTION:
			myModelReader.insertEndOfSectionParagraph();
			++mySectionDepth;
			mySectionStarted = true;
			break;
		case _TITLE:
			if (myInsidePoem) {
				myModelReader.pushKind(POEM_TITLE);
			} else if (mySectionDepth == 0) {
				myModelReader.insertEndOfSectionParagraph();
				myModelReader.pushKind(TITLE);
			} else {
				myModelReader.pushKind(SECTION_TITLE);
				myModelReader.enterTitle();
				myInsideTitle1 = true;
			}
			break;
		case _POEM:
			myInsidePoem = true;
			break;
		case _STANZA:
			myModelReader.pushKind(STANZA);
			myModelReader.beginParagraph(Paragraph::BEFORE_SKIP_PARAGRAPH);
			myModelReader.endParagraph();
			break;
		case _EPIGRAPH:
			myModelReader.pushKind(EPIGRAPH);
			break;
		case _ANNOTATION:
			if (myBodyCounter == 0) {
				myModelReader.setMainTextModel();
			}
			myModelReader.pushKind(ANNOTATION);
			break;
		case _COVERPAGE:
			if (myBodyCounter == 0) {
			  myInsideCoverpage = true;
				myModelReader.setMainTextModel();
			}
			break;
		case _SUB:
			myModelReader.addControl(SUB, true);
			break;
		case _SUP:
			myModelReader.addControl(SUP, true);
			break;
		case _CODE:
			myModelReader.addControl(CODE, true);
			break;
		case _STRIKETHROUGH:
			myModelReader.addControl(STRIKETHROUGH, true);
			break;
		case _STRONG:
			myModelReader.addControl(STRONG, true);
			break;
		case _EMPHASIS:
			myModelReader.addControl(EMPHASIS, true);
			break;
		case _A:
		{
			const char *ref = reference(xmlattributes);
			if (ref != 0) {
				myModelReader.addHyperlinkControl(FOOTNOTE, ref);
			} else {
				myModelReader.addControl(FOOTNOTE, true);
			}
			break;
		}
		case _IMAGE:
		{
			const char *ref = reference(xmlattributes);
			if (ref != 0) {
				if ((myCoverImageReference != ref) ||
			      (myParagraphsBeforeBodyNumber != myModelReader.model().bookTextModel().paragraphsNumber())) {
				  myModelReader.addImageReference(ref);
				}
				if (myInsideCoverpage) {
				  myCoverImageReference = ref;
				}
			}
			break;
		}
		case _BINARY:
		{
			const char *contentType = attributeValue(xmlattributes, "content-type");
			const char *id = attributeValue(xmlattributes, "id");
			if ((contentType != 0) && (id != 0)) {
				myCurrentImage = new Base64EncodedImage(contentType);
				myModelReader.addImage(id, myCurrentImage);
				myProcessingImage = true;
			}
			break;
		}
		case _EMPTY_LINE:
			myModelReader.beginParagraph(Paragraph::EMPTY_LINE_PARAGRAPH);
			myModelReader.endParagraph();
			break;
		case _BODY:
			++myBodyCounter;
			myParagraphsBeforeBodyNumber = myModelReader.model().bookTextModel().paragraphsNumber();
			if (myBodyCounter == 1) {
				myModelReader.setMainTextModel();
			}
			myModelReader.pushKind(REGULAR);
			break;
		default:
			break;
	}
}

void FB2BookReader::endElementHandler(int tag) {
	switch (tag) {
		case _P:
			myModelReader.endParagraph();
			break;
		case _V:
		case _SUBTITLE:
		case _TEXT_AUTHOR:
		case _DATE:
			myModelReader.popKind();
			myModelReader.endParagraph();
			break;
		case _CITE:
			myModelReader.popKind();
			break;
		case _SECTION:
			if (myBodyCounter > 1) {
				myModelReader.unsetTextModel();
			}
			--mySectionDepth;
			mySectionStarted = false;
			break;
		case _TITLE:
			myModelReader.exitTitle();
			myModelReader.popKind();
			myModelReader.endContentsParagraph();
			myInsideTitle1 = false;
			break;
		case _POEM:
			myInsidePoem = false;
			break;
		case _STANZA:
			myModelReader.beginParagraph(Paragraph::AFTER_SKIP_PARAGRAPH);
			myModelReader.endParagraph();
			myModelReader.popKind();
			break;
		case _EPIGRAPH:
			myModelReader.popKind();
			break;
		case _ANNOTATION:
			myModelReader.popKind();
			if (myBodyCounter == 0) {
				myModelReader.insertEndOfSectionParagraph();
				myModelReader.unsetTextModel();
			}
			break;
		case _COVERPAGE:
			if (myBodyCounter == 0) {
			  myInsideCoverpage = false;
				myModelReader.insertEndOfSectionParagraph();
				myModelReader.unsetTextModel();
			}
			break;
		case _SUB:
			myModelReader.addControl(SUB, false);
			break;
		case _SUP:
			myModelReader.addControl(SUP, false);
			break;
		case _CODE:
			myModelReader.addControl(CODE, false);
			break;
		case _STRIKETHROUGH:
			myModelReader.addControl(STRIKETHROUGH, false);
			break;
		case _STRONG:
			myModelReader.addControl(STRONG, false);
			break;
		case _EMPHASIS:
			myModelReader.addControl(EMPHASIS, false);
			break;
		case _A:
			myModelReader.addControl(FOOTNOTE, false);
			break;
		case _BINARY:
			if (!myImageBuffer.empty() && (myCurrentImage != 0)) {
				myCurrentImage->addData(myImageBuffer);
				myImageBuffer.clear();
				myCurrentImage = 0;
			}
			myProcessingImage = false;
			break;
		case _BODY:
			myModelReader.popKind();
			myModelReader.unsetTextModel();
			break;
		default:
			break;
	}
}

bool FB2BookReader::readBook(const std::string &fileName) {
	return readDocument(fileName);
}
