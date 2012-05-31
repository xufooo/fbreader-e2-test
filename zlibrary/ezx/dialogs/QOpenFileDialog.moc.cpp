/****************************************************************************
** QOpenFileDialog meta object code from reading C++ file 'QOpenFileDialog.h'
**
** Created: Mon Dec 19 19:08:57 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.10   edited 2005-01-24 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QOpenFileDialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QOpenFileDialog::className() const
{
    return "QOpenFileDialog";
}

QMetaObject *QOpenFileDialog::metaObj = 0;

#ifdef QWS
static class QOpenFileDialog_metaObj_Unloader {
public:
    ~QOpenFileDialog_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QOpenFileDialog" );
    }
} QOpenFileDialog_metaObj_unloader;
#endif

void QOpenFileDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(FullScreenDialog::className(), "FullScreenDialog") != 0 )
	badSuperclassWarning("QOpenFileDialog","FullScreenDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QOpenFileDialog::tr(const char* s)
{
    return qApp->translate( "QOpenFileDialog", s, 0 );
}

QString QOpenFileDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "QOpenFileDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QOpenFileDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) FullScreenDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (QOpenFileDialog::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &QOpenFileDialog::accept;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "accept()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"QOpenFileDialog", "FullScreenDialog",
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
