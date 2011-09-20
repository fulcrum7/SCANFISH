/****************************************************************************
** Meta object code from reading C++ file 'Receive.h'
**
** Created: Tue Sep 20 08:06:44 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Receive.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Receive.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Receive[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      42,   25,    8,    8, 0x08,
      77,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Receive[] = {
    "Receive\0\0RecTableClear()\0ID,DLC,DATA,time\0"
    "ReceiveSlot(int,int,QString,QTime)\0"
    "RecTableSave()\0"
};

const QMetaObject Receive::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_Receive,
      qt_meta_data_Receive, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Receive::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Receive::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Receive::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Receive))
        return static_cast<void*>(const_cast< Receive*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int Receive::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: RecTableClear(); break;
        case 1: ReceiveSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QTime(*)>(_a[4]))); break;
        case 2: RecTableSave(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
