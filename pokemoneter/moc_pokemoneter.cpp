/****************************************************************************
** Meta object code from reading C++ file 'pokemoneter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "pokemoneter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pokemoneter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pokemoneter_t {
    QByteArrayData data[19];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pokemoneter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pokemoneter_t qt_meta_stringdata_Pokemoneter = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Pokemoneter"
QT_MOC_LITERAL(1, 12, 10), // "checkStage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "type"
QT_MOC_LITERAL(4, 29, 4), // "name"
QT_MOC_LITERAL(5, 34, 5), // "steps"
QT_MOC_LITERAL(6, 40, 3), // "set"
QT_MOC_LITERAL(7, 44, 13), // "currentPIndex"
QT_MOC_LITERAL(8, 58, 8), // "setImage"
QT_MOC_LITERAL(9, 67, 9), // "imageName"
QT_MOC_LITERAL(10, 77, 15), // "setNotification"
QT_MOC_LITERAL(11, 93, 5), // "stage"
QT_MOC_LITERAL(12, 99, 9), // "setButton"
QT_MOC_LITERAL(13, 109, 11), // "fileChanged"
QT_MOC_LITERAL(14, 121, 4), // "path"
QT_MOC_LITERAL(15, 126, 22), // "on_back_button_clicked"
QT_MOC_LITERAL(16, 149, 25), // "on_capture_button_clicked"
QT_MOC_LITERAL(17, 175, 26), // "on_pokeball_button_clicked"
QT_MOC_LITERAL(18, 202, 22) // "on_shop_button_clicked"

    },
    "Pokemoneter\0checkStage\0\0type\0name\0"
    "steps\0set\0currentPIndex\0setImage\0"
    "imageName\0setNotification\0stage\0"
    "setButton\0fileChanged\0path\0"
    "on_back_button_clicked\0on_capture_button_clicked\0"
    "on_pokeball_button_clicked\0"
    "on_shop_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pokemoneter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x08 /* Private */,
       6,    1,   71,    2, 0x08 /* Private */,
       8,    1,   74,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      13,    1,   83,    2, 0x08 /* Private */,
      15,    0,   86,    2, 0x08 /* Private */,
      16,    0,   87,    2, 0x08 /* Private */,
      17,    0,   88,    2, 0x08 /* Private */,
      18,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Pokemoneter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pokemoneter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->checkStage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setNotification((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->fileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_back_button_clicked(); break;
        case 7: _t->on_capture_button_clicked(); break;
        case 8: _t->on_pokeball_button_clicked(); break;
        case 9: _t->on_shop_button_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Pokemoneter::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Pokemoneter.data,
    qt_meta_data_Pokemoneter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Pokemoneter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pokemoneter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pokemoneter.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Pokemoneter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
