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

#include <algorithm>

#include <qapplication.h>
#include "../dropin/qtabwidget.h"
#include "../dropin/qtabbar.h"
#include <qhbox.h>
#include <qvbox.h>

#include <qlayout.h>
#include <qlabel.h>
#include <qscrollview.h>
#include <qregexp.h>

#include <abstract/ZLOptionEntry.h>
#include <abstract/ZLDeviceInfo.h>

#include "QOptionsDialog.h"
#include "QOptionView.h"
#include "QDialogManager.h"

#include <ZSoftKey.h>
#include <ZOptionsMenu.h>
#include <ZScrollView.h>
#include <ZScrollPanel.h>
#include <ZLabel.h>

class MyTabBar : public QTabBar
{
public:
	MyTabBar(QWidget *parent = 0, const char *name = 0) : QTabBar(parent, name)
	{
	}

	virtual QSize sizeHint() const
	{
		return (QSize(0,0));
	}
};

class MyTabWidget : public QTabWidget
{
public:
	MyTabWidget(QWidget* parent) : QTabWidget(parent)
	{
		setTabBar(new MyTabBar(parent, "MyTabBar"));
		((MyTabBar*)tabBar())->hide();
	}
};

QOptionsDialog::QOptionsDialog(const std::string &id, const std::string &caption) :
    FullScreenDialog(caption.c_str()),
    ZLOptionsDialog(id),
    tabno(0)
{
	cap = caption;
	myTabWidget = new MyTabWidget(this);
	setContentWidget(myTabWidget);


	ZSoftKey *softKey = (ZSoftKey *)getCSTWidget(true);

	QRect rect;
	menu = new ZOptionsMenu(rect, softKey, NULL, 0, (ZSkinService::WidgetClsID)4);
	softKey->setOptMenu(ZSoftKey::LEFT, menu);
	softKey->setText(ZSoftKey::LEFT, "Menu", (ZSoftKey::TEXT_PRIORITY)0);

	QRect rect2;
	ZOptionsMenu * menu2 = new ZOptionsMenu(rect2, softKey, NULL, 0, (ZSkinService::WidgetClsID)4);
	menu2->insertItem(QString("Accept"), NULL, NULL, true, 0, 0);
	menu2->insertItem(QString("Cancel"), NULL, NULL, true, 1, 1 );
	softKey->setOptMenu(ZSoftKey::RIGHT, menu2);
	softKey->setText(ZSoftKey::RIGHT, "Done", (ZSoftKey::TEXT_PRIORITY)0);

	connect(menu, SIGNAL(activated(int)), this, SLOT(selectTab(int)));

	menu2->connectItem(0, this, SLOT(accept()));
	menu2->connectItem(1, this, SLOT(reject()));
}


ZLDialogContent &QOptionsDialog::createTab(const std::string &name) {
//    QScrollView *sv = new QScrollView(myTabWidget, "QScrollView", 0);
    ZScrollView *sv = new ZScrollView(myTabWidget, NULL, 0/*, (ZSkinService::WidgetClsID)4*/);
	sv->setResizePolicy(QScrollView::AutoOneFit );
	sv->setFrameStyle( QFrame::NoFrame );
#if 0
	QSizePolicy pol = sv->sizePolicy();
	pol.setHorData(QSizePolicy::Fixed);
	sv->setSizePolicy(pol);
	QRect rect = sv->contentsRect();
	rect.setWidth(240);
	sv->setFrameRect(rect);
	sv->setLineWidth(240);
#endif
	sv->setVScrollBarMode(QScrollView::AlwaysOff);
	sv->setHScrollBarMode(QScrollView::AlwaysOff);

	QOptionsDialogTab *tab = new QOptionsDialogTab(sv->viewport());
	sv->addChild(tab, 0, 0);
	myTabWidget->insertTab(sv, name.c_str());
	menu->insertItem(QString(name.c_str()), NULL, NULL, true, tabno, tabno);
	myTabs.append(tab);
	myTabNames.push_back(name);
	tabno++;
	return *tab;
}

const std::string &QOptionsDialog::selectedTabName() const {
	return myTabNames[myTabWidget->currentPageIndex()];
}

void QOptionsDialog::selectTab(const std::string &name) {
	std::vector<std::string>::const_iterator it = std::find(myTabNames.begin(), myTabNames.end(), name);
	if (it != myTabNames.end()) {
		myTabWidget->setCurrentPage(it - myTabNames.begin());
	} else {
		myTabWidget->setCurrentPage(0);
	}
	QLabel *l = (QLabel*)(QFrame*)getTitleBarWidget();
	QString s = myTabWidget->tabLabel(myTabWidget->currentPage());
	l->setText(QString((cap + " - ").c_str() + s).replace(QRegExp("[\\n\\r?/<>\\\\:\"*]"), ""));
}

