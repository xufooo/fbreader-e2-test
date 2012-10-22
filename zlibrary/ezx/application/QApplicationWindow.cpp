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

#include <ZApplication.h>
#include <ZGlobal.h>
#include <ZMainWidget.h>
#include <ZSoftKey.h>
#include <ZOptionsMenu.h>

#include <qpixmap.h>
#include <qmenubar.h>
#include <qlayout.h>
#include <qhbox.h>
#include <qlabel.h>

#include "QApplicationWindow.h"
#include "QtMenuAction.h"
#include "../view/QViewWidget.h"
#include "../dialogs/QDialogManager.h"
#include "../../qt/util/QKeyUtil.h"

#ifdef BETTER_TOOLBAR
#include "../dropin/qwallpaper.h"
#endif

QAboutDialog::QAboutDialog(const char *caption) : FullScreenDialog(caption) {
	QWidget *myWidget = new QWidget(this);
	QFont f(qApp->font());
	f.setPointSize(16);
	myWidget->setFont(f);
	QVBoxLayout *myVBoxLayout = new QVBoxLayout(myWidget, 4);

	QHBoxLayout *myHBoxLayout = new QHBoxLayout; 
	myHBoxLayout->setSpacing( 4 );
	myHBoxLayout->setMargin( 0 );

	QLabel *myLabel = new QLabel(myWidget);
//	myLabel->setPixmap(QPixmap((std::string(getenv("FBDIR")) + "/pics/FBReader.png").c_str()));ooo fixed
	myLabel->setPixmap(QPixmap("./pics/FBReader.png"));
	myLabel->setScaledContents(false);
	myHBoxLayout->addWidget(myLabel);

	myLabel = new QLabel(QString("<qt>FBReader 0.7.4g<br>"
			"<font size=\"-1\">FBReader is an e-book reader</font></qt>"), myWidget);
	myHBoxLayout->addWidget(myLabel, 1);
	myVBoxLayout->addLayout(myHBoxLayout);
	
	myLabel = new QLabel(QString("<qt><font size=\"-1\"><p>Copyright (C) 2004-2006 Nikolay Pultsin<br>"
			"<tt>&lt;geometer@mawhrin.net&gt;</tt><br>"
			"Copyright (C) 2005 Mikhail Sobolev<br>"
			"<tt>&lt;mss@mawhrin.net&gt;</tt></p>"
			"<p>Port to Motorola EZX by Ketut P. Kumajaya<br>"
			"<tt>&lt;kumajaya@bluebottle.com&gt;</tt></p>"
			"<p>Port to Motorola Z6 by Alexey Kuznetsov<br>"
			"<tt>&lt;kuznet@ms2.inr.ac.ru&gt;</tt></p>"
			"<p>Port to Motorola E2 by ooo</p></font></qt>"),
			     myWidget);
	myVBoxLayout->addWidget(myLabel);

	QSpacerItem* spacer = new QSpacerItem(8, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);
	myVBoxLayout->addItem(spacer);

	myLabel = new QLabel("Licensed under the GNU GPL.", myWidget);
	myVBoxLayout->addWidget(myLabel);
	setContentWidget(myWidget);

	ZSoftKey *softKey = (ZSoftKey*)getCSTWidget(true);
	softKey->setText(ZSoftKey::LEFT, "Thanks", (ZSoftKey::TEXT_PRIORITY)0);
	softKey->setText(ZSoftKey::RIGHT, "OK", (ZSoftKey::TEXT_PRIORITY)0);
}

QAboutDialog::~QAboutDialog() {
}

void QAboutDialog::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Key_Enter) {
		reject();
	} else {
		FullScreenDialog::keyPressEvent(event);
	}
}

#if 00000000
class MyMenuBar : public QMenuBar {

public:
	MyMenuBar(QWidget *parent) : QMenuBar(parent) {}

private:
	void keyPressEvent(QKeyEvent *event) {
		if (event->key() == Key_Escape) {
			QMenuBar::keyPressEvent(event);
		}
	}
};
#endif

QApplicationWindow::QApplicationWindow(ZLApplication *a) :
    ZKbMainWidget(ZHeader::FULL_TYPE, NULL, "ZMainWidget", 0),
    ZLApplicationWindow(a) {
	myFullScreen = false;

#if 00000000
	myToolBar = new MyMenuBar(this);
	myMenu = new QPopupMenu(this);
	QFont f(qApp->font());
	f.setPointSize(15);
	myMenu->setFont(f);

	connect(myToolBar, SIGNAL(activated(int)), this, SLOT(doActionSlot(int)));

	setGeometry(ZGlobal::mapFromGlobalR(this, ZGlobal::getHomeR(0)));
#endif
	((ZApplication*)qApp)->showMainWidget(this);
}

