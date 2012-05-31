/****************************************************************************
** QTabBar meta object code from reading C++ file 'qtabbar.h'
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

#include "qtabbar.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QTabBar::className() const
{
    return "QTabBar";
}

QMetaObject *QTabBar::metaObj = 0;

#ifdef QWS
static class QTabBar_metaObj_Unloader {
public:
    ~QTabBar_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QTabBar" );
    }
} QTabBar_metaObj_unloader;
#endif

void QTabBar::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QTabBar","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QTabBar::tr(const char* s)
{
    return qApp->translate( "QTabBar", s, 0 );
}

QString QTabBar::tr(const char* s, const char * c)
{
    return qApp->translate( "QTabBar", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QTabBar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    QMetaEnum* enum_tbl = QMetaObject::new_metaenum( 1 );
    enum_tbl[0].name = "Shape";
    enum_tbl[0].count = 4;
    enum_tbl[0].items = QMetaObject::new_metaenum_item( 4 );
    enum_tbl[0].set = FALSE;
    enum_tbl[0].items[0].key = "RoundedAbove";
    enum_tbl[0].items[0].value = (int) QTabBar::RoundedAbove;
    enum_tbl[0].items[1].key = "RoundedBelow";
    enum_tbl[0].items[1].value = (int) QTabBar::RoundedBelow;
    enum_tbl[0].items[2].key = "TriangularAbove";
    enum_tbl[0].items[2].value = (int) QTabBar::TriangularAbove;
    enum_tbl[0].items[3].key = "TriangularBelow";
    enum_tbl[0].items[3].value = (int) QTabBar::TriangularBelow;
#endif // QT_NO_PROPERTIES
#ifndef QT_NO_PROPERTIES
    typedef Shape (QTabBar::*m3_t0)()const;
    typedef Shape (QObject::*om3_t0)()const;
    typedef void (QTabBar::*m3_t1)(Shape);
    typedef void (QObject::*om3_t1)(Shape);
    typedef int (QTabBar::*m3_t3)()const;
    typedef int (QObject::*om3_t3)()const;
    typedef void (QTabBar::*m3_t4)(int);
    typedef void (QObject::*om3_t4)(int);
    typedef int (QTabBar::*m3_t6)()const;
    typedef int (QObject::*om3_t6)()const;
    typedef int (QTabBar::*m3_t9)()const;
    typedef int (QObject::*om3_t9)()const;
    m3_t0 v3_0 = &QTabBar::shape;
    om3_t0 ov3_0 = (om3_t0)v3_0;
    m3_t1 v3_1 = &QTabBar::setShape;
    om3_t1 ov3_1 = (om3_t1)v3_1;
    m3_t3 v3_3 = &QTabBar::currentTab;
    om3_t3 ov3_3 = (om3_t3)v3_3;
    m3_t4 v3_4 = &QTabBar::setCurrentTab;
    om3_t4 ov3_4 = (om3_t4)v3_4;
    m3_t6 v3_6 = &QTabBar::count;
    om3_t6 ov3_6 = (om3_t6)v3_6;
    m3_t9 v3_9 = &QTabBar::keyboardFocusTab;
    om3_t9 ov3_9 = (om3_t9)v3_9;
    QMetaProperty *props_tbl = QMetaObject::new_metaproperty( 4 );
    props_tbl[0].t = "Shape";
    props_tbl[0].n = "shape";
    props_tbl[0].get = (QMember)ov3_0;
    props_tbl[0].set = (QMember)ov3_1;
    props_tbl[0].reset = 0;
    props_tbl[0].gspec = QMetaProperty::Class;
    props_tbl[0].sspec = QMetaProperty::Class;
    props_tbl[0].enumData = &enum_tbl[0];
    props_tbl[0].setFlags(QMetaProperty::StdSet);
    props_tbl[1].t = "int";
    props_tbl[1].n = "currentTab";
    props_tbl[1].get = (QMember)ov3_3;
    props_tbl[1].set = (QMember)ov3_4;
    props_tbl[1].reset = 0;
    props_tbl[1].gspec = QMetaProperty::Class;
    props_tbl[1].sspec = QMetaProperty::Class;
    props_tbl[1].setFlags(QMetaProperty::StdSet);
    props_tbl[2].t = "int";
    props_tbl[2].n = "count";
    props_tbl[2].get = (QMember)ov3_6;
    props_tbl[2].set = 0;
    props_tbl[2].reset = 0;
    props_tbl[2].gspec = QMetaProperty::Class;
    props_tbl[2].sspec = QMetaProperty::Unspecified;
    props_tbl[3].t = "int";
    props_tbl[3].n = "keyboardFocusTab";
    props_tbl[3].get = (QMember)ov3_9;
    props_tbl[3].set = 0;
    props_tbl[3].reset = 0;
    props_tbl[3].gspec = QMetaProperty::Class;
    props_tbl[3].sspec = QMetaProperty::Unspecified;
#endif // QT_NO_PROPERTIES
    typedef void (QTabBar::*m1_t0)(int);
    typedef void (QObject::*om1_t0)(int);
    typedef void (QTabBar::*m1_t1)(QTab*);
    typedef void (QObject::*om1_t1)(QTab*);
    typedef void (QTabBar::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    m1_t0 v1_0 = &QTabBar::setCurrentTab;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &QTabBar::setCurrentTab;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &QTabBar::scrollTabs;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    QMetaData *slot_tbl = QMetaObject::new_metadata(3);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(3);
    slot_tbl[0].name = "setCurrentTab(int)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "setCurrentTab(QTab*)";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "scrollTabs()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Private;
    typedef void (QTabBar::*m2_t0)(int);
    typedef void (QObject::*om2_t0)(int);
    m2_t0 v2_0 = &QTabBar::selected;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "selected(int)";
    signal_tbl[0].ptr = (QMember)ov2_0;
    metaObj = QMetaObject::new_metaobject(
	"QTabBar", "QWidget",
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 4,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

// SIGNAL selected
void QTabBar::selected( int t0 )
{
    activate_signal( "selected(int)", t0 );
}
