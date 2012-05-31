/****************************************************************************
** QListView meta object code from reading C++ file 'qlistview.h'
**
** Created: Mon Dec 19 19:09:01 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.10   edited 2005-01-24 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "qlistview.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QListView::className() const
{
    return "QListView";
}

QMetaObject *QListView::metaObj = 0;

#ifdef QWS
static class QListView_metaObj_Unloader {
public:
    ~QListView_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QListView" );
    }
} QListView_metaObj_unloader;
#endif

void QListView::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QScrollView::className(), "QScrollView") != 0 )
	badSuperclassWarning("QListView","QScrollView");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QListView::tr(const char* s)
{
    return qApp->translate( "QListView", s, 0 );
}

QString QListView::tr(const char* s, const char * c)
{
    return qApp->translate( "QListView", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QScrollView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    QMetaEnum* enum_tbl = QMetaObject::new_metaenum( 1 );
    enum_tbl[0].name = "SelectionMode";
    enum_tbl[0].count = 4;
    enum_tbl[0].items = QMetaObject::new_metaenum_item( 4 );
    enum_tbl[0].set = FALSE;
    enum_tbl[0].items[0].key = "Single";
    enum_tbl[0].items[0].value = (int) QListView::Single;
    enum_tbl[0].items[1].key = "Multi";
    enum_tbl[0].items[1].value = (int) QListView::Multi;
    enum_tbl[0].items[2].key = "Extended";
    enum_tbl[0].items[2].value = (int) QListView::Extended;
    enum_tbl[0].items[3].key = "NoSelection";
    enum_tbl[0].items[3].value = (int) QListView::NoSelection;
#endif // QT_NO_PROPERTIES
#ifndef QT_NO_PROPERTIES
    typedef int (QListView::*m3_t0)()const;
    typedef int (QObject::*om3_t0)()const;
    typedef bool (QListView::*m3_t3)()const;
    typedef bool (QObject::*om3_t3)()const;
    typedef void (QListView::*m3_t4)(bool);
    typedef void (QObject::*om3_t4)(bool);
    typedef SelectionMode (QListView::*m3_t6)()const;
    typedef SelectionMode (QObject::*om3_t6)()const;
    typedef void (QListView::*m3_t7)(SelectionMode);
    typedef void (QObject::*om3_t7)(SelectionMode);
    typedef int (QListView::*m3_t9)()const;
    typedef int (QObject::*om3_t9)()const;
    typedef bool (QListView::*m3_t12)()const;
    typedef bool (QObject::*om3_t12)()const;
    typedef void (QListView::*m3_t13)(bool);
    typedef void (QObject::*om3_t13)(bool);
    typedef bool (QListView::*m3_t15)()const;
    typedef bool (QObject::*om3_t15)()const;
    typedef void (QListView::*m3_t16)(bool);
    typedef void (QObject::*om3_t16)(bool);
    typedef int (QListView::*m3_t18)()const;
    typedef int (QObject::*om3_t18)()const;
    typedef void (QListView::*m3_t19)(int);
    typedef void (QObject::*om3_t19)(int);
    typedef bool (QListView::*m3_t21)()const;
    typedef bool (QObject::*om3_t21)()const;
    typedef void (QListView::*m3_t22)(bool);
    typedef void (QObject::*om3_t22)(bool);
    m3_t0 v3_0 = &QListView::columns;
    om3_t0 ov3_0 = (om3_t0)v3_0;
    m3_t3 v3_3 = &QListView::isMultiSelection;
    om3_t3 ov3_3 = (om3_t3)v3_3;
    m3_t4 v3_4 = &QListView::setMultiSelection;
    om3_t4 ov3_4 = (om3_t4)v3_4;
    m3_t6 v3_6 = &QListView::selectionMode;
    om3_t6 ov3_6 = (om3_t6)v3_6;
    m3_t7 v3_7 = &QListView::setSelectionMode;
    om3_t7 ov3_7 = (om3_t7)v3_7;
    m3_t9 v3_9 = &QListView::childCount;
    om3_t9 ov3_9 = (om3_t9)v3_9;
    m3_t12 v3_12 = &QListView::allColumnsShowFocus;
    om3_t12 ov3_12 = (om3_t12)v3_12;
    m3_t13 v3_13 = &QListView::setAllColumnsShowFocus;
    om3_t13 ov3_13 = (om3_t13)v3_13;
    m3_t15 v3_15 = &QListView::showSortIndicator;
    om3_t15 ov3_15 = (om3_t15)v3_15;
    m3_t16 v3_16 = &QListView::setShowSortIndicator;
    om3_t16 ov3_16 = (om3_t16)v3_16;
    m3_t18 v3_18 = &QListView::itemMargin;
    om3_t18 ov3_18 = (om3_t18)v3_18;
    m3_t19 v3_19 = &QListView::setItemMargin;
    om3_t19 ov3_19 = (om3_t19)v3_19;
    m3_t21 v3_21 = &QListView::rootIsDecorated;
    om3_t21 ov3_21 = (om3_t21)v3_21;
    m3_t22 v3_22 = &QListView::setRootIsDecorated;
    om3_t22 ov3_22 = (om3_t22)v3_22;
    QMetaProperty *props_tbl = QMetaObject::new_metaproperty( 8 );
    props_tbl[0].t = "int";
    props_tbl[0].n = "columns";
    props_tbl[0].get = (QMember)ov3_0;
    props_tbl[0].set = 0;
    props_tbl[0].reset = 0;
    props_tbl[0].gspec = QMetaProperty::Class;
    props_tbl[0].sspec = QMetaProperty::Unspecified;
    props_tbl[1].t = "bool";
    props_tbl[1].n = "multiSelection";
    props_tbl[1].get = (QMember)ov3_3;
    props_tbl[1].set = (QMember)ov3_4;
    props_tbl[1].reset = 0;
    props_tbl[1].gspec = QMetaProperty::Class;
    props_tbl[1].sspec = QMetaProperty::Class;
    props_tbl[1].setFlags(QMetaProperty::NotDesignable|QMetaProperty::StdSet);
    props_tbl[2].t = "SelectionMode";
    props_tbl[2].n = "selectionMode";
    props_tbl[2].get = (QMember)ov3_6;
    props_tbl[2].set = (QMember)ov3_7;
    props_tbl[2].reset = 0;
    props_tbl[2].gspec = QMetaProperty::Class;
    props_tbl[2].sspec = QMetaProperty::Class;
    props_tbl[2].enumData = &enum_tbl[0];
    props_tbl[2].setFlags(QMetaProperty::StdSet);
    props_tbl[3].t = "int";
    props_tbl[3].n = "childCount";
    props_tbl[3].get = (QMember)ov3_9;
    props_tbl[3].set = 0;
    props_tbl[3].reset = 0;
    props_tbl[3].gspec = QMetaProperty::Class;
    props_tbl[3].sspec = QMetaProperty::Unspecified;
    props_tbl[4].t = "bool";
    props_tbl[4].n = "allColumnsShowFocus";
    props_tbl[4].get = (QMember)ov3_12;
    props_tbl[4].set = (QMember)ov3_13;
    props_tbl[4].reset = 0;
    props_tbl[4].gspec = QMetaProperty::Class;
    props_tbl[4].sspec = QMetaProperty::Class;
    props_tbl[4].setFlags(QMetaProperty::StdSet);
    props_tbl[5].t = "bool";
    props_tbl[5].n = "showSortIndicator";
    props_tbl[5].get = (QMember)ov3_15;
    props_tbl[5].set = (QMember)ov3_16;
    props_tbl[5].reset = 0;
    props_tbl[5].gspec = QMetaProperty::Class;
    props_tbl[5].sspec = QMetaProperty::Class;
    props_tbl[5].setFlags(QMetaProperty::StdSet);
    props_tbl[6].t = "int";
    props_tbl[6].n = "itemMargin";
    props_tbl[6].get = (QMember)ov3_18;
    props_tbl[6].set = (QMember)ov3_19;
    props_tbl[6].reset = 0;
    props_tbl[6].gspec = QMetaProperty::Class;
    props_tbl[6].sspec = QMetaProperty::Class;
    props_tbl[6].setFlags(QMetaProperty::StdSet);
    props_tbl[7].t = "bool";
    props_tbl[7].n = "rootIsDecorated";
    props_tbl[7].get = (QMember)ov3_21;
    props_tbl[7].set = (QMember)ov3_22;
    props_tbl[7].reset = 0;
    props_tbl[7].gspec = QMetaProperty::Class;
    props_tbl[7].sspec = QMetaProperty::Class;
    props_tbl[7].setFlags(QMetaProperty::StdSet);
#endif // QT_NO_PROPERTIES
    typedef void (QListView::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (QListView::*m1_t1)(bool);
    typedef void (QObject::*om1_t1)(bool);
    typedef void (QListView::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    typedef void (QListView::*m1_t3)(int,int);
    typedef void (QObject::*om1_t3)(int,int);
    typedef void (QListView::*m1_t4)();
    typedef void (QObject::*om1_t4)();
    typedef void (QListView::*m1_t5)();
    typedef void (QObject::*om1_t5)();
    typedef void (QListView::*m1_t6)(int);
    typedef void (QObject::*om1_t6)(int);
    typedef void (QListView::*m1_t7)();
    typedef void (QObject::*om1_t7)();
    typedef void (QListView::*m1_t8)();
    typedef void (QObject::*om1_t8)();
    typedef void (QListView::*m1_t9)(int,int,int);
    typedef void (QObject::*om1_t9)(int,int,int);
    m1_t0 v1_0 = &QListView::invertSelection;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &QListView::selectAll;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &QListView::triggerUpdate;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &QListView::setContentsPos;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    m1_t4 v1_4 = &QListView::updateContents;
    om1_t4 ov1_4 = (om1_t4)v1_4;
    m1_t5 v1_5 = &QListView::doAutoScroll;
    om1_t5 ov1_5 = (om1_t5)v1_5;
    m1_t6 v1_6 = &QListView::changeSortColumn;
    om1_t6 ov1_6 = (om1_t6)v1_6;
    m1_t7 v1_7 = &QListView::updateDirtyItems;
    om1_t7 ov1_7 = (om1_t7)v1_7;
    m1_t8 v1_8 = &QListView::makeVisible;
    om1_t8 ov1_8 = (om1_t8)v1_8;
    m1_t9 v1_9 = &QListView::handleSizeChange;
    om1_t9 ov1_9 = (om1_t9)v1_9;
    QMetaData *slot_tbl = QMetaObject::new_metadata(10);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(10);
    slot_tbl[0].name = "invertSelection()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "selectAll(bool)";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "triggerUpdate()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "setContentsPos(int,int)";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "updateContents()";
    slot_tbl[4].ptr = (QMember)ov1_4;
    slot_tbl_access[4] = QMetaData::Protected;
    slot_tbl[5].name = "doAutoScroll()";
    slot_tbl[5].ptr = (QMember)ov1_5;
    slot_tbl_access[5] = QMetaData::Protected;
    slot_tbl[6].name = "changeSortColumn(int)";
    slot_tbl[6].ptr = (QMember)ov1_6;
    slot_tbl_access[6] = QMetaData::Private;
    slot_tbl[7].name = "updateDirtyItems()";
    slot_tbl[7].ptr = (QMember)ov1_7;
    slot_tbl_access[7] = QMetaData::Private;
    slot_tbl[8].name = "makeVisible()";
    slot_tbl[8].ptr = (QMember)ov1_8;
    slot_tbl_access[8] = QMetaData::Private;
    slot_tbl[9].name = "handleSizeChange(int,int,int)";
    slot_tbl[9].ptr = (QMember)ov1_9;
    slot_tbl_access[9] = QMetaData::Private;
    typedef void (QListView::*m2_t0)();
    typedef void (QObject::*om2_t0)();
    typedef void (QListView::*m2_t1)(QListViewItem*);
    typedef void (QObject::*om2_t1)(QListViewItem*);
    typedef void (QListView::*m2_t2)(QListViewItem*);
    typedef void (QObject::*om2_t2)(QListViewItem*);
    typedef void (QListView::*m2_t3)(QListViewItem*);
    typedef void (QObject::*om2_t3)(QListViewItem*);
    typedef void (QListView::*m2_t4)(QListViewItem*,const QPoint&,int);
    typedef void (QObject::*om2_t4)(QListViewItem*,const QPoint&,int);
    typedef void (QListView::*m2_t5)(QListViewItem*);
    typedef void (QObject::*om2_t5)(QListViewItem*);
    typedef void (QListView::*m2_t6)(QListViewItem*,const QPoint&,int);
    typedef void (QObject::*om2_t6)(QListViewItem*,const QPoint&,int);
    typedef void (QListView::*m2_t7)(QListViewItem*);
    typedef void (QObject::*om2_t7)(QListViewItem*);
    typedef void (QListView::*m2_t8)(QListViewItem*);
    typedef void (QObject::*om2_t8)(QListViewItem*);
    typedef void (QListView::*m2_t9)(QListViewItem*,const QPoint&,int);
    typedef void (QObject::*om2_t9)(QListViewItem*,const QPoint&,int);
    typedef void (QListView::*m2_t10)(QListViewItem*,const QPoint&,int);
    typedef void (QObject::*om2_t10)(QListViewItem*,const QPoint&,int);
    typedef void (QListView::*m2_t11)(int,QListViewItem*,const QPoint&,int);
    typedef void (QObject::*om2_t11)(int,QListViewItem*,const QPoint&,int);
    typedef void (QListView::*m2_t12)(int,QListViewItem*,const QPoint&,int);
    typedef void (QObject::*om2_t12)(int,QListViewItem*,const QPoint&,int);
    typedef void (QListView::*m2_t13)(QListViewItem*);
    typedef void (QObject::*om2_t13)(QListViewItem*);
    typedef void (QListView::*m2_t14)();
    typedef void (QObject::*om2_t14)();
    typedef void (QListView::*m2_t15)(QListViewItem*);
    typedef void (QObject::*om2_t15)(QListViewItem*);
    typedef void (QListView::*m2_t16)(QListViewItem*);
    typedef void (QObject::*om2_t16)(QListViewItem*);
    m2_t0 v2_0 = &QListView::selectionChanged;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    m2_t1 v2_1 = &QListView::selectionChanged;
    om2_t1 ov2_1 = (om2_t1)v2_1;
    m2_t2 v2_2 = &QListView::currentChanged;
    om2_t2 ov2_2 = (om2_t2)v2_2;
    m2_t3 v2_3 = &QListView::clicked;
    om2_t3 ov2_3 = (om2_t3)v2_3;
    m2_t4 v2_4 = &QListView::clicked;
    om2_t4 ov2_4 = (om2_t4)v2_4;
    m2_t5 v2_5 = &QListView::pressed;
    om2_t5 ov2_5 = (om2_t5)v2_5;
    m2_t6 v2_6 = &QListView::pressed;
    om2_t6 ov2_6 = (om2_t6)v2_6;
    m2_t7 v2_7 = &QListView::doubleClicked;
    om2_t7 ov2_7 = (om2_t7)v2_7;
    m2_t8 v2_8 = &QListView::returnPressed;
    om2_t8 ov2_8 = (om2_t8)v2_8;
    m2_t9 v2_9 = &QListView::rightButtonClicked;
    om2_t9 ov2_9 = (om2_t9)v2_9;
    m2_t10 v2_10 = &QListView::rightButtonPressed;
    om2_t10 ov2_10 = (om2_t10)v2_10;
    m2_t11 v2_11 = &QListView::mouseButtonPressed;
    om2_t11 ov2_11 = (om2_t11)v2_11;
    m2_t12 v2_12 = &QListView::mouseButtonClicked;
    om2_t12 ov2_12 = (om2_t12)v2_12;
    m2_t13 v2_13 = &QListView::onItem;
    om2_t13 ov2_13 = (om2_t13)v2_13;
    m2_t14 v2_14 = &QListView::onViewport;
    om2_t14 ov2_14 = (om2_t14)v2_14;
    m2_t15 v2_15 = &QListView::expanded;
    om2_t15 ov2_15 = (om2_t15)v2_15;
    m2_t16 v2_16 = &QListView::collapsed;
    om2_t16 ov2_16 = (om2_t16)v2_16;
    QMetaData *signal_tbl = QMetaObject::new_metadata(17);
    signal_tbl[0].name = "selectionChanged()";
    signal_tbl[0].ptr = (QMember)ov2_0;
    signal_tbl[1].name = "selectionChanged(QListViewItem*)";
    signal_tbl[1].ptr = (QMember)ov2_1;
    signal_tbl[2].name = "currentChanged(QListViewItem*)";
    signal_tbl[2].ptr = (QMember)ov2_2;
    signal_tbl[3].name = "clicked(QListViewItem*)";
    signal_tbl[3].ptr = (QMember)ov2_3;
    signal_tbl[4].name = "clicked(QListViewItem*,const QPoint&,int)";
    signal_tbl[4].ptr = (QMember)ov2_4;
    signal_tbl[5].name = "pressed(QListViewItem*)";
    signal_tbl[5].ptr = (QMember)ov2_5;
    signal_tbl[6].name = "pressed(QListViewItem*,const QPoint&,int)";
    signal_tbl[6].ptr = (QMember)ov2_6;
    signal_tbl[7].name = "doubleClicked(QListViewItem*)";
    signal_tbl[7].ptr = (QMember)ov2_7;
    signal_tbl[8].name = "returnPressed(QListViewItem*)";
    signal_tbl[8].ptr = (QMember)ov2_8;
    signal_tbl[9].name = "rightButtonClicked(QListViewItem*,const QPoint&,int)";
    signal_tbl[9].ptr = (QMember)ov2_9;
    signal_tbl[10].name = "rightButtonPressed(QListViewItem*,const QPoint&,int)";
    signal_tbl[10].ptr = (QMember)ov2_10;
    signal_tbl[11].name = "mouseButtonPressed(int,QListViewItem*,const QPoint&,int)";
    signal_tbl[11].ptr = (QMember)ov2_11;
    signal_tbl[12].name = "mouseButtonClicked(int,QListViewItem*,const QPoint&,int)";
    signal_tbl[12].ptr = (QMember)ov2_12;
    signal_tbl[13].name = "onItem(QListViewItem*)";
    signal_tbl[13].ptr = (QMember)ov2_13;
    signal_tbl[14].name = "onViewport()";
    signal_tbl[14].ptr = (QMember)ov2_14;
    signal_tbl[15].name = "expanded(QListViewItem*)";
    signal_tbl[15].ptr = (QMember)ov2_15;
    signal_tbl[16].name = "collapsed(QListViewItem*)";
    signal_tbl[16].ptr = (QMember)ov2_16;
    metaObj = QMetaObject::new_metaobject(
	"QListView", "QScrollView",
	slot_tbl, 10,
	signal_tbl, 17,
#ifndef QT_NO_PROPERTIES
	props_tbl, 8,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

// SIGNAL selectionChanged
void QListView::selectionChanged()
{
    activate_signal( "selectionChanged()" );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL selectionChanged
void QListView::selectionChanged( QListViewItem* t0 )
{
    // No builtin function for signal parameter type QListViewItem*
    QConnectionList *clist = receivers("selectionChanged(QListViewItem*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
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

// SIGNAL currentChanged
void QListView::currentChanged( QListViewItem* t0 )
{
    // No builtin function for signal parameter type QListViewItem*
    QConnectionList *clist = receivers("currentChanged(QListViewItem*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
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

// SIGNAL clicked
void QListView::clicked( QListViewItem* t0 )
{
    // No builtin function for signal parameter type QListViewItem*
    QConnectionList *clist = receivers("clicked(QListViewItem*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
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

// SIGNAL clicked
void QListView::clicked( QListViewItem* t0, const QPoint& t1, int t2 )
{
    // No builtin function for signal parameter type QListViewItem*,const QPoint&,int
    QConnectionList *clist = receivers("clicked(QListViewItem*,const QPoint&,int)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
    typedef void (QObject::*RT2)(QListViewItem*,const QPoint&);
    typedef void (QObject::*RT3)(QListViewItem*,const QPoint&,int);
    RT0 r0;
    RT1 r1;
    RT2 r2;
    RT3 r3;
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
	    case 2:
#ifdef Q_FP_CCAST_BROKEN
		r2 = reinterpret_cast<RT2>(*(c->member()));
#else
		r2 = (RT2)*(c->member());
#endif
		(object->*r2)(t0, t1);
		break;
	    case 3:
#ifdef Q_FP_CCAST_BROKEN
		r3 = reinterpret_cast<RT3>(*(c->member()));
#else
		r3 = (RT3)*(c->member());
#endif
		(object->*r3)(t0, t1, t2);
		break;
	}
    }
}

// SIGNAL pressed
void QListView::pressed( QListViewItem* t0 )
{
    // No builtin function for signal parameter type QListViewItem*
    QConnectionList *clist = receivers("pressed(QListViewItem*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
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

// SIGNAL pressed
void QListView::pressed( QListViewItem* t0, const QPoint& t1, int t2 )
{
    // No builtin function for signal parameter type QListViewItem*,const QPoint&,int
    QConnectionList *clist = receivers("pressed(QListViewItem*,const QPoint&,int)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
    typedef void (QObject::*RT2)(QListViewItem*,const QPoint&);
    typedef void (QObject::*RT3)(QListViewItem*,const QPoint&,int);
    RT0 r0;
    RT1 r1;
    RT2 r2;
    RT3 r3;
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
	    case 2:
#ifdef Q_FP_CCAST_BROKEN
		r2 = reinterpret_cast<RT2>(*(c->member()));
#else
		r2 = (RT2)*(c->member());
#endif
		(object->*r2)(t0, t1);
		break;
	    case 3:
#ifdef Q_FP_CCAST_BROKEN
		r3 = reinterpret_cast<RT3>(*(c->member()));
#else
		r3 = (RT3)*(c->member());
#endif
		(object->*r3)(t0, t1, t2);
		break;
	}
    }
}

// SIGNAL doubleClicked
void QListView::doubleClicked( QListViewItem* t0 )
{
    // No builtin function for signal parameter type QListViewItem*
    QConnectionList *clist = receivers("doubleClicked(QListViewItem*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
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

// SIGNAL returnPressed
void QListView::returnPressed( QListViewItem* t0 )
{
    // No builtin function for signal parameter type QListViewItem*
    QConnectionList *clist = receivers("returnPressed(QListViewItem*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
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

// SIGNAL rightButtonClicked
void QListView::rightButtonClicked( QListViewItem* t0, const QPoint& t1, int t2 )
{
    // No builtin function for signal parameter type QListViewItem*,const QPoint&,int
    QConnectionList *clist = receivers("rightButtonClicked(QListViewItem*,const QPoint&,int)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
    typedef void (QObject::*RT2)(QListViewItem*,const QPoint&);
    typedef void (QObject::*RT3)(QListViewItem*,const QPoint&,int);
    RT0 r0;
    RT1 r1;
    RT2 r2;
    RT3 r3;
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
	    case 2:
#ifdef Q_FP_CCAST_BROKEN
		r2 = reinterpret_cast<RT2>(*(c->member()));
#else
		r2 = (RT2)*(c->member());
#endif
		(object->*r2)(t0, t1);
		break;
	    case 3:
#ifdef Q_FP_CCAST_BROKEN
		r3 = reinterpret_cast<RT3>(*(c->member()));
#else
		r3 = (RT3)*(c->member());
#endif
		(object->*r3)(t0, t1, t2);
		break;
	}
    }
}

// SIGNAL rightButtonPressed
void QListView::rightButtonPressed( QListViewItem* t0, const QPoint& t1, int t2 )
{
    // No builtin function for signal parameter type QListViewItem*,const QPoint&,int
    QConnectionList *clist = receivers("rightButtonPressed(QListViewItem*,const QPoint&,int)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
    typedef void (QObject::*RT2)(QListViewItem*,const QPoint&);
    typedef void (QObject::*RT3)(QListViewItem*,const QPoint&,int);
    RT0 r0;
    RT1 r1;
    RT2 r2;
    RT3 r3;
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
	    case 2:
#ifdef Q_FP_CCAST_BROKEN
		r2 = reinterpret_cast<RT2>(*(c->member()));
#else
		r2 = (RT2)*(c->member());
#endif
		(object->*r2)(t0, t1);
		break;
	    case 3:
#ifdef Q_FP_CCAST_BROKEN
		r3 = reinterpret_cast<RT3>(*(c->member()));
#else
		r3 = (RT3)*(c->member());
#endif
		(object->*r3)(t0, t1, t2);
		break;
	}
    }
}

// SIGNAL mouseButtonPressed
void QListView::mouseButtonPressed( int t0, QListViewItem* t1, const QPoint& t2, int t3 )
{
    // No builtin function for signal parameter type int,QListViewItem*,const QPoint&,int
    QConnectionList *clist = receivers("mouseButtonPressed(int,QListViewItem*,const QPoint&,int)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(int);
    typedef void (QObject::*RT2)(int,QListViewItem*);
    typedef void (QObject::*RT3)(int,QListViewItem*,const QPoint&);
    typedef void (QObject::*RT4)(int,QListViewItem*,const QPoint&,int);
    RT0 r0;
    RT1 r1;
    RT2 r2;
    RT3 r3;
    RT4 r4;
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
	    case 2:
#ifdef Q_FP_CCAST_BROKEN
		r2 = reinterpret_cast<RT2>(*(c->member()));
#else
		r2 = (RT2)*(c->member());
#endif
		(object->*r2)(t0, t1);
		break;
	    case 3:
#ifdef Q_FP_CCAST_BROKEN
		r3 = reinterpret_cast<RT3>(*(c->member()));
#else
		r3 = (RT3)*(c->member());
#endif
		(object->*r3)(t0, t1, t2);
		break;
	    case 4:
#ifdef Q_FP_CCAST_BROKEN
		r4 = reinterpret_cast<RT4>(*(c->member()));
#else
		r4 = (RT4)*(c->member());
#endif
		(object->*r4)(t0, t1, t2, t3);
		break;
	}
    }
}

// SIGNAL mouseButtonClicked
void QListView::mouseButtonClicked( int t0, QListViewItem* t1, const QPoint& t2, int t3 )
{
    // No builtin function for signal parameter type int,QListViewItem*,const QPoint&,int
    QConnectionList *clist = receivers("mouseButtonClicked(int,QListViewItem*,const QPoint&,int)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(int);
    typedef void (QObject::*RT2)(int,QListViewItem*);
    typedef void (QObject::*RT3)(int,QListViewItem*,const QPoint&);
    typedef void (QObject::*RT4)(int,QListViewItem*,const QPoint&,int);
    RT0 r0;
    RT1 r1;
    RT2 r2;
    RT3 r3;
    RT4 r4;
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
	    case 2:
#ifdef Q_FP_CCAST_BROKEN
		r2 = reinterpret_cast<RT2>(*(c->member()));
#else
		r2 = (RT2)*(c->member());
#endif
		(object->*r2)(t0, t1);
		break;
	    case 3:
#ifdef Q_FP_CCAST_BROKEN
		r3 = reinterpret_cast<RT3>(*(c->member()));
#else
		r3 = (RT3)*(c->member());
#endif
		(object->*r3)(t0, t1, t2);
		break;
	    case 4:
#ifdef Q_FP_CCAST_BROKEN
		r4 = reinterpret_cast<RT4>(*(c->member()));
#else
		r4 = (RT4)*(c->member());
#endif
		(object->*r4)(t0, t1, t2, t3);
		break;
	}
    }
}

// SIGNAL onItem
void QListView::onItem( QListViewItem* t0 )
{
    // No builtin function for signal parameter type QListViewItem*
    QConnectionList *clist = receivers("onItem(QListViewItem*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
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

// SIGNAL onViewport
void QListView::onViewport()
{
    activate_signal( "onViewport()" );
}

// SIGNAL expanded
void QListView::expanded( QListViewItem* t0 )
{
    // No builtin function for signal parameter type QListViewItem*
    QConnectionList *clist = receivers("expanded(QListViewItem*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
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

// SIGNAL collapsed
void QListView::collapsed( QListViewItem* t0 )
{
    // No builtin function for signal parameter type QListViewItem*
    QConnectionList *clist = receivers("collapsed(QListViewItem*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(QListViewItem*);
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
