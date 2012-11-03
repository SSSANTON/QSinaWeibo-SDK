QT += netwrok

HEADERS += \
    $$PWD/QSinaWeiboConstants.h \
    $$PWD/QSinaWeibo.h \
    $$PWD/QSinaWeiboRequest.h \
    ../Source/QSinaWeiboRequestManager.h

SOURCES += \
    $$PWD/QSinaWeibo.cpp \
    $$PWD/QSinaWeiboRequest.cpp \
    ../Source/QSinaWeiboRequestManager.cpp
