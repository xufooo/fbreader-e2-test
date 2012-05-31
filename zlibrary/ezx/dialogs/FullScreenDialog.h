/*
 * Copyright (C) 2004-2006 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 *
 * Port for the Motorola A780/E680i is 
 * Copyright (C) 2006 Ketut P. Kumajaya <kumajaya@bluebottle.com>
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

#ifndef __FULLSCREENDIALOG_H__
#define __FULLSCREENDIALOG_H__

#include <ZKbMainWidget.h>

class FullScreenDialog : public ZMainWidget {
	Q_OBJECT

protected:
	FullScreenDialog(const char *caption); 
	virtual ~FullScreenDialog(); 

	enum DialogCode { Rejected, Accepted };
	void setResult(int r) { rescode = r; }

public:
	int exec();
	int result() const { return rescode; }

protected slots:
	virtual void done(int);
	virtual void accept();
	virtual void reject();

private:
	bool myInLoop;
	int rescode;
};

#endif /* __FULLSCREENDIALOG_H__ */
