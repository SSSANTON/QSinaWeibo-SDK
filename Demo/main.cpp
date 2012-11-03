#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QDeclarativeEngine>
#include <QDeclarativeContext>

#include "QSinaWeibo.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QSinaWeibo SinaWeibo;

    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("SinaWeibo", &SinaWeibo);
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/QSinaWeiboDemo/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
