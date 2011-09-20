/****************************************************************************
** Meta object code from reading C++ file 'Transmit.h'
**
** Created: Tue Sep 20 03:02:50 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Transmit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Transmit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Transmit[] = {

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
      10,    9,    9,    9, 0x08,
      45,   28,    9,    9, 0x08,
      85,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Transmit[] = {
    "Transmit\0\0TransTableClear()\0"
    "ID,DLC,DATA,time\0"
    "SendSlot(QString,QString,QString,QTime)\0"
    "TransTableSave()\0"
};

const QMetaObject Transmit::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_Transmit,
      qt_meta_data_Transmit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Transmit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Transmit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Transmit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Transmit))
        return static_cast<void*>(const_cast< Transmit*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int Transmit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: TransTableClear(); break;
        case 1: SendSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QTime(*)>(_a[4]))); break;
        case 2: TransTableSave(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
