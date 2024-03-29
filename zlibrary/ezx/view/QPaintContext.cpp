/*
 * Copyright (C) 2004-2006 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 *
 * Port for the Motorola A780/E680i is 
 * Copyright (C) 2006 Ketut P. Kumajaya <kumajaya@bluebottle.com>
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

#include <qpainter.h>
#include <qpixmap.h>
#include <qfontmetrics.h>
#include <qfontdatabase.h>
#include <qimage.h>

#include <abstract/ZLUnicodeUtil.h>
#include <abstract/ZLImage.h>

#include "QPaintContext.h"
#include "../../qt/image/QImageManager.h"

QPaintContext::QPaintContext() {
	myPainter = new QPainter();
	myPixmap = NULL;
	mySpaceWidth = -1;
	myFontIsStored = false;
}

QPaintContext::~QPaintContext() {
	if (myPixmap != NULL) {
		myPainter->end();
		delete myPixmap;
	}
	delete myPainter;
}

void QPaintContext::setSize(int w, int h) {
	if (myPixmap != NULL) {
		if ((myPixmap->width() != w) || (myPixmap->height() != h)) {
			myPainter->end();
			delete myPixmap;
			myPixmap = NULL;
		}
	}
	if ((myPixmap == NULL) && (w > 0) && (h > 0)) {
		myPixmap = new QPixmap(w, h);
		myPainter->begin(myPixmap);
		if (myFontIsStored) {
			myFontIsStored = false;
			setFont(myStoredFamily, myStoredSize, myStoredBold, myStoredItalic);
			myPainter->setFont(myFont);/*ooo added*/
		}
	}
}

static const std::string HELVETICA = "helvetica";

void QPaintContext::fillFamiliesList(std::vector<std::string> &families) const {
	bool helveticaFlag = false;
	QFontDatabase db;
	QStringList qFamilies = db.families();
	for (QStringList::Iterator it = qFamilies.begin(); it != qFamilies.end(); ++it) {
		std::string family = (*it).ascii();
		if (family == HELVETICA) {
			helveticaFlag = true;
		}
		families.push_back(family);
	}
	if (!helveticaFlag) {
		families.push_back(HELVETICA);
	}
}

const std::string QPaintContext::realFontFamilyName(std::string &fontFamily) const {
	QString fullName = QFontInfo(QFont(fontFamily.c_str())).family();
	if (fullName.isNull() || fullName.isEmpty()) {
		fullName = QFontInfo(QFont::defaultFont()).family();
		if (fullName.isNull() || fullName.isEmpty()) {
			return HELVETICA;
		}
	}
	return fullName.left(fullName.find(" [")).ascii();
}

void QPaintContext::setFont(const std::string &family, int size, bool bold, bool italic) {
	if (myPainter->device() == 0) {
		myFontIsStored = true;
		myStoredFamily = family;
		myStoredSize = size;
		myStoredBold = bold;
		myStoredItalic= italic;
	} else {
	/*	QFont font = myPainter->font(); ooo use myFont instead of this*/
//		QFont font = myFont;/*next: use myFont instead of QFont font*/
		bool fontChanged = false;
/*ooo changed font to myFont*/
		if (myFont.family() != family.c_str()) {
			myFont.setFamily(family.c_str());
			fontChanged = true;
		}

		if (myFont.pointSize() != size) {
			myFont.setPointSize(size);
			fontChanged = true;
		}

		if ((myFont.weight() != (bold ? QFont::Bold : QFont::Normal))) {
			myFont.setWeight(bold ? QFont::Bold : QFont::Normal);
			fontChanged = true;
		}

		if (myFont.italic() != italic) {
			myFont.setItalic(italic);
			fontChanged = true;
		}

		if (fontChanged) {
/*		        myPainter->setFont(font);ooo comment this to avoid segmentation fault */
//				myFont = font;/*ooo added*/
			mySpaceWidth = -1;
		}
	}
}

void QPaintContext::setColor(ZLColor color, LineStyle style) {
	myPainter->setPen(QPen(
		QColor(color.Red, color.Green, color.Blue),
		1,
		(style == SOLID_LINE) ? QPainter::SolidLine : QPainter::DashLine
	));
}

void QPaintContext::setFillColor(ZLColor color, FillStyle style) {
	myPainter->setBrush(QBrush(
		QColor(color.Red, color.Green, color.Blue),
		(style == SOLID_FILL) ? QPainter::SolidPattern : QPainter::Dense4Pattern
	));
}

int QPaintContext::stringWidth(const char *str, int len) const {
    QString qStr = QString::fromUtf8(str, len);
	for (unsigned int i=0; i<qStr.length(); i++) {
	    if (qStr[i] == QChar(0x14,0x20) ||
		qStr[i] == QChar(0x13,0x20))
		qStr[i] = QChar('-', 0);
	}
    return myPainter->fontMetrics().width(qStr);
}

int QPaintContext::spaceWidth() const {
	if (mySpaceWidth == -1) {
		mySpaceWidth = myPainter->fontMetrics().width(" ");
	}
	return mySpaceWidth;
}

int QPaintContext::stringHeight() const {
//	return myPainter->font().pointSize() + 2; ooo fixed myPainter->font may cause sf
	return myFont.pointSize() + 2;
}

void QPaintContext::drawString(int x, int y, const char *str, int len) {
	QString qStr = QString::fromUtf8(str, len);
	for (unsigned int i=0; i<qStr.length(); i++) {
	    if (qStr[i] == QChar(0x14,0x20) ||
		qStr[i] == QChar(0x13,0x20))
		qStr[i] = QChar('-', 0);
	}
//	myPainter->drawText(x + leftMargin(), y + topMargin(),0,-1,-1, qStr);
	myPainter->drawText(x + leftMargin(), y + topMargin(),stringWidth(str,len),stringHeight()+3,0, qStr);
//	myPainter->drawText(x + leftMargin(), y + topMargin(), qStr);
}

void QPaintContext::drawImage(int x, int y, const ZLImageData &image) {
	const QImage &qImage = (ZLQImageData&)image;
	myPainter->drawImage(x + leftMargin(), y + topMargin() - qImage.height(), qImage);
}

void QPaintContext::drawLine(int x0, int y0, int x1, int y1) {
	myPainter->drawLine(x0 + leftMargin(), y0 + topMargin(),
											x1 + leftMargin(), y1 + topMargin());
}

void QPaintContext::fillRectangle(int x0, int y0, int x1, int y1) {
	if (x1 < x0) {
		int tmp = x1;
		x1 = x0;
		x0 = tmp;
	}
	if (y1 < y0) {
		int tmp = y1;
		y1 = y0;
		y0 = tmp;
	}
	myPainter->fillRect(x0 + leftMargin(), y0 + topMargin(),
			    x1 - x0 + 1, y1 - y0 + 1,
			    myPainter->brush());
}

void QPaintContext::drawFilledCircle(int x, int y, int r) {
	x += leftMargin();
	y += topMargin();
	myPainter->drawEllipse(x - r, y - r, 2 * r + 1, 2 * r + 1);
}

void QPaintContext::clear(ZLColor color) {
	if (myPixmap != NULL) {
		myPixmap->fill(QColor(color.Red, color.Green, color.Blue));
	}
}

int QPaintContext::width() const {
	if (myPixmap == NULL) {
		return 0;
	}
	return myPixmap->width() - leftMargin() - rightMargin();
}

int QPaintContext::height() const {
	if (myPixmap == NULL) {
		return 0;
	}
	return myPixmap->height() - bottomMargin() - topMargin();
}
