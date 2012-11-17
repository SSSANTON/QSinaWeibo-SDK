QT += netwrok script webkit

HEADERS += \
    $$PWD/QSinaWeiboConstants.h \
    $$PWD/QSinaWeibo.h \
    $$PWD/QSinaWeiboRequest.h \
    $$PWD/QSinaWeiboRequestManager.h \
    $$PWD/QSinaWeiboRequestParam.h \
    ../Source/QSinaWeiboAuthorizeWidget.h

SOURCES += \
    $$PWD/QSinaWeibo.cpp \
    $$PWD/QSinaWeiboRequest.cpp \
    $$PWD/QSinaWeiboRequestManager.cpp \
    $$PWD/QSinaWeiboRequestParam.cpp \
    ../Source/QSinaWeiboAuthorizeWidget.cpp
