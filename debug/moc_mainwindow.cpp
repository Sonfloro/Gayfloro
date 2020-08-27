/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "disconnectBot"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "disconnectCH"
QT_MOC_LITERAL(4, 39, 17), // "sendCustomMessage"
QT_MOC_LITERAL(5, 57, 7), // "channel"
QT_MOC_LITERAL(6, 65, 7), // "message"
QT_MOC_LITERAL(7, 73, 6), // "addMod"
QT_MOC_LITERAL(8, 80, 3), // "mod"
QT_MOC_LITERAL(9, 84, 5), // "isMod"
QT_MOC_LITERAL(10, 90, 5), // "bool*"
QT_MOC_LITERAL(11, 96, 1), // "b"
QT_MOC_LITERAL(12, 98, 9), // "writePong"
QT_MOC_LITERAL(13, 108, 14), // "updateConsoles"
QT_MOC_LITERAL(14, 123, 8), // "readline"
QT_MOC_LITERAL(15, 132, 7), // "channle"
QT_MOC_LITERAL(16, 140, 6), // "sender"
QT_MOC_LITERAL(17, 147, 18), // "writeStatusMessage"
QT_MOC_LITERAL(18, 166, 21), // "on_chatButton_clicked"
QT_MOC_LITERAL(19, 188, 29), // "on_chatLineEdit_returnPressed"
QT_MOC_LITERAL(20, 218, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(21, 246, 5), // "index"
QT_MOC_LITERAL(22, 252, 18) // "updateDebugConsole"

    },
    "MainWindow\0disconnectBot\0\0disconnectCH\0"
    "sendCustomMessage\0channel\0message\0"
    "addMod\0mod\0isMod\0bool*\0b\0writePong\0"
    "updateConsoles\0readline\0channle\0sender\0"
    "writeStatusMessage\0on_chatButton_clicked\0"
    "on_chatLineEdit_returnPressed\0"
    "on_tabWidget_currentChanged\0index\0"
    "updateDebugConsole"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    2,   76,    2, 0x06 /* Public */,
       7,    2,   81,    2, 0x06 /* Public */,
       9,    3,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   93,    2, 0x08 /* Private */,
      13,    4,   94,    2, 0x08 /* Private */,
      17,    1,  103,    2, 0x08 /* Private */,
      18,    0,  106,    2, 0x08 /* Private */,
      19,    0,  107,    2, 0x08 /* Private */,
      20,    1,  108,    2, 0x08 /* Private */,
      22,    1,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    5,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, 0x80000000 | 10,    8,    5,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   15,   16,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disconnectBot(); break;
        case 1: _t->disconnectCH(); break;
        case 2: _t->sendCustomMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->addMod((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: { bool _r = _t->isMod((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->writePong(); break;
        case 6: _t->updateConsoles((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 7: _t->writeStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_chatButton_clicked(); break;
        case 9: _t->on_chatLineEdit_returnPressed(); break;
        case 10: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateDebugConsole((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::disconnectBot)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::disconnectCH)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendCustomMessage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::addMod)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = bool (MainWindow::*)(QString , QString , bool * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::isMod)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::disconnectBot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::disconnectCH()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::sendCustomMessage(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::addMod(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
bool MainWindow::isMod(QString _t1, QString _t2, bool * _t3)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
