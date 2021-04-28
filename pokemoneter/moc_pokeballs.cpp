/****************************************************************************
** Meta object code from reading C++ file 'pokeballs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "pokeballs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pokeballs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pokeballs_t {
    QByteArrayData data[21];
    char stringdata0[330];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pokeballs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pokeballs_t qt_meta_stringdata_pokeballs = {
    {
QT_MOC_LITERAL(0, 0, 9), // "pokeballs"
QT_MOC_LITERAL(1, 10, 9), // "hideSlots"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "loadSlots"
QT_MOC_LITERAL(4, 31, 10), // "slotSelect"
QT_MOC_LITERAL(5, 42, 5), // "load0"
QT_MOC_LITERAL(6, 48, 9), // "imageName"
QT_MOC_LITERAL(7, 58, 5), // "load1"
QT_MOC_LITERAL(8, 64, 5), // "load2"
QT_MOC_LITERAL(9, 70, 5), // "load3"
QT_MOC_LITERAL(10, 76, 5), // "load4"
QT_MOC_LITERAL(11, 82, 5), // "load5"
QT_MOC_LITERAL(12, 88, 22), // "on_back_button_clicked"
QT_MOC_LITERAL(13, 111, 24), // "on_select_button_clicked"
QT_MOC_LITERAL(14, 136, 25), // "on_release_button_clicked"
QT_MOC_LITERAL(15, 162, 27), // "on_pokemon_button_1_clicked"
QT_MOC_LITERAL(16, 190, 27), // "on_pokemon_button_2_clicked"
QT_MOC_LITERAL(17, 218, 27), // "on_pokemon_button_3_clicked"
QT_MOC_LITERAL(18, 246, 27), // "on_pokemon_button_4_clicked"
QT_MOC_LITERAL(19, 274, 27), // "on_pokemon_button_5_clicked"
QT_MOC_LITERAL(20, 302, 27) // "on_pokemon_button_6_clicked"

    },
    "pokeballs\0hideSlots\0\0loadSlots\0"
    "slotSelect\0load0\0imageName\0load1\0load2\0"
    "load3\0load4\0load5\0on_back_button_clicked\0"
    "on_select_button_clicked\0"
    "on_release_button_clicked\0"
    "on_pokemon_button_1_clicked\0"
    "on_pokemon_button_2_clicked\0"
    "on_pokemon_button_3_clicked\0"
    "on_pokemon_button_4_clicked\0"
    "on_pokemon_button_5_clicked\0"
    "on_pokemon_button_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pokeballs[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    1,  100,    2, 0x08 /* Private */,
       5,    1,  103,    2, 0x08 /* Private */,
       7,    1,  106,    2, 0x08 /* Private */,
       8,    1,  109,    2, 0x08 /* Private */,
       9,    1,  112,    2, 0x08 /* Private */,
      10,    1,  115,    2, 0x08 /* Private */,
      11,    1,  118,    2, 0x08 /* Private */,
      12,    0,  121,    2, 0x08 /* Private */,
      13,    0,  122,    2, 0x08 /* Private */,
      14,    0,  123,    2, 0x08 /* Private */,
      15,    0,  124,    2, 0x08 /* Private */,
      16,    0,  125,    2, 0x08 /* Private */,
      17,    0,  126,    2, 0x08 /* Private */,
      18,    0,  127,    2, 0x08 /* Private */,
      19,    0,  128,    2, 0x08 /* Private */,
      20,    0,  129,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pokeballs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pokeballs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hideSlots(); break;
        case 1: _t->loadSlots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->load0((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->load1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->load2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->load3((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->load4((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->load5((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_back_button_clicked(); break;
        case 9: _t->on_select_button_clicked(); break;
        case 10: _t->on_release_button_clicked(); break;
        case 11: _t->on_pokemon_button_1_clicked(); break;
        case 12: _t->on_pokemon_button_2_clicked(); break;
        case 13: _t->on_pokemon_button_3_clicked(); break;
        case 14: _t->on_pokemon_button_4_clicked(); break;
        case 15: _t->on_pokemon_button_5_clicked(); break;
        case 16: _t->on_pokemon_button_6_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject pokeballs::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_pokeballs.data,
    qt_meta_data_pokeballs,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pokeballs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pokeballs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pokeballs.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int pokeballs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
