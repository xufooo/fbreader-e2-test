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

#include <cctype>
#include <algorithm>

#include <abstract/ZLInputStream.h>

#include "TextFormatDetector.h"

TextFormatDetector::TextFormatDetector() {
}

TextFormatDetector::~TextFormatDetector() {
}

bool TextFormatDetector::isHtml(ZLInputStream &stream) const {
	if (!stream.open()) {
		return false;
	}

	const size_t bufferSize = 1024;
	char *buffer = new char[bufferSize];
	char sixBytes[7]; 
	memset(sixBytes, 0, 7);
	int valuableBytesCounter = 0;
	bool skipFlag = true;
	while (valuableBytesCounter < 6) {
		size_t size = stream.read(buffer, bufferSize);
		if (size == 0) {
			break;
		}
		size_t index;
		for (index = 0; skipFlag && (index < size); ++index) {
			if (!isspace(buffer[index])) {
				skipFlag = false;
				break;
			}
		}
		if (!skipFlag && (index < size)) {
			int bytes = std::min(6 - valuableBytesCounter, (int)(size - index));
			memcpy(sixBytes, buffer + index, bytes);
			valuableBytesCounter += bytes;
		}
	}
	stream.close();
	delete[] buffer;
	return strcasecmp(sixBytes, "<html>") == 0;
}

bool TextFormatDetector::isPPL(ZLInputStream &stream) const {
	if (!stream.open()) {
		return false;
	}

	char buffer[5]; 
	bool result =
	  (stream.read(buffer, 5) == 5) && (strncmp(buffer, "PPL\r\n", 5) == 0);
	stream.close();
	return result;
}
