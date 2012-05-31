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

#include <abstract/ZLUnicodeUtil.h>

#include "Hyphenator.h"

#include "../textview/Word.h"

Hyphenator *Hyphenator::ourInstance = 0;

void Hyphenator::deleteInstance() {
	if (ourInstance != 0) {
		ourInstance->unload();
		delete ourInstance;
		ourInstance = 0;
	}
}

HyphenationInfo Hyphenator::info(const Word &word) const {
	ZLUnicodeUtil::Ucs2String ucs2Vector;
	ZLUnicodeUtil::utf8ToUcs2(ucs2Vector, word.Data, word.Size, word.Length);

	static std::vector<unsigned short> pattern;
	pattern.clear();
	pattern.reserve(word.Length + 2);

	static std::vector<unsigned char> isLetter;
	isLetter.clear();
	isLetter.reserve(word.Length);

	pattern.push_back(' ');
	for (unsigned int i = 0; i < ucs2Vector.size(); ++i) {
		unsigned short symbol = ucs2Vector[i];
		bool letter = ZLUnicodeUtil::isLetter(symbol);
		isLetter.push_back(letter);
		pattern.push_back(letter ? ZLUnicodeUtil::toLower(symbol) : ' ');
	}
	pattern.push_back(' ');

	HyphenationInfo info(word.Length + 2);
	hyphenate(pattern, info.myMask, word.Length + 2);

	for (int i = 0; i < word.Length + 1; ++i) {
		if ((i < 2) || (i > word.Length - 2)) {
			info.myMask[i] = false;
		} else if (ucs2Vector[i - 1] == '-') {
			info.myMask[i] = (i >= 3) &&
				isLetter[i - 3] &&
				isLetter[i - 2] &&
				isLetter[i] &&
				isLetter[i + 1];
		} else {
			info.myMask[i] = info.myMask[i] &&
				isLetter[i - 2] &&
				isLetter[i - 1] &&
				isLetter[i] &&
				isLetter[i + 1];
		}
	}

	return info;
}