QApplicationWindow::~QApplicationWindow() {
}

void QApplicationWindow::setCaption(const std::string &) {
}

bool QApplicationWindow::isFullKeyboardControlSupported() const {
	return true;
}

void QApplicationWindow::grabAllKeys(bool) {
}

void QApplicationWindow::addToolbarItem(ZLApplication::Toolbar::ItemPtr) {
}

void QApplicationWindow::initMenu() {
}

QApplicationWindow::MenuMaskCalculator::MenuMaskCalculator(QApplicationWindow &window) : myWindow(window), myFirstTime(myWindow.myMenuMask.empty()), myShouldBeUpdated(myFirstTime), myCounter(0) {
}

void QApplicationWindow::MenuMaskCalculator::processSubmenuBeforeItems(ZLApplication::Menubar::Submenu&) {
}

void QApplicationWindow::MenuMaskCalculator::processSubmenuAfterItems(ZLApplication::Menubar::Submenu&) {
}

void QApplicationWindow::MenuMaskCalculator::processSepartor(ZLApplication::Menubar::Separator&) {
}

void QApplicationWindow::MenuMaskCalculator::processItem(ZLApplication::Menubar::PlainItem &item) {
	bool visible = myWindow.application().isActionVisible(item.actionId());
	if (myFirstTime) {
		myWindow.myMenuMask.push_back(visible);
	} else {
		if (myWindow.myMenuMask[myCounter] != visible) {
			myWindow.myMenuMask[myCounter] = visible;
			myShouldBeUpdated = true;
		}
		++myCounter;
	}
}

QApplicationWindow::MenuUpdater::MenuUpdater(QApplicationWindow &window) : myWindow(window), myCounter(0) {
	myMenuStack.push(myWindow.myMenu);
}

void QApplicationWindow::MenuUpdater::processSubmenuBeforeItems(ZLApplication::Menubar::Submenu &submenu) {
#if 00000000
	QPopupMenu *qmenu = new QPopupMenu(myMenuStack.top());
	myMenuStack.top()->insertItem(submenu.menuName().c_str(), qmenu);
	myMenuStack.push(qmenu);
#endif
}

void QApplicationWindow::MenuUpdater::processSubmenuAfterItems(ZLApplication::Menubar::Submenu&) {
	myMenuStack.pop();
}

void QApplicationWindow::MenuUpdater::processItem(ZLApplication::Menubar::PlainItem &item) {
#if 00000000
	if (myWindow.myMenuMask[myCounter++]) {
		const int id = item.actionId();
		QtMenuAction *action = myWindow.myMenuMap[id];
		if (action == 0) {
			action = new QtMenuAction(myWindow.application(), item);
			myWindow.myMenuMap[id] = action;
		}
		action->addTo(myMenuStack.top());
		action->setEnabled(myWindow.application().isActionEnabled(id));
	}
#endif
}

void QApplicationWindow::MenuUpdater::processSepartor(ZLApplication::Menubar::Separator&) {
#if 00000000
	myMenuStack.top()->insertSeparator();
#endif
}

