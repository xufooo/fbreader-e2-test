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

#include <cctype>

#include <qlabel.h>
#include <qlayout.h>
#include <ZRadioButton.h>
#include <ZApplication.h>
#include <ZCheckBox.h>
#include <ZComboBox.h>
#include <ZLineEdit.h>
#include <ZSlider.h>
#include <ZNumPickerDlg.h>

#include <abstract/ZLStringUtil.h>
#include "../../qt/util/QKeyUtil.h"

#include "QOptionView.h"
#include "QOptionsDialog.h"


void BooleanOptionView::_createItem() {
    myCheckBox = new ZCheckBox(QString(myOption->name().c_str()).replace(QRegExp("[\\n\\r?/<>&\\\\:\"*]"),""), myTab, "ZCheckBox");
#if 0
    QRect rect;
    rect = myCheckBox->getContentRect();
    rect.setWidth(100);
    myCheckBox->setGeometry(rect);
    QSizePolicy pol = myCheckBox->sizePolicy();
    pol.setHorData(QSizePolicy::Fixed);
    myCheckBox->setSizePolicy(pol);
#endif
	QFont f = qApp->font();
	f.setPointSize(14);
	myCheckBox->setFont(f);
	if (((ZLBooleanOptionEntry*)myOption)->initialState())
	    myCheckBox->setState(ZBaseButton::on);
	myTab->addItem(myCheckBox, myRow, myFromColumn, myToColumn, Qt::AlignLeft);
	connect(myCheckBox, SIGNAL(toggled(bool)), this, SLOT(onValueChange(bool)));
}

void BooleanOptionView::_show() {
	myCheckBox->show();
}

void BooleanOptionView::_hide() {
	myCheckBox->hide();
}

void BooleanOptionView::_onAccept() const {
    ((ZLBooleanOptionEntry*)myOption)->onAccept(myCheckBox->getState() == ZBaseButton::on);
}

void BooleanOptionView::onValueChange(bool state) const {
	((ZLBooleanOptionEntry*)myOption)->onValueChange(state);
}

void ChoiceOptionView::_createItem() {
    myGroup = new ZBaseButtonGroup(myTab, "ZBaseButtonGroup");
	myGroup->setFrameStyle(QFrame::NoFrame);
	QVBoxLayout *layout = new QVBoxLayout(myGroup);
	myGroup->setExclusive(true);
	myButtons = new ZRadioButton*[((ZLChoiceOptionEntry*)myOption)->choiceNumber()];
	for (int i = 0; i < ((ZLChoiceOptionEntry*)myOption)->choiceNumber(); ++i) {
	    myButtons[i] = new ZRadioButton(myGroup, "ZRadioButton", (ZSkinService::WidgetClsID)2);
	    myButtons[i]->setText(((ZLChoiceOptionEntry*)myOption)->text(i).c_str());
	    layout->addWidget(myButtons[i]);
	    myGroup->insert(myButtons[i], i);
	}
	myGroup->setButton(((ZLChoiceOptionEntry*)myOption)->initialCheckedIndex());
	myTab->addItem(myGroup, myRow, myFromColumn, myToColumn, Qt::AlignLeft);
}

void ChoiceOptionView::_show() {
	myGroup->show();
}

void ChoiceOptionView::_hide() {
	myGroup->hide();
}

void ChoiceOptionView::_onAccept() const {
	for (int i = 0; i < ((ZLChoiceOptionEntry*)myOption)->choiceNumber(); ++i) {
	    if (myButtons[i]->getState() == ZBaseButton::on) {
			((ZLChoiceOptionEntry*)myOption)->onAccept(i);
			return;
		}
	}
}

