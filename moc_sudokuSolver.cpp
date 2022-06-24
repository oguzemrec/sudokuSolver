/****************************************************************************
** Meta object code from reading C++ file 'sudokuSolver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "sudokuSolver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sudokuSolver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sudokuSolver_t {
    QByteArrayData data[10];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sudokuSolver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sudokuSolver_t qt_meta_stringdata_sudokuSolver = {
    {
QT_MOC_LITERAL(0, 0, 12), // "sudokuSolver"
QT_MOC_LITERAL(1, 13, 13), // "solutionEvent"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "solutionRes"
QT_MOC_LITERAL(4, 40, 14), // "iterationCount"
QT_MOC_LITERAL(5, 55, 14), // "CellEntrAttemp"
QT_MOC_LITERAL(6, 70, 9), // "NOT_FOUND"
QT_MOC_LITERAL(7, 80, 11), // "EXIST_INROW"
QT_MOC_LITERAL(8, 92, 14), // "EXIST_INCOLUMN"
QT_MOC_LITERAL(9, 107, 11) // "EXIST_INBOX"

    },
    "sudokuSolver\0solutionEvent\0\0solutionRes\0"
    "iterationCount\0CellEntrAttemp\0NOT_FOUND\0"
    "EXIST_INROW\0EXIST_INCOLUMN\0EXIST_INBOX"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sudokuSolver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       1,   24, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    3,    4,

 // enums: name, alias, flags, count, data
       5,    5, 0x2,    4,   29,

 // enum data: key, value
       6, uint(sudokuSolver::CellEntrAttemp::NOT_FOUND),
       7, uint(sudokuSolver::CellEntrAttemp::EXIST_INROW),
       8, uint(sudokuSolver::CellEntrAttemp::EXIST_INCOLUMN),
       9, uint(sudokuSolver::CellEntrAttemp::EXIST_INBOX),

       0        // eod
};

void sudokuSolver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<sudokuSolver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->solutionEvent((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (sudokuSolver::*)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sudokuSolver::solutionEvent)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject sudokuSolver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_sudokuSolver.data,
    qt_meta_data_sudokuSolver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *sudokuSolver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sudokuSolver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sudokuSolver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int sudokuSolver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void sudokuSolver::solutionEvent(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
