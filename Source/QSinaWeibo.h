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

QT_FORWARD_DECLARE_CLASS(QNetworkReply)
QT_FORWARD_DECLARE_CLASS(QSinaWeiboRequest)
QT_FORWARD_DECLARE_CLASS(QSinaWeiboRequestParam)
QT_FORWARD_DECLARE_CLASS(QSinaWeiboRequestManager)

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

public slots:
    void requestAccessToken(const QString &authorizationCode);

    QSinaWeiboRequest *createSinaWeiboRequest(const QString &url,
                                            const QString &httpMethod,
                                            const QVariant &params);
    QSinaWeiboRequest *createSinaWeiboRequest(const QString &url,
                                              const QString &httpMethod,
                                              const QList<QSinaWeiboRequestParam *> &params);

signals:
    void isLoggedInChanged();
    void isAuthorizeExpiredChanged();

private slots:
    void requestAccessTokenFinished(const QString &tokenResult);

private:
    QString m_loginUrl;

    bool m_isLoggedIn;
    bool m_isisAuthorizeExpired;

};

#endif // QSINAWEIBO_H
