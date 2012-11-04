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

#ifndef QSINAWEIBOREQUESTMANAGER_H
#define QSINAWEIBOREQUESTMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QMutex>
#include <QtCore/QList>

QT_FORWARD_DECLARE_CLASS(QTimer)
QT_FORWARD_DECLARE_CLASS(QSinaWeiboRequest)

class QSinaWeiboRequestManager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    static void init();
    static void destroy();

    void requestStarted(QSinaWeiboRequest *request);
    void requestFinished(QSinaWeiboRequest *request);

    static QSinaWeiboRequestManager *requetManager();

private:
    explicit QSinaWeiboRequestManager(QObject *parent = 0);
    ~QSinaWeiboRequestManager();

private slots:
    void clearFinishedRequest();

private:
    static QSinaWeiboRequestManager *singleRequestManager;
    static QMutex mutex;
    QList<QSinaWeiboRequest *> m_requestList;
    QTimer *m_clearTimer;
};

#endif // QSINAWEIBOREQUESTMANAGER_H
