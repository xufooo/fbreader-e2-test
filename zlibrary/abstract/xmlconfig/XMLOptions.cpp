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

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

#include "XMLOptions.h"
#include "XMLConfig.h"

XMLOptions::XMLOptions() {
	myConfig = new XMLConfig();
}

XMLOptions::~XMLOptions() {
	delete myConfig;
}

void XMLOptions::setGroup(const std::string &name){
	myGroupName = name;
}

void XMLOptions::clearGroup() {
	myConfig->removeGroup(myGroupName);
}

void XMLOptions::unsetValue(const std::string &name) {
	myConfig->unsetValue(myGroupName, name);
}

bool XMLOptions::booleanValue(const std::string &name, bool defaultValue) {
	return stringValue(name, defaultValue ? "true" : "false") == "true";
}

void XMLOptions::setValue(const std::string &name, bool value, const std::string &category) {
	setValue(name, std::string(value ? "true" : "false"), category);
}

long XMLOptions::integerValue(const std::string &name, long defaultValue) {
	std::string value = stringValue(name, std::string());
	return (!value.empty()) ? atoi(value.c_str()) : defaultValue;
}

void XMLOptions::setValue(const std::string &name, long value, const std::string &category) {
	char buf[100];
	sprintf(buf, "%ld", value);
	setValue(name, std::string(buf), category);
}

double XMLOptions::doubleValue(const std::string &name, double defaultValue) {
	std::string value = stringValue(name, std::string());
	setlocale(LC_NUMERIC, "C");
	return (!value.empty()) ? atof(value.c_str()) : defaultValue;
}

void XMLOptions::setValue(const std::string &name, double value, const std::string &category) {
	char buf[100];
	setlocale(LC_NUMERIC, "C");
	sprintf(buf, "%f", value);
	setValue(name, std::string(buf), category);
}

std::string XMLOptions::stringValue(const std::string &name, const std::string &defaultValue) {
	return myConfig->getValue(myGroupName, name, defaultValue);
}

void XMLOptions::setValue(const std::string &name, const std::string &value, const std::string &category) {
	myConfig->setValue(myGroupName, name, value, category);
}

void XMLOptions::startAutoSave(int seconds) {
	myConfig->startAutoSave(seconds);
}
