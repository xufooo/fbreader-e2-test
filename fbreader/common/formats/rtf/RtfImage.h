/*
 * FBReader -- electronic book reader
 * Copyright (C) 2004-2006 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 * Copyright (C) 2006 Vladimir Sorokin <s_v_d_2000@mail.ru>
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

#ifndef __RTFIMAGE_H__
#define __RTFIMAGE_H__

#include <vector>

#include <abstract/ZLImage.h>

class RtfImage : public ZLSingleImage {

public:
	RtfImage(const std::string &mimeType, const std::string &fileName, size_t startOffset, size_t length);
	~RtfImage();
	const shared_ptr<std::string> stringData() const;

private:
	void read() const;

private:
	std::string myFileName;
	size_t myStartOffset;
	size_t myLength;
	mutable shared_ptr<std::string> myData;
};

inline RtfImage::RtfImage(const std::string &mimeType, const std::string &fileName, size_t startOffset, size_t length) : ZLSingleImage(mimeType), myFileName(fileName), myStartOffset(startOffset), myLength(length) {}
inline RtfImage::~RtfImage() {}

#endif /* __RTFIMAGE_H__ */
