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

#include <abstract/ZLFile.h>
#include <abstract/ZLInputStream.h>
#include <abstract/ZLZDecompressor.h>
#include <abstract/ZLStringUtil.h>

#include "PluckerImages.h"
#include "DocDecompressor.h"

const shared_ptr<std::string> ZCompressedFileImage::stringData() const {
	shared_ptr<ZLInputStream> stream = ZLFile(myPath).inputStream();

	shared_ptr<std::string> imageData = new std::string();

	if (!stream.isNull() && stream->open()) {
		stream->seek(myOffset);
		ZLZDecompressor decompressor(myCompressedSize);

		static const size_t charBufferSize = 2048;
		char *charBuffer = new char[charBufferSize];
		std::vector<std::string> buffer;

		size_t s;
		do {
			s = decompressor.decompress(*stream, charBuffer, charBufferSize);
			if (s != 0) {
				buffer.push_back(std::string());
				buffer.back().append(charBuffer, s);
			}
		} while (s == charBufferSize);
		ZLStringUtil::append(*imageData, buffer);

		delete charBuffer;
	}

	return imageData;
}

const shared_ptr<std::string> DocCompressedFileImage::stringData() const {
	shared_ptr<ZLInputStream> stream = ZLFile(myPath).inputStream();

	shared_ptr<std::string> imageData = new std::string();

	if (!stream.isNull() && stream->open()) {
		stream->seek(myOffset);
		char *buffer = new char[65535];
		size_t uncompressedSize = DocDecompressor().decompress(*stream, buffer, myCompressedSize, 65535);
		imageData->append(buffer, uncompressedSize);
		delete[] buffer;
	}

	return imageData;
}

const ZLImage *PluckerMultiImage::subImage(unsigned int row, unsigned int column) const {
	unsigned int index = row * myColumns + column;
	if (index >= myIds.size()) {
		return 0;
	}
	ImageMap::const_iterator entry = myImageMap.find(myIds[index]);
	return (entry != myImageMap.end()) ? entry->second : 0;
}
