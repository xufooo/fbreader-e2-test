/****************************************************************************
** QOptionsDialogTab meta object code from reading C++ file 'QOptionsDialog.h'
**
** Created: Mon Dec 19 19:08:55 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.10   edited 2005-01-24 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QOptionsDialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QOptionsDialogTab::className() const
{
    return "QOptionsDialogTab";
}

QMetaObject *QOptionsDialogTab::metaObj = 0;

#ifdef QWS
static class QOptionsDialogTab_metaObj_Unloader {
public:
    ~QOptionsDialogTab_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QOptionsDialogTab" );
    }
} QOptionsDialogTab_metaObj_unloader;
#endif

void QOptionsDialogTab::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QOptionsDialogTab","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QOptionsDialogTab::tr(const char* s)
{
    return qApp->translate( "QOptionsDialogTab", s, 0 );
}

QString QOptionsDialogTab::tr(const char* s, const char * c)
{
    return qApp->translate( "QOptionsDialogTab", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QOptionsDialogTab::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QOptionsDialogTab", "QWidget",
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


const char *QOptionsDialog::className() const
{
    return "QOptionsDialog";
}

QMetaObject *QOptionsDialog::metaObj = 0;

#ifdef QWS
static class QOptionsDialog_metaObj_Unloader {
public:
    ~QOptionsDialog_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QOptionsDialog" );
    }
} QOptionsDialog_metaObj_unloader;
#endif

void QOptionsDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(FullScreenDialog::className(), "FullScreenDialog") != 0 )
	badSuperclassWarning("QOptionsDialog","FullScreenDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QOptionsDialog::tr(const char* s)
{
    return qApp->translate( "QOptionsDialog", s, 0 );
}

QString QOptionsDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "QOptionsDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QOptionsDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) FullScreenDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (QOptionsDialog::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (QOptionsDialog::*m1_t1)(int);
    typedef void (QObject::*om1_t1)(int);
    m1_t0 v1_0 = &QOptionsDialog::accept;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &QOptionsDialog::selectTab;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "accept()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "selectTab(int)";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"QOptionsDialog", "FullScreenDialog",
	slot_tbl, 2,
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
