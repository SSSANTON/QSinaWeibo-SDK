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

#ifndef QSINAWEIBOAUTHORIZEWIDGET_H
#define QSINAWEIBOAUTHORIZEWIDGET_H

#include <QtGui/QWidget>
#include <QtCore/QUrl>

QT_FORWARD_DECLARE_CLASS(QWebView)

class QSinaWeiboAuthorizeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QSinaWeiboAuthorizeWidget(QWidget *parent = 0);
    
    void loadUrl(const QString &url);

signals:
    void requestAccessToken(const QString &code);
    
public slots:
    void showAuthorizeWidget();
    void hideAuthorizeWidget();

private slots:
    void onUrlChanged(const QUrl &url);

private:
    QWebView *m_webView;
};

#endif // QSINAWEIBOAUTHORIZEWIDGET_H
