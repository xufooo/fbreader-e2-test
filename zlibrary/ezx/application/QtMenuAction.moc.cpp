/****************************************************************************
** QtMenuAction meta object code from reading C++ file 'QtMenuAction.h'
**
** Created: Mon Dec 19 19:09:00 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.10   edited 2005-01-24 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "QtMenuAction.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QtMenuAction::className() const
{
    return "QtMenuAction";
}

QMetaObject *QtMenuAction::metaObj = 0;

#ifdef QWS
static class QtMenuAction_metaObj_Unloader {
public:
    ~QtMenuAction_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QtMenuAction" );
    }
} QtMenuAction_metaObj_unloader;
#endif

void QtMenuAction::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QtMenuAction","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QtMenuAction::tr(const char* s)
{
    return qApp->translate( "QtMenuAction", s, 0 );
}

QString QtMenuAction::tr(const char* s, const char * c)
{
    return qApp->translate( "QtMenuAction", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QtMenuAction::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (QtMenuAction::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &QtMenuAction::doSlot;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "doSlot()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"QtMenuAction", "QWidget",
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
