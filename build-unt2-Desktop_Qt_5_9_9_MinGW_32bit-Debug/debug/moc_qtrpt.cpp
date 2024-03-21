/****************************************************************************
** Meta object code from reading C++ file 'qtrpt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../projet - Copie/SmartCare/QtRptProject/QtRPT/qtrpt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtrpt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtRPT_t {
    QByteArrayData data[31];
    char stringdata0[300];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtRPT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtRPT_t qt_meta_stringdata_QtRPT = {
    {
QT_MOC_LITERAL(0, 0, 5), // "QtRPT"
QT_MOC_LITERAL(1, 6, 8), // "setValue"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 5), // "recNo"
QT_MOC_LITERAL(4, 22, 9), // "paramName"
QT_MOC_LITERAL(5, 32, 9), // "QVariant&"
QT_MOC_LITERAL(6, 42, 10), // "paramValue"
QT_MOC_LITERAL(7, 53, 10), // "reportPage"
QT_MOC_LITERAL(8, 64, 8), // "setField"
QT_MOC_LITERAL(9, 73, 15), // "RptFieldObject&"
QT_MOC_LITERAL(10, 89, 11), // "fieldObject"
QT_MOC_LITERAL(11, 101, 13), // "setValueImage"
QT_MOC_LITERAL(12, 115, 7), // "QImage&"
QT_MOC_LITERAL(13, 123, 15), // "setValueDiagram"
QT_MOC_LITERAL(14, 139, 14), // "GraphDataList&"
QT_MOC_LITERAL(15, 154, 4), // "data"
QT_MOC_LITERAL(16, 159, 8), // "setChart"
QT_MOC_LITERAL(17, 168, 7), // "QChart&"
QT_MOC_LITERAL(18, 176, 5), // "chart"
QT_MOC_LITERAL(19, 182, 7), // "newPage"
QT_MOC_LITERAL(20, 190, 4), // "page"
QT_MOC_LITERAL(21, 195, 9), // "setDSInfo"
QT_MOC_LITERAL(22, 205, 12), // "DataSetInfo&"
QT_MOC_LITERAL(23, 218, 6), // "dsInfo"
QT_MOC_LITERAL(24, 225, 16), // "previewDestroyed"
QT_MOC_LITERAL(25, 242, 12), // "printPreview"
QT_MOC_LITERAL(26, 255, 9), // "QPrinter*"
QT_MOC_LITERAL(27, 265, 7), // "printer"
QT_MOC_LITERAL(28, 273, 8), // "exportTo"
QT_MOC_LITERAL(29, 282, 8), // "pageList"
QT_MOC_LITERAL(30, 291, 8) // "PageList"

    },
    "QtRPT\0setValue\0\0recNo\0paramName\0"
    "QVariant&\0paramValue\0reportPage\0"
    "setField\0RptFieldObject&\0fieldObject\0"
    "setValueImage\0QImage&\0setValueDiagram\0"
    "GraphDataList&\0data\0setChart\0QChart&\0"
    "chart\0newPage\0page\0setDSInfo\0DataSetInfo&\0"
    "dsInfo\0previewDestroyed\0printPreview\0"
    "QPrinter*\0printer\0exportTo\0pageList\0"
    "PageList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtRPT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       1,  104, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   64,    2, 0x06 /* Public */,
       8,    1,   73,    2, 0x06 /* Public */,
      11,    4,   76,    2, 0x06 /* Public */,
      13,    1,   85,    2, 0x06 /* Public */,
      16,    2,   88,    2, 0x06 /* Public */,
      19,    1,   93,    2, 0x06 /* Public */,
      21,    1,   96,    2, 0x06 /* Public */,
      24,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    1,  100,    2, 0x0a /* Public */,
      28,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 5, QMetaType::Int,    3,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 12, QMetaType::Int,    3,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 17,   10,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void,

 // properties: name, type, flags
      29, 0x80000000 | 30, 0x0009500b,

       0        // eod
};

void QtRPT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtRPT *_t = static_cast<QtRPT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setValue((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 1: _t->setField((*reinterpret_cast< RptFieldObject(*)>(_a[1]))); break;
        case 2: _t->setValueImage((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QImage(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 3: _t->setValueDiagram((*reinterpret_cast< GraphDataList(*)>(_a[1]))); break;
        case 4: _t->setChart((*reinterpret_cast< RptFieldObject(*)>(_a[1])),(*reinterpret_cast< QChart(*)>(_a[2]))); break;
        case 5: _t->newPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setDSInfo((*reinterpret_cast< DataSetInfo(*)>(_a[1]))); break;
        case 7: _t->previewDestroyed(); break;
        case 8: _t->printPreview((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 9: _t->exportTo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QtRPT::*_t)(const int , const QString , QVariant & , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtRPT::setValue)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QtRPT::*_t)(RptFieldObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtRPT::setField)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QtRPT::*_t)(const int , const QString , QImage & , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtRPT::setValueImage)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QtRPT::*_t)(GraphDataList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtRPT::setValueDiagram)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QtRPT::*_t)(RptFieldObject & , QChart & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtRPT::setChart)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QtRPT::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtRPT::newPage)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (QtRPT::*_t)(DataSetInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtRPT::setDSInfo)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (QtRPT::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtRPT::previewDestroyed)) {
                *result = 7;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PageList >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QtRPT *_t = static_cast<QtRPT *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< PageList*>(_v) = _t->pageList; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QtRPT *_t = static_cast<QtRPT *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->pageList != *reinterpret_cast< PageList*>(_v)) {
                _t->pageList = *reinterpret_cast< PageList*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QtRPT::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtRPT.data,
      qt_meta_data_QtRPT,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtRPT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtRPT::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtRPT.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtRPT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QtRPT::setValue(const int _t1, const QString _t2, QVariant & _t3, const int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtRPT::setField(RptFieldObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtRPT::setValueImage(const int _t1, const QString _t2, QImage & _t3, const int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtRPT::setValueDiagram(GraphDataList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QtRPT::setChart(RptFieldObject & _t1, QChart & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QtRPT::newPage(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QtRPT::setDSInfo(DataSetInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QtRPT::previewDestroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
