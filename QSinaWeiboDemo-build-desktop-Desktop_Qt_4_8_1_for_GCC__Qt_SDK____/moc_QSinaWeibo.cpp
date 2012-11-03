/****************************************************************************
** Meta object code from reading C++ file 'QSinaWeibo.h'
**
** Created: Sun Oct 28 23:29:53 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Source/QSinaWeibo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSinaWeibo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSinaWeibo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       3,  224, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      32,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   11,   11,   11, 0x08,

 // methods: signature, parameters, type, tag, flags
     107,   89,   11,   11, 0x02,
     141,  135,   11,   11, 0x02,
     164,   11,   11,   11, 0x22,
     235,  184,   11,   11, 0x02,
     330,  289,   11,   11, 0x22,
     413,  380,   11,   11, 0x22,
     484,  459,   11,   11, 0x22,
     546,  526,   11,   11, 0x22,
     598,  584,   11,   11, 0x22,
     632,  184,   11,   11, 0x02,
     683,  289,   11,   11, 0x22,
     730,  380,   11,   11, 0x22,
     773,  459,   11,   11, 0x22,
     812,  526,   11,   11, 0x22,
     847,  584,   11,   11, 0x22,
     878,  184,   11,   11, 0x02,
     935,  289,   11,   11, 0x22,
     988,  380,   11,   11, 0x22,
    1037,  459,   11,   11, 0x22,
    1082,  526,   11,   11, 0x22,
    1123,  584,   11,   11, 0x22,
    1226, 1160,   11,   11, 0x02,
    1349, 1293,   11,   11, 0x22,
    1460, 1412,   11,   11, 0x22,
    1559, 1519,   11,   11, 0x22,
    1649, 1614,   11,   11, 0x22,
    1729, 1700,   11,   11, 0x22,
    1776, 1160,   11,   11, 0x02,
    1846, 1293,   11,   11, 0x22,
    1912, 1412,   11,   11, 0x22,
    1974, 1519,   11,   11, 0x22,
    2032, 1614,   11,   11, 0x22,
    2086, 1700,   11,   11, 0x22,
    2190, 2136,   11,   11, 0x02,
    2294, 2250,   11,   11, 0x22,
    2386, 2350,   11,   11, 0x22,
    2466, 2438,   11,   11, 0x22,
    2537, 2514,   11,   11, 0x22,
    2598, 2581,   11,   11, 0x22,

 // properties: name, type, flags
    2646, 2638, 0x0a095001,
    2660, 2655, 0x01495001,
    2671, 2655, 0x01495001,

 // properties: notify_signal_id
       0,
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_QSinaWeibo[] = {
    "QSinaWeibo\0\0isLoggedInChanged()\0"
    "isAuthorizeExpiredChanged()\0"
    "requestAccessTokenFinished()\0"
    "authorizationCode\0requestAccessToken(QString)\0"
    "count\0getPublicTimeline(int)\0"
    "getPublicTimeline()\0"
    "sinceId,maxId,count,page,baseApp,feature,trimeUser\0"
    "getFriendsTimeline(qint64,qint64,int,int,int,int,int)\0"
    "sinceId,maxId,count,page,baseApp,feature\0"
    "getFriendsTimeline(qint64,qint64,int,int,int,int)\0"
    "sinceId,maxId,count,page,baseApp\0"
    "getFriendsTimeline(qint64,qint64,int,int,int)\0"
    "sinceId,maxId,count,page\0"
    "getFriendsTimeline(qint64,qint64,int,int)\0"
    "sinceId,maxId,count\0"
    "getFriendsTimeline(qint64,qint64,int)\0"
    "sinceId,maxId\0getFriendsTimeline(qint64,qint64)\0"
    "getHomeTimeline(qint64,qint64,int,int,int,int,int)\0"
    "getHomeTimeline(qint64,qint64,int,int,int,int)\0"
    "getHomeTimeline(qint64,qint64,int,int,int)\0"
    "getHomeTimeline(qint64,qint64,int,int)\0"
    "getHomeTimeline(qint64,qint64,int)\0"
    "getHomeTimeline(qint64,qint64)\0"
    "getFriendsTimelineIds(qint64,qint64,int,int,int,int,int)\0"
    "getFriendsTimelineIds(qint64,qint64,int,int,int,int)\0"
    "getFriendsTimelineIds(qint64,qint64,int,int,int)\0"
    "getFriendsTimelineIds(qint64,qint64,int,int)\0"
    "getFriendsTimelineIds(qint64,qint64,int)\0"
    "getFriendsTimelineIds(qint64,qint64)\0"
    "uid,screenName,sinceId,maxId,count,page,baseApp,feature,trimeUser\0"
    "getUserTimeline(QString,QString,qint64,qint64,int,int,int,int,int)\0"
    "uid,screenName,sinceId,maxId,count,page,baseApp,feature\0"
    "getUserTimeline(QString,QString,qint64,qint64,int,int,int,int)\0"
    "uid,screenName,sinceId,maxId,count,page,baseApp\0"
    "getUserTimeline(QString,QString,qint64,qint64,int,int,int)\0"
    "uid,screenName,sinceId,maxId,count,page\0"
    "getUserTimeline(QString,QString,qint64,qint64,int,int)\0"
    "uid,screenName,sinceId,maxId,count\0"
    "getUserTimeline(QString,QString,qint64,qint64,int)\0"
    "uid,screenName,sinceId,maxId\0"
    "getUserTimeline(QString,QString,qint64,qint64)\0"
    "getUserTimelineIds(QString,QString,qint64,qint64,int,int,int,int,int)\0"
    "getUserTimelineIds(QString,QString,qint64,qint64,int,int,int,int)\0"
    "getUserTimelineIds(QString,QString,qint64,qint64,int,int,int)\0"
    "getUserTimelineIds(QString,QString,qint64,qint64,int,int)\0"
    "getUserTimelineIds(QString,QString,qint64,qint64,int)\0"
    "getUserTimelineIds(QString,QString,qint64,qint64)\0"
    "id,sinceId,maxId,count,page,baseApp,feature,trimeUser\0"
    "getRepostTimeline(qint64,qint64,qint64,int,int,int,int,int)\0"
    "id,sinceId,maxId,count,page,baseApp,feature\0"
    "getRepostTimeline(qint64,qint64,qint64,int,int,int,int)\0"
    "id,sinceId,maxId,count,page,baseApp\0"
    "getRepostTimeline(qint64,qint64,qint64,int,int,int)\0"
    "id,sinceId,maxId,count,page\0"
    "getRepostTimeline(qint64,qint64,qint64,int,int)\0"
    "id,sinceId,maxId,count\0"
    "getRepostTimeline(qint64,qint64,qint64,int)\0"
    "id,sinceId,maxId\0"
    "getRepostTimeline(qint64,qint64,qint64)\0"
    "QString\0loginUrl\0bool\0isLoggedIn\0"
    "isAuthorizeExpired\0"
};

void QSinaWeibo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSinaWeibo *_t = static_cast<QSinaWeibo *>(_o);
        switch (_id) {
        case 0: _t->isLoggedInChanged(); break;
        case 1: _t->isAuthorizeExpiredChanged(); break;
        case 2: _t->requestAccessTokenFinished(); break;
        case 3: _t->requestAccessToken((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->getPublicTimeline((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->getPublicTimeline(); break;
        case 6: _t->getFriendsTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 7: _t->getFriendsTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 8: _t->getFriendsTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 9: _t->getFriendsTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 10: _t->getFriendsTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->getFriendsTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 12: _t->getHomeTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 13: _t->getHomeTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 14: _t->getHomeTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 15: _t->getHomeTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 16: _t->getHomeTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 17: _t->getHomeTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 18: _t->getFriendsTimelineIds((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 19: _t->getFriendsTimelineIds((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 20: _t->getFriendsTimelineIds((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 21: _t->getFriendsTimelineIds((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 22: _t->getFriendsTimelineIds((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 23: _t->getFriendsTimelineIds((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 24: _t->getUserTimeline((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9]))); break;
        case 25: _t->getUserTimeline((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 26: _t->getUserTimeline((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 27: _t->getUserTimeline((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 28: _t->getUserTimeline((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 29: _t->getUserTimeline((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4]))); break;
        case 30: _t->getUserTimelineIds((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9]))); break;
        case 31: _t->getUserTimelineIds((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 32: _t->getUserTimelineIds((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 33: _t->getUserTimelineIds((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 34: _t->getUserTimelineIds((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 35: _t->getUserTimelineIds((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4]))); break;
        case 36: _t->getRepostTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 37: _t->getRepostTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 38: _t->getRepostTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 39: _t->getRepostTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 40: _t->getRepostTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 41: _t->getRepostTimeline((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSinaWeibo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSinaWeibo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSinaWeibo,
      qt_meta_data_QSinaWeibo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSinaWeibo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSinaWeibo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSinaWeibo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSinaWeibo))
        return static_cast<void*>(const_cast< QSinaWeibo*>(this));
    return QObject::qt_metacast(_clname);
}

int QSinaWeibo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = loginUrl(); break;
        case 1: *reinterpret_cast< bool*>(_v) = isLoggedIn(); break;
        case 2: *reinterpret_cast< bool*>(_v) = isAuthorizeExpired(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
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
void QSinaWeibo::isLoggedInChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QSinaWeibo::isAuthorizeExpiredChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
