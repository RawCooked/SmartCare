/****************************************************************************
** Meta object code from reading C++ file 'RptFieldObject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../projet - Copie/SmartCare/QtRptProject/QtRPT/RptFieldObject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RptFieldObject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RptFieldObject_t {
    QByteArrayData data[21];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RptFieldObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RptFieldObject_t qt_meta_stringdata_RptFieldObject = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RptFieldObject"
QT_MOC_LITERAL(1, 15, 5), // "recNo"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "setVisible"
QT_MOC_LITERAL(4, 33, 5), // "value"
QT_MOC_LITERAL(5, 39, 8), // "setWidth"
QT_MOC_LITERAL(6, 48, 8), // "getWidth"
QT_MOC_LITERAL(7, 57, 9), // "setHeight"
QT_MOC_LITERAL(8, 67, 9), // "getHeight"
QT_MOC_LITERAL(9, 77, 6), // "setTop"
QT_MOC_LITERAL(10, 84, 6), // "getTop"
QT_MOC_LITERAL(11, 91, 7), // "setLeft"
QT_MOC_LITERAL(12, 99, 7), // "getLeft"
QT_MOC_LITERAL(13, 107, 5), // "width"
QT_MOC_LITERAL(14, 113, 6), // "height"
QT_MOC_LITERAL(15, 120, 3), // "top"
QT_MOC_LITERAL(16, 124, 4), // "left"
QT_MOC_LITERAL(17, 129, 7), // "visible"
QT_MOC_LITERAL(18, 137, 6), // "rotate"
QT_MOC_LITERAL(19, 144, 9), // "fontColor"
QT_MOC_LITERAL(20, 154, 15) // "backgroundColor"

    },
    "RptFieldObject\0recNo\0\0setVisible\0value\0"
    "setWidth\0getWidth\0setHeight\0getHeight\0"
    "setTop\0getTop\0setLeft\0getLeft\0width\0"
    "height\0top\0left\0visible\0rotate\0fontColor\0"
    "backgroundColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RptFieldObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       9,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x02 /* Public */,
       3,    1,   65,    2, 0x02 /* Public */,
       5,    1,   68,    2, 0x02 /* Public */,
       6,    0,   71,    2, 0x02 /* Public */,
       7,    1,   72,    2, 0x02 /* Public */,
       8,    0,   75,    2, 0x02 /* Public */,
       9,    1,   76,    2, 0x02 /* Public */,
      10,    0,   79,    2, 0x02 /* Public */,
      11,    1,   80,    2, 0x02 /* Public */,
      12,    0,   83,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Int,

 // properties: name, type, flags
       4, QMetaType::QString, 0x00095003,
      13, QMetaType::Int, 0x00095103,
      14, QMetaType::Int, 0x00095103,
      15, QMetaType::Int, 0x00095103,
      16, QMetaType::Int, 0x00095103,
      17, QMetaType::Bool, 0x00095003,
      18, QMetaType::Int, 0x00095003,
      19, QMetaType::QColor, 0x00095003,
      20, QMetaType::QColor, 0x00095003,

       0        // eod
};

void RptFieldObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RptFieldObject *_t = static_cast<RptFieldObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->recNo();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { int _r = _t->getWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: { int _r = _t->getHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setTop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: { int _r = _t->getTop();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: { int _r = _t->getLeft();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        RptFieldObject *_t = static_cast<RptFieldObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->value; break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getWidth(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getHeight(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getTop(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getLeft(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->m_visible; break;
        case 6: *reinterpret_cast< int*>(_v) = _t->rotate; break;
        case 7: *reinterpret_cast< QColor*>(_v) = _t->fontColor; break;
        case 8: *reinterpret_cast< QColor*>(_v) = _t->backgroundColor; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        RptFieldObject *_t = static_cast<RptFieldObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->value != *reinterpret_cast< QString*>(_v)) {
                _t->value = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 1: _t->setWidth(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setHeight(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setTop(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setLeft(*reinterpret_cast< int*>(_v)); break;
        case 5:
            if (_t->m_visible != *reinterpret_cast< bool*>(_v)) {
                _t->m_visible = *reinterpret_cast< bool*>(_v);
            }
            break;
        case 6:
            if (_t->rotate != *reinterpret_cast< int*>(_v)) {
                _t->rotate = *reinterpret_cast< int*>(_v);
            }
            break;
        case 7:
            if (_t->fontColor != *reinterpret_cast< QColor*>(_v)) {
                _t->fontColor = *reinterpret_cast< QColor*>(_v);
            }
            break;
        case 8:
            if (_t->backgroundColor != *reinterpret_cast< QColor*>(_v)) {
                _t->backgroundColor = *reinterpret_cast< QColor*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject RptFieldObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RptFieldObject.data,
      qt_meta_data_RptFieldObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RptFieldObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RptFieldObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RptFieldObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RptFieldObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
