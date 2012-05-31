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

#ifndef __QOPTIONVIEW_H__
#define __QOPTIONVIEW_H__

#include <qobject.h>
#include <qlabel.h>

#include <ZLineEdit.h>
#include <ZNumPickerDlg.h>
#include <ZComboBox.h>
#include <ZBaseButtonGroup.h>
#include <ZCheckBox.h>
#include <ZSlider.h>

#include "../../abstract/dialogs/ZLOptionsDialog.h"
#include "../../abstract/dialogs/ZLOptionEntry.h"

class QOptionsDialogTab;

class QLabel;
class ZRadioButton;
class QWidget;
class ZNumPicker;


class QOptionView : public OptionView {

protected:
	QOptionView(ZLOptionEntry *option, QOptionsDialogTab *tab, int row, int fromColumn, int toColumn) :
	    OptionView(option),
	    myTab(tab),
	    myRow(row),
	    myFromColumn(fromColumn),
	    myToColumn(toColumn),
	    myInitialized(false) {}
	QOptionView(ZLOptionEntry *option) :
	    OptionView(option),
	    myInitialized(false) {}

public:
	virtual ~QOptionView() {}
	void setPosition(QOptionsDialogTab *tab, int row, int fromColumn, int toColumn) {
		myTab = tab;
		myRow = row;
		myFromColumn = fromColumn;
		myToColumn = toColumn;
	}

	void setVisible(bool visible) {
		if (visible) {
			if (!myInitialized) _createItem();
			myInitialized = true;
			setActive(myOption->isActive());
			_show();
		} else {
			if (myInitialized) _hide();
		}
	}
	void setActive(bool active) {
		if (myInitialized) {
			_setActive(active);
		}
	}
	void onAccept() const { if (myInitialized) _onAccept(); }

protected:
	virtual void _createItem() = 0;
	virtual void _hide() = 0;
	virtual void _show() = 0;
	// TODO: replace by pure virtual method
	virtual void _setActive(bool /*active*/) {}
	virtual void _onAccept() const = 0;

protected:
	QOptionsDialogTab *myTab;
	int myRow, myFromColumn, myToColumn;

private:
	bool myInitialized;
};

class ChoiceOptionView : public QOptionView {

public:
	ChoiceOptionView(ZLChoiceOptionEntry *option, QOptionsDialogTab *tab, int row, int fromColumn, int toColumn) :
	    QOptionView(option, tab, row, fromColumn, toColumn) {
		myButtons = 0;
		myGroup = 0;
	}
	~ChoiceOptionView() {
	    if (myButtons != 0)
		delete[] myButtons;
#if 0
	    if (myGroup)
		delete myGroup;
#endif
	}

protected:
	void _createItem();
	void _show();
	void _hide();
	void _onAccept() const;

private:
	ZBaseButtonGroup *myGroup;
	ZRadioButton **myButtons;
};

class BooleanOptionView : public QObject, public QOptionView {

Q_OBJECT

public:
	BooleanOptionView(ZLBooleanOptionEntry *option, QOptionsDialogTab *tab, int row, int fromColumn, int toColumn) :
	    QOptionView(option, tab, row, fromColumn, toColumn) {}
#if 0
	~BooleanOptionView() {
	    if (myCheckBox)
		delete(myCheckBox);
	}
#endif
protected:
	void _createItem();
	void _show();
	void _hide();
	void _onAccept() const;

private slots:
	void onValueChange(bool) const;

private:
	ZCheckBox *myCheckBox;
};

class StringOptionView : public QOptionView {

public:
	StringOptionView(ZLStringOptionEntry *option, QOptionsDialogTab *tab, int row, int fromColumn, int toColumn) :
	    QOptionView(option, tab, row, fromColumn, toColumn) {}
#if 0
	~StringOptionView() {
	    if (myLabel)
		delete myLabel;
	    if (myLineEdit)
		delete myLineEdit;
	}
#endif

protected:
	void _createItem();
	void _show();
	void _hide();
	void _setActive(bool active);
	void _onAccept() const;

private:
	QLabel *myLabel;
	ZLineEdit *myLineEdit;
};

class SpinOptionView : public QOptionView {

public:
	SpinOptionView(ZLSpinOptionEntry *option, QOptionsDialogTab *tab, int row, int fromColumn, int toColumn) :
	    QOptionView(option, tab, row, fromColumn, toColumn) {}
#if 0
	~SpinOptionView() {
	    if (myLabel)
		delete myLabel;
	    if (myNumPick)
		delete myNumPick;
	}
#endif

protected:
	void _createItem();
	void _show();
	void _hide();
	void _onAccept() const;

private:
	QLabel *myLabel;
	ZNumPicker *myNumPick;
};

class ComboOptionView : public QObject, public QOptionView {

Q_OBJECT

public:
	ComboOptionView(ZLComboOptionEntry *option, QOptionsDialogTab *tab, int row, int fromColumn, int toColumn) :
	    QOptionView(option, tab, row, fromColumn, toColumn) {}
#if 0
	~ComboOptionView() {
	    if (myLabel)
		delete myLabel;
	    if (myComboBox)
		delete myComboBox;
	}
#endif

protected:
	void _createItem();
	void _show();
	void _hide();
	void _setActive(bool active);
	void _onAccept() const;

private slots:
	void onValueChange(int);
	
private:
	QLabel *myLabel;
	ZComboBox *myComboBox;
};

#include <ZPressButton.h>

class KeyOptionView : public QObject, public QOptionView {

Q_OBJECT

public:
	KeyOptionView(ZLKeyOptionEntry *option, QOptionsDialogTab *tab, int row, int fromColumn, int toColumn) :
	    QOptionView(option, tab, row, fromColumn, toColumn) {}
	virtual ~KeyOptionView() {
#if 0
	    if (myKeyButton)
		delete(myKeyButton);
	    if (myLabel)
		delete(myLabel);
	    if (myWidget)
		delete(myWidget);
	    if (myComboBox)
		delete(myComboBox);
#endif
	}

protected:
	void _createItem();
	void _show();
	void _hide();
	void _onAccept() const;

private slots:
	void onValueChange(int);

private:
	QWidget *myWidget;
	ZPressButton *myKeyButton;
	QLabel *myLabel;
	ZComboBox *myComboBox;
	std::string myCurrentKey;

friend class KeyButton;
};

class ColorOptionView : public QObject, public QOptionView {

Q_OBJECT

public:
	ColorOptionView(ZLColorOptionEntry *option, QOptionsDialogTab *tab, int row, int fromColumn, int toColumn) :
	    QOptionView(option, tab, row, fromColumn, toColumn) {}

#if 0
	~ColorOptionView() {
	    if (myRSlider)
		delete myRSlider;
	    if (myGSlider)
		delete myGSlider;
	    if (myBSlider)
		delete myBSlider;
	    if (myWidget)
		delete myWidget;
	    if (myColorBar)
		delete myColorBar;
	    if (myPixmap)
		delete myPixmap;
	}
#endif

protected:
	void _createItem();
	void _show();
	void _hide();
	void _onAccept() const;

private slots:
	void onSliderMove(int);

private:
	QWidget *myWidget;
	ZSlider *myRSlider, *myGSlider, *myBSlider;
	QLabel *myColorBar;
	QPixmap *myPixmap;
};

#endif /* __QOPTIONVIEW_H__ */
