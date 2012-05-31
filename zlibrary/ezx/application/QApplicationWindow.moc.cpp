/****************************************************************************
** QAboutDialog meta object code from reading C++ file 'QApplicationWindow.h'
**
** Created: Mon Dec 19 19:08:58 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.10   edited 2005-01-24 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QApplicationWindow.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QAboutDialog::className() const
{
    return "QAboutDialog";
}

QMetaObject *QAboutDialog::metaObj = 0;

#ifdef QWS
static class QAboutDialog_metaObj_Unloader {
public:
    ~QAboutDialog_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QAboutDialog" );
    }
} QAboutDialog_metaObj_unloader;
#endif

void QAboutDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(FullScreenDialog::className(), "FullScreenDialog") != 0 )
	badSuperclassWarning("QAboutDialog","FullScreenDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QAboutDialog::tr(const char* s)
{
    return qApp->translate( "QAboutDialog", s, 0 );
}

QString QAboutDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "QAboutDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QAboutDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) FullScreenDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QAboutDialog", "FullScreenDialog",
	0, 0,
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


const char *QApplicationWindow::className() const
{
    return "QApplicationWindow";
}

QMetaObject *QApplicationWindow::metaObj = 0;

#ifdef QWS
static class QApplicationWindow_metaObj_Unloader {
public:
    ~QApplicationWindow_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QApplicationWindow" );
    }
} QApplicationWindow_metaObj_unloader;
#endif

void QApplicationWindow::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(ZKbMainWidget::className(), "ZKbMainWidget") != 0 )
	badSuperclassWarning("QApplicationWindow","ZKbMainWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QApplicationWindow::tr(const char* s)
{
    return qApp->translate( "QApplicationWindow", s, 0 );
}

QString QApplicationWindow::tr(const char* s, const char * c)
{
    return qApp->translate( "QApplicationWindow", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QApplicationWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) ZKbMainWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (QApplicationWindow::*m1_t0)(int);
    typedef void (QObject::*om1_t0)(int);
    typedef void (QApplicationWindow::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (QApplicationWindow::*m1_t2)(const QString&);
    typedef void (QObject::*om1_t2)(const QString&);
    typedef void (QApplicationWindow::*m1_t3)();
    typedef void (QObject::*om1_t3)();
    typedef void (QApplicationWindow::*m1_t4)();
    typedef void (QObject::*om1_t4)();
    typedef void (QApplicationWindow::*m1_t5)();
    typedef void (QObject::*om1_t5)();
    typedef void (QApplicationWindow::*m1_t6)();
    typedef void (QObject::*om1_t6)();
    typedef void (QApplicationWindow::*m1_t7)();
    typedef void (QObject::*om1_t7)();
    typedef void (QApplicationWindow::*m1_t8)();
    typedef void (QObject::*om1_t8)();
    typedef void (QApplicationWindow::*m1_t9)();
    typedef void (QObject::*om1_t9)();
    typedef void (QApplicationWindow::*m1_t10)();
    typedef void (QObject::*om1_t10)();
    typedef void (QApplicationWindow::*m1_t11)();
    typedef void (QObject::*om1_t11)();
    typedef void (QApplicationWindow::*m1_t12)();
    typedef void (QObject::*om1_t12)();
    m1_t0 v1_0 = &QApplicationWindow::doActionSlot;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &QApplicationWindow::emptySlot;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &QApplicationWindow::setDocument;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &QApplicationWindow::setFullscreen;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    m1_t4 v1_4 = &QApplicationWindow::addFile;
    om1_t4 ov1_4 = (om1_t4)v1_4;
    m1_t5 v1_5 = &QApplicationWindow::gotoStart;
    om1_t5 ov1_5 = (om1_t5)v1_5;
    m1_t6 v1_6 = &QApplicationWindow::gotoEnd;
    om1_t6 ov1_6 = (om1_t6)v1_6;
    m1_t7 v1_7 = &QApplicationWindow::findStart;
    om1_t7 ov1_7 = (om1_t7)v1_7;
    m1_t8 v1_8 = &QApplicationWindow::findRepeat;
    om1_t8 ov1_8 = (om1_t8)v1_8;
    m1_t9 v1_9 = &QApplicationWindow::findBack;
    om1_t9 ov1_9 = (om1_t9)v1_9;
    m1_t10 v1_10 = &QApplicationWindow::showOptions;
    om1_t10 ov1_10 = (om1_t10)v1_10;
    m1_t11 v1_11 = &QApplicationWindow::bookInfo;
    om1_t11 ov1_11 = (om1_t11)v1_11;
    m1_t12 v1_12 = &QApplicationWindow::showAboutDialog;
    om1_t12 ov1_12 = (om1_t12)v1_12;
    QMetaData *slot_tbl = QMetaObject::new_metadata(13);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(13);
    slot_tbl[0].name = "doActionSlot(int)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "emptySlot()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Private;
    slot_tbl[2].name = "setDocument(const QString&)";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Private;
    slot_tbl[3].name = "setFullscreen()";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Private;
    slot_tbl[4].name = "addFile()";
    slot_tbl[4].ptr = (QMember)ov1_4;
    slot_tbl_access[4] = QMetaData::Private;
    slot_tbl[5].name = "gotoStart()";
    slot_tbl[5].ptr = (QMember)ov1_5;
    slot_tbl_access[5] = QMetaData::Private;
    slot_tbl[6].name = "gotoEnd()";
    slot_tbl[6].ptr = (QMember)ov1_6;
    slot_tbl_access[6] = QMetaData::Private;
    slot_tbl[7].name = "findStart()";
    slot_tbl[7].ptr = (QMember)ov1_7;
    slot_tbl_access[7] = QMetaData::Private;
    slot_tbl[8].name = "findRepeat()";
    slot_tbl[8].ptr = (QMember)ov1_8;
    slot_tbl_access[8] = QMetaData::Private;
    slot_tbl[9].name = "findBack()";
    slot_tbl[9].ptr = (QMember)ov1_9;
    slot_tbl_access[9] = QMetaData::Private;
    slot_tbl[10].name = "showOptions()";
    slot_tbl[10].ptr = (QMember)ov1_10;
    slot_tbl_access[10] = QMetaData::Private;
    slot_tbl[11].name = "bookInfo()";
    slot_tbl[11].ptr = (QMember)ov1_11;
    slot_tbl_access[11] = QMetaData::Private;
    slot_tbl[12].name = "showAboutDialog()";
    slot_tbl[12].ptr = (QMember)ov1_12;
    slot_tbl_access[12] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"QApplicationWindow", "ZKbMainWidget",
	slot_tbl, 13,
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
