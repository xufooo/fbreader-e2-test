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

#ifndef __ZLFSMANAGER_H__
#define __ZLFSMANAGER_H__

#include <string>

#include <abstract/ZLFileInfo.h>

class ZLFSDir;
class ZLInputStream;
class ZLOutputStream;

class ZLFSManager {

public:
	static void deleteInstance();
	static ZLFSManager &instance();

protected:
	static ZLFSManager *ourInstance;
	
protected:
	ZLFSManager();
	virtual ~ZLFSManager();
	
public:
	virtual void normalize(std::string &path) const;

protected:
	virtual ZLInputStream *createPlainInputStream(const std::string &path) const = 0;
	virtual ZLOutputStream *createOutputStream(const std::string &path) const = 0;
	virtual ZLFSDir *createPlainDirectory(const std::string &path) const = 0;
	virtual ZLFSDir *createNewDirectory(const std::string &path) const = 0;
	virtual ZLFileInfo fileInfo(const std::string &path) const = 0;
	virtual bool isZipSupported() const = 0;
	virtual bool removeFile(const std::string &path) const = 0;

friend class ZLFile;
};

inline void ZLFSManager::deleteInstance() { delete ourInstance; }
inline ZLFSManager &ZLFSManager::instance() { return *ourInstance; }
inline ZLFSManager::ZLFSManager() {}
inline ZLFSManager::~ZLFSManager() {}
inline void ZLFSManager::normalize(std::string&) const {}

#endif /* __ZLFSMANAGER_H__ */
