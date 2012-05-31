/*
 * Copyright (C) 2004-2006 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 *
 * Port for the Motorola A780/E680i is 
 * Copyright (C) 2006 Ketut P. Kumajaya <kumajaya@bluebottle.com>
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

#include <stdio.h>
#include "FullScreenDialog.h"

#ifdef BETTER_TOOLBAR
#include "../dropin/qwallpaper.h"
#endif

#include <qapplication.h>
#include <ZSoftKey.h>

FullScreenDialog::FullScreenDialog(const char *caption) :
    ZMainWidget(caption, true, qApp->mainWidget(), NULL, WType_Modal | WType_TopLevel)
{
	myInLoop = false;

	ZSoftKey *softKey = new ZSoftKey(NULL, this, this);
	softKey->setText(ZSoftKey::LEFT, "Accept", (ZSoftKey::TEXT_PRIORITY)0);
	softKey->setText(ZSoftKey::RIGHT, "Reject", (ZSoftKey::TEXT_PRIORITY)0);
	softKey->setClickedSlot(ZSoftKey::RIGHT, this, SLOT(reject()));
	softKey->setClickedSlot(ZSoftKey::LEFT, this, SLOT(accept()));
	setCSTWidget(softKey);
}

FullScreenDialog::~FullScreenDialog() {
}

#include <stdio.h>

int FullScreenDialog::exec() {
	setResult(0);
	show();
	myInLoop = TRUE;
	qApp->enter_loop();
	return result();
}

void FullScreenDialog::done( int r )
{
	hide();
	if (myInLoop) {
		qApp->exit_loop();
	}
	setResult(r);
	if ( qApp->mainWidget() == this )
		qApp->quit();
}

void FullScreenDialog::accept() {
	done(Accepted);
}

void FullScreenDialog::reject() {
	done(Rejected);
}
