/****************************************************************************
** Meta object code from reading C++ file 'commandhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../commandhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commandhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommandHandler_t {
    QByteArrayData data[24];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommandHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommandHandler_t qt_meta_stringdata_CommandHandler = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CommandHandler"
QT_MOC_LITERAL(1, 15, 11), // "sendMessage"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "channel"
QT_MOC_LITERAL(4, 36, 7), // "message"
QT_MOC_LITERAL(5, 44, 11), // "updateDelay"
QT_MOC_LITERAL(6, 56, 5), // "delay"
QT_MOC_LITERAL(7, 62, 14), // "deleteCHThread"
QT_MOC_LITERAL(8, 77, 18), // "updateDebugConsole"
QT_MOC_LITERAL(9, 96, 9), // "onMessage"
QT_MOC_LITERAL(10, 106, 6), // "sender"
QT_MOC_LITERAL(11, 113, 5), // "start"
QT_MOC_LITERAL(12, 119, 10), // "disconnect"
QT_MOC_LITERAL(13, 130, 20), // "onYouTubeAPIResponse"
QT_MOC_LITERAL(14, 151, 14), // "QNetworkReply*"
QT_MOC_LITERAL(15, 166, 5), // "reply"
QT_MOC_LITERAL(16, 172, 19), // "onTwitchAPIResponse"
QT_MOC_LITERAL(17, 192, 18), // "onJagexAPIResponse"
QT_MOC_LITERAL(18, 211, 15), // "updateTextFiles"
QT_MOC_LITERAL(19, 227, 6), // "addMod"
QT_MOC_LITERAL(20, 234, 3), // "mod"
QT_MOC_LITERAL(21, 238, 5), // "isMod"
QT_MOC_LITERAL(22, 244, 5), // "bool*"
QT_MOC_LITERAL(23, 250, 1) // "b"

    },
    "CommandHandler\0sendMessage\0\0channel\0"
    "message\0updateDelay\0delay\0deleteCHThread\0"
    "updateDebugConsole\0onMessage\0sender\0"
    "start\0disconnect\0onYouTubeAPIResponse\0"
    "QNetworkReply*\0reply\0onTwitchAPIResponse\0"
    "onJagexAPIResponse\0updateTextFiles\0"
    "addMod\0mod\0isMod\0bool*\0b"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    1,   89,    2, 0x06 /* Public */,
       7,    0,   92,    2, 0x06 /* Public */,
       8,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    3,   96,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    1,  105,    2, 0x08 /* Private */,
      16,    1,  108,    2, 0x08 /* Private */,
      17,    1,  111,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    2,  115,    2, 0x08 /* Private */,
      21,    3,  120,    2, 0x08 /* Private */,
      21,    2,  127,    2, 0x28 /* Private | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,   10,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   20,    3,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, 0x80000000 | 22,   10,    3,   23,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   10,    3,

       0        // eod
};

void CommandHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommandHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->updateDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->deleteCHThread(); break;
        case 3: _t->updateDebugConsole((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->start(); break;
        case 6: _t->disconnect(); break;
        case 7: _t->onYouTubeAPIResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 8: _t->onTwitchAPIResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 9: _t->onJagexAPIResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->updateTextFiles(); break;
        case 11: _t->addMod((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: { bool _r = _t->isMod((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->isMod((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CommandHandler::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandHandler::sendMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CommandHandler::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandHandler::updateDelay)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CommandHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandHandler::deleteCHThread)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CommandHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandHandler::updateDebugConsole)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommandHandler::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CommandHandler.data,
    qt_meta_data_CommandHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommandHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommandHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CommandHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CommandHandler::sendMessage(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommandHandler::updateDelay(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommandHandler::deleteCHThread()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CommandHandler::updateDebugConsole(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
