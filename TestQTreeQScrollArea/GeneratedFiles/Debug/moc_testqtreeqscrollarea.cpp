/****************************************************************************
** Meta object code from reading C++ file 'testqtreeqscrollarea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testqtreeqscrollarea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testqtreeqscrollarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TestQTreeQScrollArea_t {
    QByteArrayData data[13];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestQTreeQScrollArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestQTreeQScrollArea_t qt_meta_stringdata_TestQTreeQScrollArea = {
    {
QT_MOC_LITERAL(0, 0, 20), // "TestQTreeQScrollArea"
QT_MOC_LITERAL(1, 21, 13), // "onItemClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 53, 4), // "item"
QT_MOC_LITERAL(5, 58, 6), // "column"
QT_MOC_LITERAL(6, 65, 24), // "onNetworkModeRadioButton"
QT_MOC_LITERAL(7, 90, 10), // "checkState"
QT_MOC_LITERAL(8, 101, 31), // "onSemiautomaticModelRadioButton"
QT_MOC_LITERAL(9, 133, 24), // "onManualModelRadioButton"
QT_MOC_LITERAL(10, 158, 12), // "initTitleBar"
QT_MOC_LITERAL(11, 171, 18), // "onButtonMinClicked"
QT_MOC_LITERAL(12, 190, 20) // "onButtonCloseClicked"

    },
    "TestQTreeQScrollArea\0onItemClicked\0\0"
    "QTreeWidgetItem*\0item\0column\0"
    "onNetworkModeRadioButton\0checkState\0"
    "onSemiautomaticModelRadioButton\0"
    "onManualModelRadioButton\0initTitleBar\0"
    "onButtonMinClicked\0onButtonCloseClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestQTreeQScrollArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x0a /* Public */,
       6,    1,   54,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,
       9,    1,   60,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,
      11,    0,   64,    2, 0x0a /* Public */,
      12,    0,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestQTreeQScrollArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestQTreeQScrollArea *_t = static_cast<TestQTreeQScrollArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->onNetworkModeRadioButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onSemiautomaticModelRadioButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onManualModelRadioButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->initTitleBar(); break;
        case 5: _t->onButtonMinClicked(); break;
        case 6: _t->onButtonCloseClicked(); break;
        default: ;
        }
    }
}

const QMetaObject TestQTreeQScrollArea::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestQTreeQScrollArea.data,
      qt_meta_data_TestQTreeQScrollArea,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TestQTreeQScrollArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestQTreeQScrollArea::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TestQTreeQScrollArea.stringdata0))
        return static_cast<void*>(const_cast< TestQTreeQScrollArea*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TestQTreeQScrollArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
