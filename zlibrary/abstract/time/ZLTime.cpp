/*
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

#include "ZLTime.h"

ZLTimeManager *ZLTimeManager::ourInstance = 0;

ZLTime::ZLTime() {
	*this = ZLTimeManager::instance().currentTime();
}

ZLTime::ZLTime(long seconds, long milliseconds) : mySeconds(seconds), myMilliseconds(milliseconds) {
}

ZLTime::~ZLTime() {
}

long ZLTime::millisecondsTo(const ZLTime &time) const {
	return 1000 * (time.mySeconds - mySeconds) + time.myMilliseconds - myMilliseconds;
}

long ZLTime::millisecondsFrom(const ZLTime &time) const {
	return - millisecondsTo(time);
}

ZLTimeManager &ZLTimeManager::instance() {
	return *ourInstance;
}

void ZLTimeManager::deleteInstance() {
	delete ourInstance;
}

ZLTimeManager::ZLTimeManager() {
}

ZLTimeManager::~ZLTimeManager() {
}
