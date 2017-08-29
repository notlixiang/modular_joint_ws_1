/****************************************************************************
** Meta object code from reading C++ file 'qnode.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/hardWare/hardWare_setting/include/hardWare_setting/qnode.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnode.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_hardWare_setting__CDownToUp_Listen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   35,   35,   35, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_hardWare_setting__CDownToUp_Listen[] = {
    "hardWare_setting::CDownToUp_Listen\0\0"
    "rosShutdown()\0"
};

void hardWare_setting::CDownToUp_Listen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDownToUp_Listen *_t = static_cast<CDownToUp_Listen *>(_o);
        switch (_id) {
        case 0: _t->rosShutdown(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData hardWare_setting::CDownToUp_Listen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject hardWare_setting::CDownToUp_Listen::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_hardWare_setting__CDownToUp_Listen,
      qt_meta_data_hardWare_setting__CDownToUp_Listen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &hardWare_setting::CDownToUp_Listen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *hardWare_setting::CDownToUp_Listen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *hardWare_setting::CDownToUp_Listen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_hardWare_setting__CDownToUp_Listen))
        return static_cast<void*>(const_cast< CDownToUp_Listen*>(this));
    return QThread::qt_metacast(_clname);
}

int hardWare_setting::CDownToUp_Listen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void hardWare_setting::CDownToUp_Listen::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_hardWare_setting__CUpToDown[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_hardWare_setting__CUpToDown[] = {
    "hardWare_setting::CUpToDown\0\0rosShutdown()\0"
};

void hardWare_setting::CUpToDown::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CUpToDown *_t = static_cast<CUpToDown *>(_o);
        switch (_id) {
        case 0: _t->rosShutdown(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData hardWare_setting::CUpToDown::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject hardWare_setting::CUpToDown::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_hardWare_setting__CUpToDown,
      qt_meta_data_hardWare_setting__CUpToDown, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &hardWare_setting::CUpToDown::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *hardWare_setting::CUpToDown::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *hardWare_setting::CUpToDown::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_hardWare_setting__CUpToDown))
        return static_cast<void*>(const_cast< CUpToDown*>(this));
    return QThread::qt_metacast(_clname);
}

int hardWare_setting::CUpToDown::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void hardWare_setting::CUpToDown::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
