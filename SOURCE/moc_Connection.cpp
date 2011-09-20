/****************************************************************************
** Meta object code from reading C++ file 'Connection.h'
**
** Created: Tue Sep 20 08:06:48 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Connection.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Connection[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      21,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   11,   11,   11, 0x08,
      50,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Connection[] = {
    "Connection\0\0active()\0disactive()\0"
    "ConnectClicked()\0DisconnectClicked()\0"
    "EnableConnectButton()\0"
};

const QMetaObject Connection::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Connection,
      qt_meta_data_Connection, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Connection::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Connection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Connection))
        return static_cast<void*>(const_cast< Connection*>(this));
    return QWidget::qt_metacast(_clname);
}

int Connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: active(); break;
        case 1: disactive(); break;
        case 2: ConnectClicked(); break;
        case 3: DisconnectClicked(); break;
        case 4: EnableConnectButton(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Connection::active()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Connection::disactive()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
