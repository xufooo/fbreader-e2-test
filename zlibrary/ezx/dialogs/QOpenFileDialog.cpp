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
#include <qlineedit.h>
#include <qheader.h>

#include <ZLineEdit.h>

#include "QOpenFileDialog.h"

QOpenFileDialogItem::QOpenFileDialogItem(QListView *listView, QListViewItem *previous, const ZLTreeNodePtr node) :
//    QListViewItem(listView, previous, QString::fromLocal8Bit(node->name().c_str())), myNode(node) {
    QListViewItem(listView, previous, QString::fromUtf8(node->name().c_str())), myNode(node) {
}

QOpenFileDialog::QOpenFileDialog(const char *caption, const ZLTreeHandler &handler) :
    FullScreenDialog(caption),
    ZLOpenFileDialog(handler) {
	myMainBox = new QVBox(this);
	setContentWidget(myMainBox);

#if 0
	myStateLine = new ZLineEdit(myMainBox, "ZLineEdit", ZSkinService::NONE);
	myStateLine->setFrame(false);
#endif
	QFrame *f = new QFrame(myMainBox);
	f->setFrameStyle( QFrame::HLine | QFrame::Plain );
#if 0
	myStateLine->setEnabled(false);
#endif
	myListView = new QListView(myMainBox);
	myListView->setFrameStyle(QFrame::NoFrame);
	myListView->addColumn("");
	myListView->setColumnWidth(0, QApplication::desktop()->width() - QApplication::style().scrollBarExtent().width());
	myListView->header()->hide();

	connect(myListView, SIGNAL(clicked(QListViewItem*)), this, SLOT(accept()));
	connect(myListView, SIGNAL(returnPressed(QListViewItem*)), this, SLOT(accept()));

	update("");
}

QOpenFileDialog::~QOpenFileDialog() {
	for (std::map<std::string,QPixmap*>::const_iterator it = myPixmaps.begin(); it != myPixmaps.end(); ++it) {
		delete it->second;
	}
}

QPixmap &QOpenFileDialog::getPixmap(const ZLTreeNodePtr node) {
	const std::string &pixmapName = node->pixmapName();
	std::map<std::string,QPixmap*>::const_iterator it = myPixmaps.find(pixmapName);
	if (it == myPixmaps.end()) {
		QPixmap *pixmap = new QPixmap(QString((std::string(getenv("FBDIR")) + "/pics/" + pixmapName + ".png").c_str()));
//		QPixmap *pixmap = new QPixmap(QString((std::string(".") + "/pics/" + pixmapName + ".png").c_str()));//ooo fixed
		myPixmaps[pixmapName] = pixmap;
		return *pixmap;
	} else {
		return *it->second;
	}
}

void QOpenFileDialog::keyPressEvent(QKeyEvent *event) {
	if ((event != 0) && (event->key() == Key_Escape)) {
		reject();
	}
	printf("KEY: %x\n", event ? event->key() : 0); fflush(stdout);
	if ((event != 0) && (event->key() == 0x1031)) {
	    reject();
	}
}

void QOpenFileDialog::resizeEvent(QResizeEvent *event) {
	if (event != 0) {
		myMainBox->resize(event->size());
	}
}

void QOpenFileDialog::update(const std::string &selectedNodeName) {
#if 0
	myStateLine->setText(QString::fromLocal8Bit(state()->name().c_str()));
#endif

	myListView->clear();

	QListViewItem *item = 0;
	QListViewItem *selectedItem = 0;

	const std::vector<ZLTreeNodePtr> &subnodes = state()->subnodes();
	for (std::vector<ZLTreeNodePtr>::const_iterator it = subnodes.begin(); it != subnodes.end(); ++it) {
	 	item = new QOpenFileDialogItem(myListView, item, *it);
		item->setPixmap(0, getPixmap(*it));
		if ((*it)->name() == selectedNodeName) {
			selectedItem = item;
		}
	}

	if (selectedItem == 0) {
		selectedItem = myListView->firstChild();
	}
	myListView->setSelected(selectedItem, true);
	if (selectedItem != myListView->firstChild()) {
		myListView->ensureItemVisible(selectedItem);
	}
}

void QOpenFileDialog::exitDialog() {
	FullScreenDialog::accept();
}

void QOpenFileDialog::accept() {
	runNode(((QOpenFileDialogItem*)myListView->currentItem())->node());
}
