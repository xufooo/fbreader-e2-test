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

#include <qapplication.h>
#include <qvbox.h>
#include <qpushbutton.h>
#include <qlabel.h>

#include "QCommonDialog.h"
#include "QOptionsDialog.h"
#include "QDialogManager.h"

#ifdef BETTER_TOOLBAR
#include "../dropin/qwallpaper.h"
#endif

#include <ZGlobal.h>
#include <ZPressButton.h>
#include <iostream>/*ooo added*/

QCommonDialog::QCommonDialog(const std::string &title) :
    ZBaseDialog(qApp->mainWidget(), 0, 1, 0) {
		std::cout<<"QCommonDialog::QCommonDialog\n";
	QVBoxLayout *layout = new QVBoxLayout(this);
	QWidget *widget = new QVBox(this);
	layout->add(widget);

	QFrame *titleFrame = new QFrame(widget);
	titleFrame->setFixedHeight(25);
	QHBoxLayout *titleHBox = new QHBoxLayout(titleFrame);
	QLabel *titleLabel = new QLabel((" " + title).c_str(), titleFrame);
	titleHBox->add(titleLabel);
	
	myTab = new QOptionsDialogTab(widget);

	myButtonGroup = new QButtonGroup(this);
//	myButtonGroup->setFrameStyle(QFrame::NoFrame);
	myButtonGroup->setFrameStyle(QFrame::Box);
	layout->add(myButtonGroup);
	myButtonLayout = new QGridLayout(myButtonGroup, 1, 0, 0, 0);

#if 00000000
	UTIL_PushButton *button = new UTIL_PushButton(myButtonGroup, 0, -1, -1);
	button->resize(ZGlobal::getDlgB2_2R().size());
	button->setText("Close");
	myButtonLayout->addWidget(button, 0, 1);
	connect(button, SIGNAL(clicked()), this, SLOT(reject()));
#else
	ZPressButton * button = new ZPressButton(myButtonGroup, "ZPressButton", (ZSkinService::WidgetClsID)4);
//	button->resize(ZGlobal::getDlgB2_2R().size());
	button->setText("Close");
	myButtonLayout->addWidget(button, 0, 1);
	connect(button, SIGNAL(clicked()), this, SLOT(reject()));
#endif
}

QCommonDialog::~QCommonDialog() {
}

void QCommonDialog::addButton(const std::string &text)
{
    ZPressButton *button = new ZPressButton(myButtonGroup, "ZPressButton", (ZSkinService::WidgetClsID)4 /*0, -1, -1*/);
    button->resize(ZGlobal::getDlgB2_1R().size());
    button->setText(QString(text.c_str()).replace(QRegExp("[\\n\\r?/<>&\\\\:\"*]"), ""));
    myButtonLayout->addWidget(button, 0, 0);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
}

bool QCommonDialog::run() {
	std::cout<<"run??\n";
	((QOptionsDialogTab*)myTab)->close();
	setGeometry(0,200,240,320-200);//ooo fixed
	bool code = exec();
	return code;
}

void QCommonDialog::accept() {
	ZBaseDialog::accept();
}

void QCommonDialog::reject() {
	ZBaseDialog::reject();
}
