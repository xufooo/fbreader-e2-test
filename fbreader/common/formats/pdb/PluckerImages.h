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

#ifndef __PLUCKERIMAGES_H__
#define __PLUCKERIMAGES_H__

#include <string>

#include <abstract/ZLImage.h>
#include "../../bookmodel/BookModel.h"

class ZCompressedFileImage : public ZLSingleImage {

public:
	ZCompressedFileImage(const std::string &mimeType, const std::string &path, size_t offset, size_t size);
	~ZCompressedFileImage();
	const shared_ptr<std::string> stringData() const;

private:
	std::string myPath;
	size_t myOffset;
	size_t myCompressedSize;
};

class DocCompressedFileImage : public ZLSingleImage {

public:
	DocCompressedFileImage(const std::string &mimeType, const std::string &path, size_t offset, size_t compressedSize);
	~DocCompressedFileImage();
	const shared_ptr<std::string> stringData() const;

private:
	std::string myPath;
	size_t myOffset;
	size_t myCompressedSize;
};

class PluckerMultiImage : public ZLMultiImage {

public:
	PluckerMultiImage(unsigned int rows, unsigned int columns, const ImageMap &imageMap);
	~PluckerMultiImage();

	void addId(const std::string &id);

	unsigned int rows() const;
	unsigned int columns() const;
	const ZLImage *subImage(unsigned int row, unsigned int column) const;

private:
	unsigned int myRows, myColumns;
	const ImageMap &myImageMap;
	std::vector<std::string> myIds;
};

inline ZCompressedFileImage::ZCompressedFileImage(const std::string &mimeType, const std::string &path, size_t offset, size_t compressedSize) : ZLSingleImage(mimeType), myPath(path), myOffset(offset), myCompressedSize(compressedSize) {}
inline ZCompressedFileImage::~ZCompressedFileImage() {}

inline DocCompressedFileImage::DocCompressedFileImage(const std::string &mimeType, const std::string &path, size_t offset, size_t compressedSize) : ZLSingleImage(mimeType), myPath(path), myOffset(offset), myCompressedSize(compressedSize) {}
inline DocCompressedFileImage::~DocCompressedFileImage() {}

inline PluckerMultiImage::PluckerMultiImage(unsigned int rows, unsigned int columns, const ImageMap &imageMap) : myRows(rows), myColumns(columns), myImageMap(imageMap) {}
inline PluckerMultiImage::~PluckerMultiImage() {}
inline void PluckerMultiImage::addId(const std::string &id) { myIds.push_back(id); }
inline unsigned int PluckerMultiImage::rows() const { return myRows; }
inline unsigned int PluckerMultiImage::columns() const { return myColumns; }

#endif /* __PLUCKERIMAGES_H__ */
