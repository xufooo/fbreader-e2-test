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

#include <algorithm>

#include <abstract/ZLStringUtil.h>

#include "BookCollection.h"

#include "../FBOptions.h"

const std::string GROUP = "LastOpenedBooks";
const std::string BOOK = "Book";

LastOpenedBooks::LastOpenedBooks() :
  MaxListSizeOption(FBOptions::BOOKS_CATEGORY, GROUP, "MaxSize", 1, 100, 10) {

  const int size = MaxListSizeOption.value();
  for (int i = 0; i < size; ++i) {
    std::string num = BOOK;
    ZLStringUtil::appendNumber(num, i);
    std::string name = ZLStringOption(FBOptions::BOOKS_CATEGORY, GROUP, num, "").value();
    if (!name.empty()) {
      BookDescriptionPtr description = BookDescription::create(name);
      if (!description.isNull()) {
        myBooks.push_back(description);
      }
    }
  }
}

LastOpenedBooks::~LastOpenedBooks() {
  const int size = std::min(MaxListSizeOption.value(), (long)myBooks.size());
  for (int i = 0; i < size; ++i) {
    std::string num = BOOK;
    ZLStringUtil::appendNumber(num, i);
    ZLStringOption(FBOptions::BOOKS_CATEGORY, GROUP, num, "").setValue(myBooks[i]->fileName());
  }
}

void LastOpenedBooks::addBook(const std::string &fileName) {
  for (Books::iterator it = myBooks.begin(); it != myBooks.end(); ++it) {
    if ((*it)->fileName() == fileName) {
      myBooks.erase(it);
      break;
    }
  }
  BookDescriptionPtr description = BookDescription::create(fileName);
  if (!description.isNull()) {
    myBooks.insert(myBooks.begin(), description);
  }
}