void ComboOptionView::_createItem() {
	myLabel = new QLabel(myOption->name().c_str(), myTab);
	myComboBox = new ZComboBox(myTab, "ZComboBox", true);
	const std::vector<std::string> &values = ((ZLComboOptionEntry*)myOption)->values();
	const std::string &initial = ((ZLComboOptionEntry*)myOption)->initialValue();
	int selectedIndex = -1;
	int index = 0;
	for (std::vector<std::string>::const_iterator it = values.begin(); it != values.end(); ++it, ++index) {
	    myComboBox->insertItem(QString(it->c_str()), index);
	    if (*it == initial) {
		selectedIndex = index;
	    }
	}
	QFont f = qApp->font();
	f.setPointSize(14);
	myLabel->setFont(f);
#if 0
	QRect rect = myComboBox->getContentRect();
	rect.setWidth(80);
	myComboBox->setGeometry(rect);
    QSizePolicy pol = myComboBox->sizePolicy();
    pol.setHorData(QSizePolicy::Fixed);
    myComboBox->setSizePolicy(pol);
    pol = myLabel->sizePolicy();
    pol.setHorData(QSizePolicy::Fixed);
    myLabel->setSizePolicy(pol);
    myLabel->setLineWidth(80);
#endif
	connect(myComboBox, SIGNAL(activated(int)), this, SLOT(onValueChange(int)));
	if (selectedIndex >= 0) {
		myComboBox->setCurrentItem(selectedIndex);
	}
	int width = myToColumn - myFromColumn + 1;
	myTab->addItem(myLabel, myRow, myFromColumn, myFromColumn + width * 2 /3  - 1, Qt::AlignLeft);
	myTab->addItem(myComboBox, myRow, myToColumn - width * 2 / 3, myToColumn, Qt::AlignRight);
}

void ComboOptionView::_show() {
	myLabel->show();
	myComboBox->show();
}

void ComboOptionView::_hide() {
	myLabel->hide();
	myComboBox->hide();
}

void ComboOptionView::_setActive(bool active) {
	myComboBox->setEnabled(active);
}

void ComboOptionView::_onAccept() const {
    if (myComboBox->currentItem() >= 0) {
	const std::vector<std::string> &values = ((ZLComboOptionEntry*)myOption)->values();
	int index = 0;
	for (std::vector<std::string>::const_iterator it = values.begin(); it != values.end(); ++it, ++index) {
	    if (index == myComboBox->currentItem()) {
		((ZLComboOptionEntry*)myOption)->onAccept(it->c_str());
		break;
	    }
	}
    }
}

void ComboOptionView::onValueChange(int index) {
	ZLComboOptionEntry *o = (ZLComboOptionEntry*)myOption;
	if ((index >= 0) && (index < (int)o->values().size())) {
		o->onValueChange(o->values()[index]);
	}
}

void SpinOptionView::_createItem() {
	myLabel = new QLabel(myOption->name().c_str(), myTab);
	char tmp[64];
	snprintf(tmp, sizeof(tmp)-1, "%d", ((ZLSpinOptionEntry*)myOption)->maxValue()); 
	myNumPick = new ZNumPicker(strlen(tmp), myTab, NULL, 0, (ZSkinService::WidgetClsID)4);
	myNumPick->setMinValue(((ZLSpinOptionEntry*)myOption)->minValue());
	myNumPick->setMaxValue(((ZLSpinOptionEntry*)myOption)->maxValue());
	myNumPick->setLineStep(((ZLSpinOptionEntry*)myOption)->step());
	myNumPick->setValue(((ZLSpinOptionEntry*)myOption)->initialValue());

	QFont f = qApp->font();
	f.setPointSize(14);
	myLabel->setFont(f);
#if 0
    QSizePolicy pol = myNumPick->sizePolicy();
    pol.setHorData(QSizePolicy::Fixed);
    pol.setVerData(QSizePolicy::Fixed);
    myNumPick->setSizePolicy(pol);
    pol = myLabel->sizePolicy();
    pol.setHorData(QSizePolicy::Fixed);
    myLabel->setSizePolicy(pol);
    myLabel->setLineWidth(80);
#endif
	int width = myToColumn - myFromColumn + 1;
	myTab->addItem(myLabel, myRow, myFromColumn, myFromColumn + (width * 2) / 3 - 1, Qt::AlignLeft);
	myTab->addItem(myNumPick, myRow, myFromColumn + (width * 2) / 3, myToColumn-1, Qt::AlignLeft);
}

void SpinOptionView::_show() {
	myLabel->show();
	myNumPick->show();
}

void SpinOptionView::_hide() {
	myLabel->hide();
	myNumPick->hide();
}

void SpinOptionView::_onAccept() const {
    ((ZLSpinOptionEntry*)myOption)->onAccept(myNumPick->getValue());
}

