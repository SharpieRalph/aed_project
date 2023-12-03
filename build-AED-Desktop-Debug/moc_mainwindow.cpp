/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AED/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "updatePatient"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "newPatient"
QT_MOC_LITERAL(4, 37, 11), // "updatePower"
QT_MOC_LITERAL(5, 49, 8), // "newPower"
QT_MOC_LITERAL(6, 58, 15), // "toggleActiveCPR"
QT_MOC_LITERAL(7, 74, 6), // "newCPR"
QT_MOC_LITERAL(8, 81, 10), // "updatePads"
QT_MOC_LITERAL(9, 92, 7), // "newPads"
QT_MOC_LITERAL(10, 100, 14), // "updateLCDTimer"
QT_MOC_LITERAL(11, 115, 7), // "lightOn"
QT_MOC_LITERAL(12, 123, 8), // "lightNum"
QT_MOC_LITERAL(13, 132, 8), // "lightOff"
QT_MOC_LITERAL(14, 141, 10), // "updateText"
QT_MOC_LITERAL(15, 152, 7), // "textNum"
QT_MOC_LITERAL(16, 160, 12), // "updateLCDImg"
QT_MOC_LITERAL(17, 173, 4), // "diag"
QT_MOC_LITERAL(18, 178, 24), // "on_shallowCPRBtn_clicked"
QT_MOC_LITERAL(19, 203, 7), // "checked"
QT_MOC_LITERAL(20, 211, 25), // "on_adequateCPRBtn_clicked"
QT_MOC_LITERAL(21, 237, 22), // "on_adultPadBtn_clicked"
QT_MOC_LITERAL(22, 260, 20) // "on_pedPadBtn_clicked"

    },
    "MainWindow\0updatePatient\0\0newPatient\0"
    "updatePower\0newPower\0toggleActiveCPR\0"
    "newCPR\0updatePads\0newPads\0updateLCDTimer\0"
    "lightOn\0lightNum\0lightOff\0updateText\0"
    "textNum\0updateLCDImg\0diag\0"
    "on_shallowCPRBtn_clicked\0checked\0"
    "on_adequateCPRBtn_clicked\0"
    "on_adultPadBtn_clicked\0on_pedPadBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    1,   82,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x08 /* Private */,
       8,    1,   88,    2, 0x08 /* Private */,
      10,    0,   91,    2, 0x08 /* Private */,
      11,    1,   92,    2, 0x08 /* Private */,
      13,    1,   95,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      16,    1,  101,    2, 0x08 /* Private */,
      18,    1,  104,    2, 0x08 /* Private */,
      20,    1,  107,    2, 0x08 /* Private */,
      21,    0,  110,    2, 0x08 /* Private */,
      22,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatePatient((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updatePower((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->toggleActiveCPR((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->updatePads((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateLCDTimer(); break;
        case 5: _t->lightOn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->lightOff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateText((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->updateLCDImg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_shallowCPRBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_adequateCPRBtn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_adultPadBtn_clicked(); break;
        case 12: _t->on_pedPadBtn_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
