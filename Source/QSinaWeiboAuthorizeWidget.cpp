/*  copyright 2012 -  cnnbboy@gmail.com (blog.cnnbboy.net)
  
    This file is part of Name.
    
    Name is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    Name is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
    
    You should have received a copy of the GNU Lesser General Public License
    along with Name. If not, see <http://www.gnu.org/licenses/>.
*/

#include "QSinaWeiboAuthorizeWidget.h"

#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include <QtGui/QHBoxLayout>
#include <QtWebKit/QWebView>
#include <QtCore/QPropertyAnimation>

#include <QtCore/QDebug>

QSinaWeiboAuthorizeWidget::QSinaWeiboAuthorizeWidget(QWidget *parent) :
    QWidget(parent)
{
    setWindowFlags(Qt::Popup);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    m_webView = new QWebView(this);
    layout->addWidget(m_webView);

    connect(m_webView, SIGNAL(urlChanged(const QUrl &)),
            SLOT(onUrlChanged(const QUrl &)));

}

void QSinaWeiboAuthorizeWidget::loadUrl(const QString &url)
{
    m_webView->load(QUrl(url));
}

void QSinaWeiboAuthorizeWidget::showAuthorizeWidget()
{
    QWidget *topLevelWidget = QApplication::activeWindow();

    setParent(topLevelWidget);

    QPoint startPoint = topLevelWidget->rect().center();
    QPoint endPoint = mapToParent(QPoint(20, 20));

    QSize endSize;
    endSize.setWidth(topLevelWidget->width() - 40);
    endSize.setHeight(topLevelWidget->height() - 40);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(400);
    animation->setStartValue(QRect(startPoint, QSize(0, 0)));
    animation->setEndValue(QRect(endPoint, endSize));
    animation->setEasingCurve(QEasingCurve::InBack);

    animation->start(QAbstractAnimation::DeleteWhenStopped);

    show();
}

void QSinaWeiboAuthorizeWidget::hideAuthorizeWidget()
{
    hide();
}

void QSinaWeiboAuthorizeWidget::onUrlChanged(const QUrl &url)
{
    QString code;
    QString urlStr = url.toString();

    if (urlStr.contains(QLatin1String("?code="))) {
        int index = urlStr.indexOf(QLatin1String("?code="));
        code = urlStr.mid(index + 6);
        emit requestAccessToken(code);
    }

}