void StringOptionView::_createItem() {
	myLabel = new QLabel(myOption->name().c_str(), myTab);
	myLineEdit = new ZLineEdit(myTab, "ZLineEdit", ZSkinService::NONE);
	QFont f = qApp->font();
	f.setPointSize(14);
	myLineEdit->setFont(f);
	myLineEdit->setText(QString::fromUtf8(((ZLStringOptionEntry*)myOption)->initialValue().c_str()));
	myLineEdit->cursorLeft(false);
	f = qApp->font();
	f.setPointSize(14);
	myLabel->setFont(f);
#if 0
    QRect rect;
    rect = myLineEdit->getContentRect();
    rect.setWidth(160);
    myLineEdit->setGeometry(rect);
    QSizePolicy pol = myLineEdit->sizePolicy();
    pol.setHorData(QSizePolicy::Fixed);
    myLineEdit->setSizePolicy(pol);
    myLabel->setLineWidth(80);
#endif
	int width = myToColumn - myFromColumn + 1;
	myTab->addItem(myLabel, myRow, myFromColumn, myFromColumn + width / 4 - 1, Qt::AlignLeft);
	myTab->addItem(myLineEdit, myRow, myFromColumn + width / 4, myToColumn, Qt::AlignLeft);
}

void StringOptionView::_show() {
	myLabel->show();
	myLineEdit->show();
}

void StringOptionView::_hide() {
	myLabel->hide();
	myLineEdit->hide();
}

void StringOptionView::_setActive(bool active) {
	myLineEdit->setReadOnly(!active);
}

void StringOptionView::_onAccept() const {
	((ZLStringOptionEntry*)myOption)->onAccept((const char*)myLineEdit->text().utf8());
}

#include <ZPressButton.h>

class KeyButton : public ZPressButton {

public:
	KeyButton(KeyOptionView &keyView);

protected:
//	void focusInEvent(QFocusEvent*);
//	void focusOutEvent(QFocusEvent*);
//	void mousePressEvent(QMouseEvent *);
	void keyPressEvent(QKeyEvent *keyEvent);

private:
	KeyOptionView &myKeyView;
};

KeyButton::KeyButton(KeyOptionView &keyView) :
    ZPressButton(keyView.myWidget, "ZPressButton", (ZSkinService::WidgetClsID)4 /*-1, 232, 25*/),
    myKeyView(keyView) {
	QFont f = qApp->font();
	f.setPointSize(14);
	this->setFont(f);
	setText("Press this button to select key");
	focusOutEvent(0);
}

#if 0
void KeyButton::focusInEvent(QFocusEvent*) {
	setText("Press key to set action");
//	grabKeyboard();
}

void KeyButton::focusOutEvent(QFocusEvent*) {
//	releaseKeyboard();
	setText("Press this button to select key");
}

void KeyButton::mousePressEvent(QMouseEvent*) {
	setFocus();
}
#endif

void KeyButton::keyPressEvent(QKeyEvent *keyEvent) {
	std::string keyText = QKeyUtil::keyName(keyEvent);
	if (keyEvent->key() == Key_Return) {
	    grabKeyboard();
	    return;
	}
	if (keyEvent->key() == Key_Up ||
	    keyEvent->key() == Key_Down) {
	    clearFocus();
	    releaseKeyboard();
	    return;
	}

	if (!keyText.empty()) {
		myKeyView.myCurrentKey = keyText;
		myKeyView.myLabel->setText("Action For " + QString::fromUtf8(keyText.c_str()));
		myKeyView.myLabel->show();
#if 0
    QSizePolicy pol = myKeyView.myLabel->sizePolicy();
    pol.setHorData(QSizePolicy::Fixed);
    myKeyView.myLabel->setSizePolicy(pol);
    myKeyView.myLabel->setLineWidth(80);
    pol = myKeyView.myComboBox->sizePolicy();
    pol.setHorData(QSizePolicy::Fixed);
    myKeyView.myComboBox->setSizePolicy(pol);
#endif
		myKeyView.myComboBox->setCurrentItem(((ZLKeyOptionEntry*)myKeyView.myOption)->actionIndex(keyText));
		myKeyView.myComboBox->show();
	}
}