void QApplicationWindow::refresh() {
	const ZLApplication::Toolbar::ItemVector &items = application().toolbar().items();

	bool isVisibilityChanged = false;
	if (myToolbarMask.size() != items.size()) {
		isVisibilityChanged = true;
		myToolbarMask.clear();
		myToolbarMask.assign(items.size(), false);
	}
	std::vector<bool>::iterator bt = myToolbarMask.begin();
	for (ZLApplication::Toolbar::ItemVector::const_iterator it = items.begin(); it != items.end(); ++it) {
		if ((*it)->isButton()) {
			const ZLApplication::Toolbar::ButtonItem &button = (const ZLApplication::Toolbar::ButtonItem&)**it;
			if (application().isActionVisible(button.actionId()) != *bt) {
				*bt = !*bt;
				isVisibilityChanged = true;
			}
			++bt;
		}
	}
#if 00000000
	if (isVisibilityChanged) {
		bt = myToolbarMask.begin();
		/* if (centralWidget() != 0) {
			centralWidget()->hide();
		} */
		myToolBar->clear();
		for (ZLApplication::Toolbar::ItemVector::const_iterator it = items.begin(); it != items.end(); ++it) {
			if ((*it)->isButton()) {
				const ZLApplication::Toolbar::ButtonItem &button = (const ZLApplication::Toolbar::ButtonItem&)**it;
				if (*bt) {
					myToolBar->insertItem(QPixmap((std::string(getenv("FBDIR")) + "/pics/" + button.iconName() + ".png").c_str()), this, SLOT(emptySlot()), 0, button.actionId());
				}
				++bt;
			}
		}
		/* if (centralWidget() != 0) {
			centralWidget()->show();
		} */
	}

	ZPushButton* cstButton = cst->getRightBtn();
	if (myToolBar->count() >= 12) {
		cstButton->setResourceID("CST_Exit");
	} else {
		cstButton->setResourceID("CST_Back");
	}

	for (ZLApplication::Toolbar::ItemVector::const_iterator it = items.begin(); it != items.end(); ++it) {
		if ((*it)->isButton()) {
			const ZLApplication::Toolbar::ButtonItem &button = (const ZLApplication::Toolbar::ButtonItem&)**it;
			int id = button.actionId();
			if (myToolBar->findItem(id) != 0) {
				myToolBar->setItemEnabled(id, application().isActionEnabled(id));
			}
		}
	}

	MenuMaskCalculator calculator(*this);
	calculator.processMenu(application().menubar());
	if (calculator.shouldBeUpdated()) {
		myMenu->clear();
		myMenu->insertItem("About", this, SLOT(showAboutDialog()));
		myMenu->insertSeparator();
		MenuUpdater(*this).processMenu(application().menubar());
	} else {
		for (std::map<int,QtMenuAction*>::iterator it = myMenuMap.begin(); it != myMenuMap.end(); ++it) {
			it->second->setEnabled(application().isActionEnabled(it->first));
		}
	}
#endif
}

void QApplicationWindow::doActionSlot(int buttonNumber) {
	application().doAction(buttonNumber);
}

void QApplicationWindow::keyPressEvent(QKeyEvent *event) {
	application().doActionByKey(QKeyUtil::keyName(event));
}

void QApplicationWindow::focusOutEvent(QFocusEvent*) {
	setFullscreen(false);
}

void QApplicationWindow::resizeEvent(QResizeEvent*) {
}

void QApplicationWindow::setFullscreen(bool fullscreen) {
	if (fullscreen == myFullScreen) {
		return;
	}
	myFullScreen = fullscreen;
	if (myFullScreen) {
//		cst->hide();
//		myToolBar->hide();
	    setFullScreenMode(true, true);
		showMaximized();
		raise();
//		::system("lcdsleep 0");
	} else {
//		myToolBar->show();
//		cst->show();
	    setFullScreenMode(false, false);
	    //showNormal();
	    showMaximized();
	    raise();
//		::system("lcdsleep r");
	}
}


bool QApplicationWindow::isFullscreen() const {
	return myFullScreen;
}

void QApplicationWindow::closeEvent(QCloseEvent *event) {
	if (application().closeView()) {
		event->accept();
	} else {
		event->ignore();
	}
}

void QApplicationWindow::close() {
#if 00000000
	QMainWindow::close();
#endif
}

void QApplicationWindow::setDocument(const QString &fileName) {
	if (!fileName.isEmpty()) {
		application().openFile((const char*)fileName.utf8());
	}
}

void QApplicationWindow::addFile()
{
    doActionSlot(24 /*ACTION_ADD_BOOK*/);
}

void QApplicationWindow::gotoStart()
{
    doActionSlot(16 /*ACTION_SCROLL_TO_START_OF_TEXT*/);
}

void QApplicationWindow::gotoEnd()
{
    doActionSlot(17 /*ACTION_SCROLL_TO_END_OF_TEXT*/);
}

void QApplicationWindow::findStart()
{
    doActionSlot(6 /*ACTION_SEARCH*/);
}

void QApplicationWindow::findRepeat()
{
    doActionSlot(8 /*ACTION_FIND_NEXT*/);
}

void QApplicationWindow::findBack()
{
    doActionSlot(7 /*ACTION_FIND_PREVIOUS*/);
}

void QApplicationWindow::showOptions()
{
    doActionSlot(2 /*ACTION_SHOW_OPTIONS*/);
}

void QApplicationWindow::bookInfo()
{
    doActionSlot(25 /*ACTION_SHOW_BOOK_INFO*/);
}

