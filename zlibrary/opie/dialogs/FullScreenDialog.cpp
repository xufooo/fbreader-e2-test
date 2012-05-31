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

#include "FullScreenDialog.h"

#include <qapplication.h>

FullScreenDialog::FullScreenDialog(const char *caption) : QDialog(qApp->mainWidget(), NULL, true) {
	setCaption(caption);
	myInLoop = false;
}

FullScreenDialog::~FullScreenDialog() {
}

int FullScreenDialog::exec() {
	setResult(Rejected);
	showMaximized();
	myInLoop = true;
	qApp->enter_loop();
	return result();
}

void FullScreenDialog::accept() {
	if (myInLoop) {
		qApp->exit_loop();
	}
	QDialog::accept();
}

void FullScreenDialog::reject() {
	if (myInLoop) {
		qApp->exit_loop();
	}
	QDialog::reject();
}
