/****************************************************************************
** QCommonDialog meta object code from reading C++ file 'QCommonDialog.h'
**
** Created: Mon Dec 19 19:08:53 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.10   edited 2005-01-24 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QCommonDialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QCommonDialog::className() const
{
    return "QCommonDialog";
}

QMetaObject *QCommonDialog::metaObj = 0;

#ifdef QWS
static class QCommonDialog_metaObj_Unloader {
public:
    ~QCommonDialog_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QCommonDialog" );
    }
} QCommonDialog_metaObj_unloader;
#endif

void QCommonDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(ZBaseDialog::className(), "ZBaseDialog") != 0 )
	badSuperclassWarning("QCommonDialog","ZBaseDialog");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QCommonDialog::tr(const char* s)
{
    return qApp->translate( "QCommonDialog", s, 0 );
}

QString QCommonDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "QCommonDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QCommonDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) ZBaseDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (QCommonDialog::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (QCommonDialog::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    m1_t0 v1_0 = &QCommonDialog::accept;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &QCommonDialog::reject;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "accept()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Protected;
    slot_tbl[1].name = "reject()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"QCommonDialog", "ZBaseDialog",
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
