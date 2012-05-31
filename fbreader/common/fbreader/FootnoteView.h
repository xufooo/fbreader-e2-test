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

#ifndef __FOOTNOTEVIEW_H__
#define __FOOTNOTEVIEW_H__

#include "FBView.h"

class FootnoteView : public FBView {

public:
	FootnoteView(FBReader &reader, ZLPaintContext &context);
	const std::string &caption() const;
	void setCaption(const std::string &caption);

private:
	std::string myCaption;
};

inline FootnoteView::FootnoteView(FBReader &reader, ZLPaintContext &context) : FBView(reader, context) {}
inline const std::string &FootnoteView::caption() const { return myCaption; }
inline void FootnoteView::setCaption(const std::string &caption) { myCaption = caption; }

#endif /* __FOOTNOTEVIEW_H__ */
