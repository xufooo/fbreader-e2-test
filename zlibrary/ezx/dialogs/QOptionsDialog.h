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

#ifndef __QOPTIONSDIALOG_H__
#define __QOPTIONSDIALOG_H__

#include <vector>

#include <qwidget.h>
#include <qlist.h>

#include "../../abstract/dialogs/ZLOptionsDialog.h"

#include "FullScreenDialog.h"

class QTabWidget;
class QOptionView;
class QGridLayout;
class ZOptionsMenu;

class QOptionsDialogTab : public QWidget, public ZLDialogContent {
	Q_OBJECT

public:
	QOptionsDialogTab(QWidget *parent);
	~QOptionsDialogTab();

	void addOption(ZLOptionEntry *option);
	void addOptions(ZLOptionEntry *option0, ZLOptionEntry *option1);

	void addItem(QWidget *widget, int row, int fromColumn, int toColumn,
	    int align);

	void close();
	void accept();

#if 1
	virtual QSize sizeHint() const
	{
	    QSize s = myLayout->sizeHint();
printf("sizeHint: %d %d\n", s.width(), s.height()); fflush(stdout);
            if (s.width() > 240)
		s.setWidth(240);
            if (s.width() > 320)
		s.setHeight(320);
	    return s;
	}
#endif

private:
	void createViewByEntry(ZLOptionEntry *option, int fromColumn, int toColumn);

private:
	QGridLayout *myLayout;
	int myRowCounter;

	QList<QOptionView> myViews;
};

class QOptionsDialog : public FullScreenDialog, public ZLOptionsDialog {
	Q_OBJECT

public:
	QOptionsDialog(const std::string &id, const std::string &caption);
	~QOptionsDialog() {}
	ZLDialogContent &createTab(const std::string &name);

protected:
	const std::string &selectedTabName() const;
	void selectTab(const std::string &name);
	bool run();

	void resizeEvent(QResizeEvent *);
	void keyPressEvent(QKeyEvent *event);

private slots:
	void accept();
	void selectTab(int id);

private:
	QTabWidget *myTabWidget;

	QList<QOptionsDialogTab> myTabs;
	std::vector<std::string> myTabNames;
	int tabno;

	ZOptionsMenu *menu;
	std::string cap;
};

#endif /* __QOPTIONSDIALOG_H__ */
