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

#include <abstract/ZLXMLReader.h>
#include <abstract/ZLStringUtil.h>

#include "FBReader.h"
#include "../Files.h"

static const std::string BINDINGS_NUMBER = "Number";
static const std::string BINDED_KEY = "Key";
static const std::string BINDED_ACTION = "Action";

class KeyBindingsReader : public ZLXMLReader {

public:
	KeyBindingsReader(std::map<std::string,int> &keymap) : myKeymap(keymap) {}

	void startElementHandler(const char *tag, const char **attributes);

	void readBindings();

private:
	std::map<std::string,int> &myKeymap;
};

void KeyBindingsReader::startElementHandler(const char *tag, const char **attributes) {
	static const std::string BINDING = "binding";

	if (BINDING == tag) {
		const char *key = attributeValue(attributes, "key");
		const char *action = attributeValue(attributes, "action");
		if ((key != 0) && (action != 0)) {
			myKeymap[key] = atoi(action);
		}
	}
}

static const std::string KeymapFile = "keymap.xml";

void KeyBindingsReader::readBindings() {
	readDocument(Files::DefaultFilesPathPrefix() + KeymapFile);
}

FullKeyBindings::FullKeyBindings() :
    UseSeparateBindingsOption(ZLOption::CONFIG_CATEGORY, "KeysOptions", "UseSeparateBindings", false),
    myBindings0("Keys"),
    myBindings90("Keys90"),
    myBindings180("Keys180"),
    myBindings270("Keys270") {
}

KeyBindings &FullKeyBindings::getBindings(ZLViewWidget::Angle angle, bool force) {
	if (!force && !UseSeparateBindingsOption.value()) {
		return myBindings0;
	}
	switch (angle) {
		case ZLViewWidget::DEGREES0:
		default:
			return myBindings0;
		case ZLViewWidget::DEGREES90:
			return myBindings90;
		case ZLViewWidget::DEGREES180:
			return myBindings180;
		case ZLViewWidget::DEGREES270:
			return myBindings270;
	}
}

KeyBindings::KeyBindings(const std::string &optionGroupName) : myOptionGroupName(optionGroupName) {
  loadDefaultBindings();
  loadCustomBindings();
	myChanged = false;
}

void KeyBindings::loadDefaultBindings() {
	std::map<std::string,int> keymap;
	KeyBindingsReader(keymap).readBindings();
	for (std::map<std::string,int>::const_iterator it = keymap.begin(); it != keymap.end(); ++it) {
		bindKey(it->first, it->second);
	}
}

void KeyBindings::loadCustomBindings() {
	int size = ZLIntegerRangeOption(ZLOption::CONFIG_CATEGORY, myOptionGroupName, BINDINGS_NUMBER, 0, 256, 0).value();
	for (int i = 0; i < size; ++i) {
		std::string key = BINDED_KEY;
		ZLStringUtil::appendNumber(key, i);
		std::string keyValue = ZLStringOption(ZLOption::CONFIG_CATEGORY, myOptionGroupName, key, "").value();
		if (!keyValue.empty()) {
			std::string action = BINDED_ACTION;
			ZLStringUtil::appendNumber(action, i);
			int actionValue = ZLIntegerOption(ZLOption::CONFIG_CATEGORY, myOptionGroupName, action, -1).value();
			if (actionValue != -1) {
				bindKey(keyValue, actionValue);
			}
		}
	}
}

void KeyBindings::saveCustomBindings() {
	if (!myChanged) {
		return;
	}
	std::map<std::string,int> keymap;
	KeyBindingsReader(keymap).readBindings();

	ZLOption::clearGroup(myOptionGroupName);
	int counter = 0;
	for (std::map<std::string,int>::const_iterator it = myBindingsMap.begin(); it != myBindingsMap.end(); ++it) {
		std::map<std::string,int>::const_iterator original = keymap.find(it->first);
		int defaultAction = (original == keymap.end()) ? 0 : original->second;
		if (defaultAction != it->second) {
			std::string key = BINDED_KEY;
			ZLStringUtil::appendNumber(key, counter);
			std::string action = BINDED_ACTION;
			ZLStringUtil::appendNumber(action, counter);
			ZLStringOption(ZLOption::CONFIG_CATEGORY, myOptionGroupName, key, "").setValue(it->first);
			ZLIntegerOption(ZLOption::CONFIG_CATEGORY, myOptionGroupName, action, -1).setValue(it->second);
			++counter;
		}
	}
	ZLIntegerRangeOption(ZLOption::CONFIG_CATEGORY, myOptionGroupName, BINDINGS_NUMBER, 0, 256, 0).setValue(counter);
}

KeyBindings::~KeyBindings() {
	saveCustomBindings();
}

void KeyBindings::bindKey(const std::string &key, int code) {
	myBindingsMap[key] = code;
	myChanged = true;
}

int KeyBindings::getBinding(const std::string &key) {
	std::map<std::string,int>::const_iterator it = myBindingsMap.find(key);
	return (it != myBindingsMap.end()) ? it->second : 0;
}