void KeyOptionView::_createItem() {
	myWidget = new QWidget(myTab);
	QGridLayout *layout = new QGridLayout(myWidget, 2, 2, 0, 10);
	myKeyButton = new KeyButton(*this);
	layout->addMultiCellWidget(myKeyButton, 0, 0, 0, 1);
	myLabel = new QLabel(myWidget);
	myLabel->setTextFormat(QObject::PlainText);
	QFont f = qApp->font();
	f.setPointSize(14);
	myLabel->setFont(f);
#if 0
    QSizePolicy pol = myLabel->sizePolicy();
    pol.setHorData(QSizePolicy::Fixed);
    myLabel->setSizePolicy(pol);
    myLabel->setLineWidth(40);
#endif
	layout->addWidget(myLabel, 1, 0);
	myComboBox = new ZComboBox(myWidget, "ZComboBox", true);
#if 0
    pol = myComboBox->sizePolicy();
    pol.setHorData(QSizePolicy::Fixed);
    myComboBox->setSizePolicy(pol);
#endif
	const std::vector<std::string> &actions = ((ZLKeyOptionEntry*)myOption)->actionNames();
	int index = 0;
	for (std::vector<std::string>::const_iterator it = actions.begin(); it != actions.end(); ++it, ++index) {
	    myComboBox->insertItem(it->c_str(), index);
	}
	connect(myComboBox, SIGNAL(activated(int)), this, SLOT(onValueChange(int)));
	layout->addWidget(myComboBox, 1, 1);
	myTab->addItem(myWidget, myRow, myFromColumn, myToColumn, AlignLeft);
}

void KeyOptionView::_show() {
	myWidget->show();
	myKeyButton->show();
	if (!myCurrentKey.empty()) {
		myLabel->show();
		myComboBox->show();
	} else {
		myLabel->hide();
		myComboBox->hide();
	}
}

void KeyOptionView::_hide() {
	myKeyButton->hide();
	myWidget->hide();
	myLabel->hide();
	myComboBox->hide();
	myCurrentKey.erase();
}

void KeyOptionView::_onAccept() const {
	((ZLKeyOptionEntry*)myOption)->onAccept();
}

void KeyOptionView::onValueChange(int index) {
	if (!myCurrentKey.empty()) {
		((ZLKeyOptionEntry*)myOption)->onValueChange(myCurrentKey, index);
	}
}

void ColorOptionView::_createItem() {
	myWidget = new QWidget(myTab);
	QGridLayout *layout = new QGridLayout(myWidget, 4, 3, 0, 10);
	layout->addWidget(new QLabel("Red", myWidget), 0, 0);
	layout->addWidget(new QLabel("Green", myWidget), 1, 0);
	layout->addWidget(new QLabel("Blue", myWidget), 2, 0);
	const ZLColor &color = ((ZLColorOptionEntry*)myOption)->color();
	myRSlider = new ZSlider(0, 255, 1, color.Red, ZSlider::NONE, ZSlider::Horizontal, myWidget, "R", ZSkinService::NONE);
	myGSlider = new ZSlider(0, 255, 1, color.Green, ZSlider::NONE, ZSlider::Horizontal, myWidget, "G", ZSkinService::NONE);
	myBSlider = new ZSlider(0, 255, 1, color.Blue, ZSlider::NONE, ZSlider::Horizontal, myWidget, "B", ZSkinService::NONE);
	connect(myRSlider, SIGNAL(valueChanged(int)), (QObject*)this, SLOT(onSliderMove(int)));
	connect(myGSlider, SIGNAL(valueChanged(int)), (QObject*)this, SLOT(onSliderMove(int)));
	connect(myBSlider, SIGNAL(valueChanged(int)), (QObject*)this, SLOT(onSliderMove(int)));
	layout->addWidget(myRSlider, 0, 1);
	layout->addWidget(myGSlider, 1, 1);
	layout->addWidget(myBSlider, 2, 1);
	myColorBar = new QLabel("                  ", myWidget);
	myPixmap = new QPixmap(2, 2);
	myPixmap->fill(QColor(color.Red, color.Green, color.Blue));
	myColorBar->setBackgroundPixmap(*myPixmap);
	myColorBar->setFrameStyle(QFrame::Panel | QFrame::Plain);
	layout->addWidget(myColorBar, 3, 1);
	myTab->addItem(myWidget, myRow, myFromColumn, myToColumn, AlignCenter);
}

void ColorOptionView::_show() {
	myWidget->show();
}

void ColorOptionView::_hide() {
	myWidget->hide();
}

void ColorOptionView::onSliderMove(int) {
	myPixmap->fill(QColor(myRSlider->value(), myGSlider->value(), myBSlider->value()));
	myColorBar->setBackgroundPixmap(*myPixmap);
}

void ColorOptionView::_onAccept() const {
	((ZLColorOptionEntry*)myOption)->onAccept(ZLColor(myRSlider->value(), myGSlider->value(), myBSlider->value()));
}
