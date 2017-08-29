/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../hardWare_setting/include/hardWare_setting/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_hardWare_setting__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x0a,
      50,   29,   29,   29, 0x0a,
      73,   29,   29,   29, 0x0a,
      98,   29,   29,   29, 0x0a,
     123,   29,   29,   29, 0x0a,
     151,   29,   29,   29, 0x0a,
     179,   29,   29,   29, 0x0a,
     202,   29,   29,   29, 0x0a,
     223,   29,   29,   29, 0x0a,
     242,   29,   29,   29, 0x0a,
     266,   29,   29,   29, 0x0a,
     293,   29,   29,   29, 0x0a,
     321,   29,   29,   29, 0x0a,
     347,   29,   29,   29, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_hardWare_setting__MainWindow[] = {
    "hardWare_setting::MainWindow\0\0"
    "handle_btn_update()\0handle_btn_modify_id()\0"
    "handle_btn_debug_speed()\0"
    "handle_btn_write_speed()\0"
    "handle_btn_debug_position()\0"
    "handle_btn_write_position()\0"
    "handle_combo_changed()\0handle_btn_save_id()\0"
    "handle_time1_out()\0handle_btn_test_speed()\0"
    "handle_btn_test_position()\0"
    "handle_btn_test_position2()\0"
    "handle_btn_test_current()\0"
    "handle_btn_data_display()\0"
};

void hardWare_setting::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->handle_btn_update(); break;
        case 1: _t->handle_btn_modify_id(); break;
        case 2: _t->handle_btn_debug_speed(); break;
        case 3: _t->handle_btn_write_speed(); break;
        case 4: _t->handle_btn_debug_position(); break;
        case 5: _t->handle_btn_write_position(); break;
        case 6: _t->handle_combo_changed(); break;
        case 7: _t->handle_btn_save_id(); break;
        case 8: _t->handle_time1_out(); break;
        case 9: _t->handle_btn_test_speed(); break;
        case 10: _t->handle_btn_test_position(); break;
        case 11: _t->handle_btn_test_position2(); break;
        case 12: _t->handle_btn_test_current(); break;
        case 13: _t->handle_btn_data_display(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData hardWare_setting::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject hardWare_setting::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_hardWare_setting__MainWindow,
      qt_meta_data_hardWare_setting__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &hardWare_setting::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *hardWare_setting::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *hardWare_setting::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_hardWare_setting__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int hardWare_setting::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
