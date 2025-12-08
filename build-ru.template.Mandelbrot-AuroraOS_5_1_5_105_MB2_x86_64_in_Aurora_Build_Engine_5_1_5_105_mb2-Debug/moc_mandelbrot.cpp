/****************************************************************************
** Meta object code from reading C++ file 'mandelbrot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Mandelbrot/src/mandelbrot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mandelbrot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Mandelbrot_t {
    QByteArrayData data[17];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mandelbrot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mandelbrot_t qt_meta_stringdata_Mandelbrot = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Mandelbrot"
QT_MOC_LITERAL(1, 11, 14), // "centerXChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "centerYChanged"
QT_MOC_LITERAL(4, 42, 12), // "scaleChanged"
QT_MOC_LITERAL(5, 55, 12), // "updatePixmap"
QT_MOC_LITERAL(6, 68, 5), // "image"
QT_MOC_LITERAL(7, 74, 11), // "scaleFactor"
QT_MOC_LITERAL(8, 86, 6), // "moveUp"
QT_MOC_LITERAL(9, 93, 8), // "moveDown"
QT_MOC_LITERAL(10, 102, 8), // "moveLeft"
QT_MOC_LITERAL(11, 111, 9), // "moveRight"
QT_MOC_LITERAL(12, 121, 6), // "zoomIn"
QT_MOC_LITERAL(13, 128, 7), // "zoomOut"
QT_MOC_LITERAL(14, 136, 7), // "centerX"
QT_MOC_LITERAL(15, 144, 7), // "centerY"
QT_MOC_LITERAL(16, 152, 5) // "scale"

    },
    "Mandelbrot\0centerXChanged\0\0centerYChanged\0"
    "scaleChanged\0updatePixmap\0image\0"
    "scaleFactor\0moveUp\0moveDown\0moveLeft\0"
    "moveRight\0zoomIn\0zoomOut\0centerX\0"
    "centerY\0scale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mandelbrot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       3,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   67,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       8,    0,   72,    2, 0x02 /* Public */,
       9,    0,   73,    2, 0x02 /* Public */,
      10,    0,   74,    2, 0x02 /* Public */,
      11,    0,   75,    2, 0x02 /* Public */,
      12,    0,   76,    2, 0x02 /* Public */,
      13,    0,   77,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::Double,    6,    7,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::Double, 0x00495103,
      15, QMetaType::Double, 0x00495103,
      16, QMetaType::Double, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void Mandelbrot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Mandelbrot *_t = static_cast<Mandelbrot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->centerXChanged(); break;
        case 1: _t->centerYChanged(); break;
        case 2: _t->scaleChanged(); break;
        case 3: _t->updatePixmap((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->moveUp(); break;
        case 5: _t->moveDown(); break;
        case 6: _t->moveLeft(); break;
        case 7: _t->moveRight(); break;
        case 8: _t->zoomIn(); break;
        case 9: _t->zoomOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Mandelbrot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Mandelbrot::centerXChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Mandelbrot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Mandelbrot::centerYChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Mandelbrot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Mandelbrot::scaleChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Mandelbrot *_t = static_cast<Mandelbrot *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->centerX(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->centerY(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->scale(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Mandelbrot *_t = static_cast<Mandelbrot *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCenterX(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setCenterY(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setScale(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Mandelbrot::staticMetaObject = {
    { &QQuickPaintedItem::staticMetaObject, qt_meta_stringdata_Mandelbrot.data,
      qt_meta_data_Mandelbrot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Mandelbrot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mandelbrot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Mandelbrot.stringdata0))
        return static_cast<void*>(const_cast< Mandelbrot*>(this));
    return QQuickPaintedItem::qt_metacast(_clname);
}

int Mandelbrot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
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
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Mandelbrot::centerXChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Mandelbrot::centerYChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Mandelbrot::scaleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