void QOptionsDialog::selectTab(int id) {
    myTabWidget->setCurrentPage(id);
    QLabel *l = (QLabel*)(QFrame*)getTitleBarWidget();
    QString s = myTabWidget->tabLabel(myTabWidget->currentPage());
    l->setText(QString((cap + " - ").c_str() + s).replace(QRegExp("[\\n\\r?/<>\\\\:\"*]"), ""));
}

bool QOptionsDialog::run() {
	for (QOptionsDialogTab *tab = myTabs.first(); tab != 0; tab = myTabs.next()) {
		tab->close();
	}
	bool code = exec();
	return code;
}

void QOptionsDialog::accept() {
	for (QOptionsDialogTab *tab = myTabs.first(); tab != 0; tab = myTabs.next()) {
		tab->accept();
	}
	FullScreenDialog::accept();
}

void QOptionsDialogTab::accept() {
	for (QOptionView *view = myViews.first(); view != 0; view = myViews.next()) {
		view->onAccept();
	}
}

void QOptionsDialog::resizeEvent(QResizeEvent *) {
  myTabWidget->resize(size());
}

void QOptionsDialog::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Key_Enter) {
		accept();
	} else {
		FullScreenDialog::keyPressEvent(event);
	}
}

void QOptionsDialogTab::close() {
    myLayout->setRowStretch(myRowCounter, 10);
}

QOptionsDialogTab::QOptionsDialogTab(QWidget *parent) : QWidget(parent) {
	int space = 10;
	switch (ZLDeviceInfo::screenSize()) {
		case ZLDeviceInfo::SIZE_640x480:
			space = 10;
			break;
		default:
			space = 3;
			break;
	}
	myLayout = new QGridLayout(this, -1, 12, space, space);
	myRowCounter = 0;

#if 0
	QSizePolicy pol = this->sizePolicy();
	pol.setHorData(QSizePolicy::Fixed);
	this->setSizePolicy(pol);
	QRect rect = QRect(0, 0, 240, 320);
	myLayout->setGeometry(rect);
	myLayout->setColStretch(12, 12);
#endif
}

QOptionsDialogTab::~QOptionsDialogTab() {
	for (QOptionView *view = myViews.first(); view != 0; view = myViews.next()) {
		delete view;
	}
}

void QOptionsDialogTab::addOption(ZLOptionEntry *option) {
	createViewByEntry(option, 0, 11);
	++myRowCounter;
}

void QOptionsDialogTab::addOptions(ZLOptionEntry *option0, ZLOptionEntry *option1) {
	createViewByEntry(option0, 0, 5);
	createViewByEntry(option1, 6, 11);
	++myRowCounter;
}

void QOptionsDialogTab::addItem(QWidget *widget, int row, int fromColumn, int toColumn,
    int align) {
    int start = fromColumn;
    int end = toColumn;
    myLayout->addMultiCellWidget(widget, row, row, start, end, align);
    while (start < end) {
	myLayout->setColStretch(start, 0);
	start++;
    }
}

void QOptionsDialogTab::createViewByEntry(ZLOptionEntry *option, int fromColumn, int toColumn) {
	if (option == 0) {
		return;
	}

	QOptionView *view = 0;
	switch (option->kind()) {
		case BOOLEAN:
			view = new BooleanOptionView((ZLBooleanOptionEntry*)option, this, myRowCounter, fromColumn, toColumn);
			break;
		case STRING:
			view = new StringOptionView((ZLStringOptionEntry*)option, this, myRowCounter, fromColumn, toColumn);
			break;
		case CHOICE:
			view = new ChoiceOptionView((ZLChoiceOptionEntry*)option, this, myRowCounter, fromColumn, toColumn);
			break;
		case SPIN:
			view = new SpinOptionView((ZLSpinOptionEntry*)option, this, myRowCounter, fromColumn, toColumn);
			break;
		case COMBO:
			view = new ComboOptionView((ZLComboOptionEntry*)option, this, myRowCounter, fromColumn, toColumn);
			break;
		case COLOR:
			view = new ColorOptionView((ZLColorOptionEntry*)option, this, myRowCounter, fromColumn, toColumn);
			break;
		case KEY:
			view = new KeyOptionView((ZLKeyOptionEntry*)option, this, myRowCounter, fromColumn, toColumn);
			break;
		case UNKNOWN:
			view = (QOptionView*)((ZLUserDefinedOptionEntry*)option)->createView();
			view->setPosition(this, myRowCounter, fromColumn, toColumn);
			break;
	}

	if (view != 0) {
		view->setVisible(option->isVisible());
		myViews.append(view);
	}
}
