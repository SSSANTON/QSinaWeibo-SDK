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

#ifndef QSINAWEIBO_H
#define QSINAWEIBO_H

#include <QObject>

class QNetworkReply;
class QSinaWeiboRequest;
class QSinaWeiboRequestManager;

class QSinaWeibo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString loginUrl READ loginUrl)
    Q_PROPERTY(bool isLoggedIn READ isLoggedIn NOTIFY isLoggedInChanged)
    Q_PROPERTY(bool isAuthorizeExpired READ isAuthorizeExpired NOTIFY isAuthorizeExpiredChanged)
    //Q_PROPERTY(QString accessToken READ accessToken WRITE accessToken)

public:
    explicit QSinaWeibo(QObject *parent = 0);
    ~QSinaWeibo();

    //void login();
    //void logOut();

    QString loginUrl() const;

    bool isLoggedIn() const;
    bool isAuthorizeExpired() const;

    Q_INVOKABLE void requestAccessToken(const QString &authorizationCode);

    Q_INVOKABLE void getPublicTimeline(int count = 20);

    Q_INVOKABLE void getFriendsTimeline(qint64 sinceId,
                                        qint64 maxId,
                                        int count = 20,
                                        int page = 1,
                                        int baseApp = 0,
                                        int feature = 0,
                                        int trimeUser = 0);

    Q_INVOKABLE void getHomeTimeline(qint64 sinceId,
                                     qint64 maxId,
                                     int count = 20,
                                     int page = 1,
                                     int baseApp = 0,
                                     int feature = 0,
                                     int trimeUser = 0);

    //Q_INVOKABLE void get();
    Q_INVOKABLE void getFriendsTimelineIds(qint64 sinceId,
                                           qint64 maxId,
                                           int count = 20,
                                           int page = 1,
                                           int baseApp = 0,
                                           int feature = 0,
                                           int trimeUser = 0);

    Q_INVOKABLE void getUserTimeline(const QString &uid,
                                     const QString &screenName,
                                     qint64 sinceId,
                                     qint64 maxId,
                                     int count = 20,
                                     int page = 1,
                                     int baseApp = 0,
                                     int feature = 0,
                                     int trimeUser = 0);

    Q_INVOKABLE void getUserTimelineIds(const QString &uid,
                                     const QString &screenName,
                                     qint64 sinceId,
                                     qint64 maxId,
                                     int count = 20,
                                     int page = 1,
                                     int baseApp = 0,
                                     int feature = 0,
                                     int trimeUser = 0);
    Q_INVOKABLE void getRepostTimeline(qint64 id,
                                       qint64 sinceId,
                                       qint64 maxId,
                                       int count = 20,
                                       int page = 1,
                                       int baseApp = 0,
                                       int feature = 0,
                                       int trimeUser = 0);
signals:
    void isLoggedInChanged();
    void isAuthorizeExpiredChanged();
    
public slots:

private slots:
    void requestAccessTokenFinished();

private:
    QString m_loginUrl;

    bool m_isLoggedIn;
    bool m_isisAuthorizeExpired;

    //NetworkReply
    QNetworkReply *m_requestAccessTokenReply;
    QSinaWeiboRequest *m_sinaWebiboRequest;
    
};

#endif // QSINAWEIBO_H
