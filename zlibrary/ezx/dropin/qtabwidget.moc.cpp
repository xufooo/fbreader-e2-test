/****************************************************************************
** QTabWidget meta object code from reading C++ file 'qtabwidget.h'
**
** Created: Mon Dec 19 19:09:02 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.10   edited 2005-01-24 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "qtabwidget.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QTabWidget::className() const
{
    return "QTabWidget";
}

QMetaObject *QTabWidget::metaObj = 0;

#ifdef QWS
static class QTabWidget_metaObj_Unloader {
public:
    ~QTabWidget_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QTabWidget" );
    }
} QTabWidget_metaObj_unloader;
#endif

void QTabWidget::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QTabWidget","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QTabWidget::tr(const char* s)
{
    return qApp->translate( "QTabWidget", s, 0 );
}

QString QTabWidget::tr(const char* s, const char * c)
{
    return qApp->translate( "QTabWidget", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QTabWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    QMetaEnum* enum_tbl = QMetaObject::new_metaenum( 2 );
    enum_tbl[0].name = "TabPosition";
    enum_tbl[0].count = 2;
    enum_tbl[0].items = QMetaObject::new_metaenum_item( 2 );
    enum_tbl[0].set = FALSE;
    enum_tbl[0].items[0].key = "Top";
    enum_tbl[0].items[0].value = (int) QTabWidget::Top;
    enum_tbl[0].items[1].key = "Bottom";
    enum_tbl[0].items[1].value = (int) QTabWidget::Bottom;
    enum_tbl[1].name = "TabShape";
    enum_tbl[1].count = 2;
    enum_tbl[1].items = QMetaObject::new_metaenum_item( 2 );
    enum_tbl[1].set = FALSE;
    enum_tbl[1].items[0].key = "Rounded";
    enum_tbl[1].items[0].value = (int) QTabWidget::Rounded;
    enum_tbl[1].items[1].key = "Triangular";
    enum_tbl[1].items[1].value = (int) QTabWidget::Triangular;
#endif // QT_NO_PROPERTIES
#ifndef QT_NO_PROPERTIES
    typedef TabPosition (QTabWidget::*m3_t0)()const;
    typedef TabPosition (QObject::*om3_t0)()const;
    typedef void (QTabWidget::*m3_t1)(TabPosition);
    typedef void (QObject::*om3_t1)(TabPosition);
    typedef TabShape (QTabWidget::*m3_t3)()const;
    typedef TabShape (QObject::*om3_t3)()const;
    typedef void (QTabWidget::*m3_t4)(TabShape);
    typedef void (QObject::*om3_t4)(TabShape);
    typedef int (QTabWidget::*m3_t6)()const;
    typedef int (QObject::*om3_t6)()const;
    typedef void (QTabWidget::*m3_t7)(int);
    typedef void (QObject::*om3_t7)(int);
    typedef int (QTabWidget::*m3_t9)()const;
    typedef int (QObject::*om3_t9)()const;
    typedef void (QTabWidget::*m3_t10)(int);
    typedef void (QObject::*om3_t10)(int);
    m3_t0 v3_0 = &QTabWidget::tabPosition;
    om3_t0 ov3_0 = (om3_t0)v3_0;
    m3_t1 v3_1 = &QTabWidget::setTabPosition;
    om3_t1 ov3_1 = (om3_t1)v3_1;
    m3_t3 v3_3 = &QTabWidget::tabShape;
    om3_t3 ov3_3 = (om3_t3)v3_3;
    m3_t4 v3_4 = &QTabWidget::setTabShape;
    om3_t4 ov3_4 = (om3_t4)v3_4;
    m3_t6 v3_6 = &QTabWidget::margin;
    om3_t6 ov3_6 = (om3_t6)v3_6;
    m3_t7 v3_7 = &QTabWidget::setMargin;
    om3_t7 ov3_7 = (om3_t7)v3_7;
    m3_t9 v3_9 = &QTabWidget::currentPageIndex;
    om3_t9 ov3_9 = (om3_t9)v3_9;
    m3_t10 v3_10 = &QTabWidget::setCurrentPage;
    om3_t10 ov3_10 = (om3_t10)v3_10;
    QMetaProperty *props_tbl = QMetaObject::new_metaproperty( 4 );
    props_tbl[0].t = "TabPosition";
    props_tbl[0].n = "tabPosition";
    props_tbl[0].get = (QMember)ov3_0;
    props_tbl[0].set = (QMember)ov3_1;
    props_tbl[0].reset = 0;
    props_tbl[0].gspec = QMetaProperty::Class;
    props_tbl[0].sspec = QMetaProperty::Class;
    props_tbl[0].enumData = &enum_tbl[0];
    props_tbl[0].setFlags(QMetaProperty::StdSet);
    props_tbl[1].t = "TabShape";
    props_tbl[1].n = "tabShape";
    props_tbl[1].get = (QMember)ov3_3;
    props_tbl[1].set = (QMember)ov3_4;
    props_tbl[1].reset = 0;
    props_tbl[1].gspec = QMetaProperty::Class;
    props_tbl[1].sspec = QMetaProperty::Class;
    props_tbl[1].enumData = &enum_tbl[1];
    props_tbl[1].setFlags(QMetaProperty::StdSet);
    props_tbl[2].t = "int";
    props_tbl[2].n = "margin";
    props_tbl[2].get = (QMember)ov3_6;
    props_tbl[2].set = (QMember)ov3_7;
    props_tbl[2].reset = 0;
    props_tbl[2].gspec = QMetaProperty::Class;
    props_tbl[2].sspec = QMetaProperty::Class;
    props_tbl[2].setFlags(QMetaProperty::StdSet);
    props_tbl[3].t = "int";
    props_tbl[3].n = "currentPage";
    props_tbl[3].get = (QMember)ov3_9;
    props_tbl[3].set = (QMember)ov3_10;
    props_tbl[3].reset = 0;
    props_tbl[3].gspec = QMetaProperty::Class;
    props_tbl[3].sspec = QMetaProperty::Class;
    props_tbl[3].setFlags(QMetaProperty::StdSet);
#endif // QT_NO_PROPERTIES
    typedef void (QTabWidget::*m1_t0)(int);
    typedef void (QObject::*om1_t0)(int);
    m1_t0 v1_0 = &QTabWidget::showTab;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "showTab(int)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    typedef void (QTabWidget::*m2_t0)(QWidget*);
    typedef void (QObject::*om2_t0)(QWidget*);
    typedef void (QTabWidget::*m2_t1)(const QString&);
    typedef void (QObject::*om2_t1)(const QString&);
    m2_t0 v2_0 = &QTabWidget::currentChanged;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    m2_t1 v2_1 = &QTabWidget::selected;
    om2_t1 ov2_1 = (om2_t1)v2_1;
    QMetaData *signal_tbl = QMetaObject::new_metadata(2);
    signal_tbl[0].name = "currentChanged(QWidget*)";
    signal_tbl[0].ptr = (QMember)ov2_0;
    signal_tbl[1].name = "selected(const QString&)";
    signal_tbl[1].ptr = (QMember)ov2_1;
    metaObj = QMetaObject::new_metaobject(
	"QTabWidget", "QWidget",
	slot_tbl, 1,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	props_tbl, 4,
	enum_tbl, 2,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL currentChanged
void QTabWidget::currentChanged( QWidget* t0 )
{
    // No builtin function for signal parameter type QWidget*
    QConnectionList *clist = receivers("currentChanged(QWidget*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QWidget*);
    RT0 r0;
    RT1 r1;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
#ifdef Q_FP_CCAST_BROKEN
		r0 = reinterpret_cast<RT0>(*(c->member()));
#else
		r0 = (RT0)*(c->member());
#endif
		(object->*r0)();
		break;
	    case 1:
#ifdef Q_FP_CCAST_BROKEN
		r1 = reinterpret_cast<RT1>(*(c->member()));
#else
		r1 = (RT1)*(c->member());
#endif
		(object->*r1)(t0);
		break;
	}
    }
}

// SIGNAL selected
void QTabWidget::selected( const QString& t0 )
{
    activate_signal_strref( "selected(const QString&)", t0 );
}
