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

#include <abstract/ZLStringUtil.h>

#include "Base64EncodedImage.h"

void Base64EncodedImage::addData(const std::vector<std::string> &text) {
	ZLStringUtil::append(myEncodedData, text);
}

void Base64EncodedImage::decode() const {
	if ((myEncodedData.empty()) || (!myData.isNull())) {
		return;
	}

	size_t dataLength = myEncodedData.length();

	myData = new std::string();
	myData->reserve(dataLength / 4 * 3);
	for (size_t pos = 0, dataPos = 0; pos < dataLength; dataPos += 3) {
		unsigned int sum = 0;
		for (int i = 0; (i < 4) && (pos < dataLength); ++pos) {
			char encodedByte = myEncodedData[pos];
			unsigned int number = 0;
			if (('A' <= encodedByte) && (encodedByte <= 'Z')) {
				number = encodedByte - 'A';
			} else if (('a' <= encodedByte) && (encodedByte <= 'z')) {
				number = encodedByte - 'a' + 26;
			} else if (('0' <= encodedByte) && (encodedByte <= '9')) {
				number = encodedByte - '0' + 52;
			} else if (encodedByte == '+') {
				number = 62;
			} else if (encodedByte == '/') {
				number = 63;
			} else if (encodedByte == '=') {
				number = 64;
			} else {
				continue;
			}
			sum += number << (6 * (3 - i));
			++i;
		}
		char triple[3];
		for (int j = 2; j >= 0; --j) {
			triple[j] = sum & 0xff; 
			sum >>= 8;
		}
		myData->append(triple, 3);
	}
	myEncodedData.erase();
}

const shared_ptr<std::string> Base64EncodedImage::stringData() const {
	decode();
	return myData;
}
