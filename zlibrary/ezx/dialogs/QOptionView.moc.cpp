/****************************************************************************
** BooleanOptionView meta object code from reading C++ file 'QOptionView.h'
**
** Created: Mon Dec 19 19:08:56 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.10   edited 2005-01-24 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QOptionView.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *BooleanOptionView::className() const
{
    return "BooleanOptionView";
}

QMetaObject *BooleanOptionView::metaObj = 0;

#ifdef QWS
static class BooleanOptionView_metaObj_Unloader {
public:
    ~BooleanOptionView_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "BooleanOptionView" );
    }
} BooleanOptionView_metaObj_unloader;
#endif

void BooleanOptionView::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("BooleanOptionView","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString BooleanOptionView::tr(const char* s)
{
    return qApp->translate( "BooleanOptionView", s, 0 );
}

QString BooleanOptionView::tr(const char* s, const char * c)
{
    return qApp->translate( "BooleanOptionView", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* BooleanOptionView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (BooleanOptionView::*m1_t0)(bool)const;
    typedef void (QObject::*om1_t0)(bool)const;
    m1_t0 v1_0 = &BooleanOptionView::onValueChange;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "onValueChange(bool)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"BooleanOptionView", "QObject",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *ComboOptionView::className() const
{
    return "ComboOptionView";
}

QMetaObject *ComboOptionView::metaObj = 0;

#ifdef QWS
static class ComboOptionView_metaObj_Unloader {
public:
    ~ComboOptionView_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "ComboOptionView" );
    }
} ComboOptionView_metaObj_unloader;
#endif

void ComboOptionView::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("ComboOptionView","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString ComboOptionView::tr(const char* s)
{
    return qApp->translate( "ComboOptionView", s, 0 );
}

QString ComboOptionView::tr(const char* s, const char * c)
{
    return qApp->translate( "ComboOptionView", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* ComboOptionView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (ComboOptionView::*m1_t0)(int);
    typedef void (QObject::*om1_t0)(int);
    m1_t0 v1_0 = &ComboOptionView::onValueChange;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "onValueChange(int)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"ComboOptionView", "QObject",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *KeyOptionView::className() const
{
    return "KeyOptionView";
}

QMetaObject *KeyOptionView::metaObj = 0;

#ifdef QWS
static class KeyOptionView_metaObj_Unloader {
public:
    ~KeyOptionView_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "KeyOptionView" );
    }
} KeyOptionView_metaObj_unloader;
#endif

void KeyOptionView::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("KeyOptionView","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString KeyOptionView::tr(const char* s)
{
    return qApp->translate( "KeyOptionView", s, 0 );
}

QString KeyOptionView::tr(const char* s, const char * c)
{
    return qApp->translate( "KeyOptionView", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* KeyOptionView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (KeyOptionView::*m1_t0)(int);
    typedef void (QObject::*om1_t0)(int);
    m1_t0 v1_0 = &KeyOptionView::onValueChange;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "onValueChange(int)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"KeyOptionView", "QObject",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}


const char *ColorOptionView::className() const
{
    return "ColorOptionView";
}

QMetaObject *ColorOptionView::metaObj = 0;

#ifdef QWS
static class ColorOptionView_metaObj_Unloader {
public:
    ~ColorOptionView_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "ColorOptionView" );
    }
} ColorOptionView_metaObj_unloader;
#endif

void ColorOptionView::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("ColorOptionView","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString ColorOptionView::tr(const char* s)
{
    return qApp->translate( "ColorOptionView", s, 0 );
}

QString ColorOptionView::tr(const char* s, const char * c)
{
    return qApp->translate( "ColorOptionView", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* ColorOptionView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (ColorOptionView::*m1_t0)(int);
    typedef void (QObject::*om1_t0)(int);
    m1_t0 v1_0 = &ColorOptionView::onSliderMove;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "onSliderMove(int)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"ColorOptionView", "QObject",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}
