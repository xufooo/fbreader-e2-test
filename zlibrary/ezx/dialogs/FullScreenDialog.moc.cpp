/****************************************************************************
** FullScreenDialog meta object code from reading C++ file 'FullScreenDialog.h'
**
** Created: Mon Dec 19 19:08:54 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.10   edited 2005-01-24 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "FullScreenDialog.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *FullScreenDialog::className() const
{
    return "FullScreenDialog";
}

QMetaObject *FullScreenDialog::metaObj = 0;

#ifdef QWS
static class FullScreenDialog_metaObj_Unloader {
public:
    ~FullScreenDialog_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "FullScreenDialog" );
    }
} FullScreenDialog_metaObj_unloader;
#endif

void FullScreenDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(ZMainWidget::className(), "ZMainWidget") != 0 )
	badSuperclassWarning("FullScreenDialog","ZMainWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString FullScreenDialog::tr(const char* s)
{
    return qApp->translate( "FullScreenDialog", s, 0 );
}

QString FullScreenDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "FullScreenDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* FullScreenDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) ZMainWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (FullScreenDialog::*m1_t0)(int);
    typedef void (QObject::*om1_t0)(int);
    typedef void (FullScreenDialog::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (FullScreenDialog::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    m1_t0 v1_0 = &FullScreenDialog::done;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &FullScreenDialog::accept;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &FullScreenDialog::reject;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    QMetaData *slot_tbl = QMetaObject::new_metadata(3);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(3);
    slot_tbl[0].name = "done(int)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Protected;
    slot_tbl[1].name = "accept()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Protected;
    slot_tbl[2].name = "reject()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"FullScreenDialog", "ZMainWidget",
	slot_tbl, 3,
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
