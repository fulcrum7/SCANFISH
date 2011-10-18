/****************************************************************************
** Meta object code from reading C++ file 'MessageEditor.h'
**
** Created: Wed Oct 19 00:30:47 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MessageEditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MessageEditor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x05,
      38,   14,   14,   14, 0x05,
      69,   52,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     108,   14,   14,   14, 0x08,
     124,   14,   14,   14, 0x08,
     145,   14,   14,   14, 0x08,
     157,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MessageEditor[] = {
    "MessageEditor\0\0k\0DLC_TextChanged(int)\0"
    "SendClicked()\0ID,DLC,DATA,time\0"
    "SendSig(QString,QString,QString,QTime)\0"
    "CommitClicked()\0EnableCommitButton()\0"
    "ChangeDLC()\0SendSigSl()\0"
};

const QMetaObject MessageEditor::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_MessageEditor,
      qt_meta_data_MessageEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MessageEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MessageEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MessageEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessageEditor))
        return static_cast<void*>(const_cast< MessageEditor*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int MessageEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: DLC_TextChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: SendClicked(); break;
        case 2: SendSig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QTime(*)>(_a[4]))); break;
        case 3: CommitClicked(); break;
        case 4: EnableCommitButton(); break;
        case 5: ChangeDLC(); break;
        case 6: SendSigSl(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MessageEditor::DLC_TextChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageEditor::SendClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MessageEditor::SendSig(QString _t1, QString _t2, QString _t3, QTime _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
