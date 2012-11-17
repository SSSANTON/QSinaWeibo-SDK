#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QDeclarativeEngine>
#include <QDeclarativeContext>
#include <QDebug>

#include "QSinaWeibo.h"

#define QSinaWeiboAppKey             "3888915020"
#define QSinaWeiBoAppSecret          "5d76ceb511497b21fa5e00c618d73c47"
#define QSinaWeiBoAppRedirectURI     "https://api.weibo.com/oauth2/default.html"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QSinaWeibo SinaWeibo(QSinaWeiboAppKey,
                         QSinaWeiBoAppSecret,
                         QSinaWeiBoAppRedirectURI);

    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("SinaWeibo", &SinaWeibo);
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/QSinaWeiboDemo/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
