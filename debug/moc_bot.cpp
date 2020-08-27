/****************************************************************************
** Meta object code from reading C++ file 'bot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Bot_t {
    QByteArrayData data[20];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Bot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Bot_t qt_meta_stringdata_Bot = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Bot"
QT_MOC_LITERAL(1, 4, 9), // "onMessage"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 7), // "channle"
QT_MOC_LITERAL(4, 23, 6), // "sender"
QT_MOC_LITERAL(5, 30, 7), // "message"
QT_MOC_LITERAL(6, 38, 15), // "deleteBotThread"
QT_MOC_LITERAL(7, 54, 9), // "writePong"
QT_MOC_LITERAL(8, 64, 14), // "updateConsoles"
QT_MOC_LITERAL(9, 79, 8), // "readLine"
QT_MOC_LITERAL(10, 88, 7), // "channel"
QT_MOC_LITERAL(11, 96, 18), // "writeStatusMessage"
QT_MOC_LITERAL(12, 115, 9), // "readyRead"
QT_MOC_LITERAL(13, 125, 5), // "start"
QT_MOC_LITERAL(14, 131, 11), // "sendMessage"
QT_MOC_LITERAL(15, 143, 11), // "updateDelay"
QT_MOC_LITERAL(16, 155, 5), // "delay"
QT_MOC_LITERAL(17, 161, 10), // "disconnect"
QT_MOC_LITERAL(18, 172, 12), // "disconnected"
QT_MOC_LITERAL(19, 185, 5) // "error"

    },
    "Bot\0onMessage\0\0channle\0sender\0message\0"
    "deleteBotThread\0writePong\0updateConsoles\0"
    "readLine\0channel\0writeStatusMessage\0"
    "readyRead\0start\0sendMessage\0updateDelay\0"
    "delay\0disconnect\0disconnected\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bot[] = {

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
       1,    3,   74,    2, 0x06 /* Public */,
       6,    0,   81,    2, 0x06 /* Public */,
       7,    0,   82,    2, 0x06 /* Public */,
       8,    4,   83,    2, 0x06 /* Public */,
      11,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   95,    2, 0x0a /* Public */,
      13,    0,   96,    2, 0x0a /* Public */,
      14,    2,   97,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x0a /* Public */,
      17,    0,  105,    2, 0x0a /* Public */,
      18,    0,  106,    2, 0x0a /* Public */,
      19,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,    4,    5,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,    5,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Bot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Bot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->deleteBotThread(); break;
        case 2: _t->writePong(); break;
        case 3: _t->updateConsoles((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: _t->writeStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->readyRead(); break;
        case 6: _t->start(); break;
        case 7: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->updateDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->disconnect(); break;
        case 10: _t->disconnected(); break;
        case 11: _t->error(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Bot::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bot::onMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Bot::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bot::deleteBotThread)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Bot::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bot::writePong)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Bot::*)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bot::updateConsoles)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Bot::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bot::writeStatusMessage)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Bot::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Bot.data,
    qt_meta_data_Bot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Bot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Bot.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Bot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Bot::onMessage(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Bot::deleteBotThread()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Bot::writePong()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Bot::updateConsoles(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Bot::writeStatusMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
