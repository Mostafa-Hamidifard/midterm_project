/****************************************************************************
** Meta object code from reading C++ file 'maze_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Maze/maze_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maze_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_maze_page_t {
    QByteArrayData data[9];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_maze_page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_maze_page_t qt_meta_stringdata_maze_page = {
    {
QT_MOC_LITERAL(0, 0, 9), // "maze_page"
QT_MOC_LITERAL(1, 10, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 17), // "on_pad_up_clicked"
QT_MOC_LITERAL(4, 53, 20), // "on_pad_right_clicked"
QT_MOC_LITERAL(5, 74, 19), // "on_pad_down_clicked"
QT_MOC_LITERAL(6, 94, 19), // "on_pad_left_clicked"
QT_MOC_LITERAL(7, 114, 18), // "on_btn_bfs_clicked"
QT_MOC_LITERAL(8, 133, 18) // "on_btn_dfs_clicked"

    },
    "maze_page\0on_pushButton_5_clicked\0\0"
    "on_pad_up_clicked\0on_pad_right_clicked\0"
    "on_pad_down_clicked\0on_pad_left_clicked\0"
    "on_btn_bfs_clicked\0on_btn_dfs_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_maze_page[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void maze_page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<maze_page *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_5_clicked(); break;
        case 1: _t->on_pad_up_clicked(); break;
        case 2: _t->on_pad_right_clicked(); break;
        case 3: _t->on_pad_down_clicked(); break;
        case 4: _t->on_pad_left_clicked(); break;
        case 5: _t->on_btn_bfs_clicked(); break;
        case 6: _t->on_btn_dfs_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject maze_page::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_maze_page.data,
    qt_meta_data_maze_page,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *maze_page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *maze_page::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_maze_page.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int maze_page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