#include <ZLabel.h>
#include <ZScrollView.h>

ZLViewWidget *QApplicationWindow::createViewWidget() {

	QViewWidget *viewWidget = new QViewWidget(this, &application());

	ZSoftKey *softKey = getSoftKey(true);

	QRect rect;
	ZOptionsMenu* menu = new ZOptionsMenu(rect, softKey, NULL, 0, (ZSkinService::WidgetClsID)2);
	menu->insertItem(QString("About"), NULL, NULL, true, 0, 0);
	menu->insertItem(QString("Book Info"), NULL, NULL, true, 1, 1 );
	menu->insertItem(QString("Open Book"), NULL, NULL, true, 2, 2 );
	menu->insertItem(QString("First Page"), NULL, NULL, true, 3, 3 );
	menu->insertItem(QString("Last Page"), NULL, NULL, true, 4, 4 );
	menu->insertItem(QString("Find"), NULL, NULL, true, 5, 5 );
	menu->insertItem(QString("Find Next"), NULL, NULL, true, 6, 6 );
	menu->insertItem(QString("Find Previous"), NULL, NULL, true, 7, 7 );
	menu->insertItem(QString("Config"), NULL, NULL, true, 8, 8 );
	softKey->setOptMenu(ZSoftKey::LEFT, menu);

	softKey->setText(ZSoftKey::LEFT, "Menu", (ZSoftKey::TEXT_PRIORITY)0);
	softKey->setText(ZSoftKey::RIGHT, "Quit", (ZSoftKey::TEXT_PRIORITY)0);
	softKey->setClickedSlot(ZSoftKey::RIGHT, qApp, SLOT(quit()));

	menu->connectItem(0, this, SLOT(showAboutDialog()));
	menu->connectItem(1, this, SLOT(bookInfo()));
	menu->connectItem(2, this, SLOT(addFile()));
	menu->connectItem(3, this, SLOT(gotoStart()));
	menu->connectItem(4, this, SLOT(gotoEnd()));
	menu->connectItem(5, this, SLOT(findStart()));
	menu->connectItem(6, this, SLOT(findRepeat()));
	menu->connectItem(7, this, SLOT(findBack()));
	menu->connectItem(8, this, SLOT(showOptions()));

	ZMainWidget::setContentWidget(viewWidget->widget());
	setFullScreenMode(true,true);
	myFullScreen = true;
	viewWidget->widget()->show();
	return viewWidget;
}

bool QApplicationWindow::isFingerTapEventSupported() const {
	return false;
}

QtMenuAction::QtMenuAction(ZLApplication &application, const ZLApplication::Menubar::PlainItem &item)
    : /*QAction(item.name().c_str(), 0, 0, 0),*/
    myApplication(application),
    myActionId(item.actionId()) {
	connect(this, SIGNAL(activated()), this, SLOT(doSlot()));
}

void QtMenuAction::doSlot() {
	myApplication.doAction(myActionId);
}

void QApplicationWindow::showAboutDialog() {
	/*UTIL_Dialog aboutDialog(UTIL_Dialog::APP_MODAL, true, this, 0, 1, 0);
	aboutDialog.setDlgTitle("FBReader");

	QWidget *cw = aboutDialog.getDlgContent();
	QVBoxLayout *layout = new QVBoxLayout(cw, 4);
	QLabel *l = new QLabel(QString("<qt><font size=\"-1\"><p>Copyright (C) 2004-2006 Nikolay Pultsin<br>"
			"<tt>&lt;geometer@mawhrin.net&gt;</tt><br>"
			"Copyright (C) 2005 Mikhail Sobolev<br>"
			"<tt>&lt;mss@mawhrin.net&gt;</tt></p>"
			"<p>Port to Motorola EZX by Ketut P. Kumajaya<br>"
			"<tt>&lt;kumajaya@bluebottle.com&gt;</tt></p></font></qt>"),
			cw);
	layout->addWidget(l);

	QHBox *cstHBox = new QHBox(&aboutDialog);
	aboutDialog.setDlgCst(cstHBox);
	UTIL_PushButton *b = new UTIL_PushButton(cstHBox, 0, -1, -1);
	b->setText("Close");
	b->resize(ZGlobal::getDlgB1_1R().size());
	connect(b, SIGNAL(clicked()), &aboutDialog, SLOT(reject()));

	aboutDialog.exec();*/

	QAboutDialog aboutDialog("About");
	aboutDialog.exec();
}
