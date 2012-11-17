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

#include <QtCore/QObject>
#include <QtCore/QDateTime>

QT_FORWARD_DECLARE_CLASS(QNetworkReply)
QT_FORWARD_DECLARE_CLASS(QSinaWeiboRequest)
QT_FORWARD_DECLARE_CLASS(QSinaWeiboRequestParam)
QT_FORWARD_DECLARE_CLASS(QSinaWeiboRequestManager)
QT_FORWARD_DECLARE_CLASS(QSinaWeiboAuthorizeWidget)

class QSinaWeibo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString loginUrl READ loginUrl)
    Q_PROPERTY(bool isLoggedIn READ isLoggedIn)
    Q_PROPERTY(bool isAuthorizeExpired READ isAuthorizeExpired )
    Q_PROPERTY(QString userID READ userID WRITE setUserID NOTIFY userIDChanged)
    Q_PROPERTY(QString accessToken READ accessToken WRITE setAccessToken NOTIFY accessTokenChanged)
    Q_PROPERTY(QDateTime expirationDate READ expirationDate WRITE setExpirationDate NOTIFY expirationDateChanged)

public:
    explicit QSinaWeibo(const QString &appKey,
               const QString &appSecret,
               const QString &appRedirectURI,
               bool isMobile = true,
               QObject *parent = 0);
    ~QSinaWeibo();

    QString loginUrl() const;

    bool isAuthValid() const;
    bool isLoggedIn() const;
    bool isAuthorizeExpired() const;

    QString userID() const;
    void setUserID(const QString &userID);

    QString accessToken() const;
    void setAccessToken(const QString &accessToken);

    QDateTime expirationDate() const;
    void setExpirationDate(const QDateTime &expirationDate);

public slots:
    QSinaWeiboRequest *createSinaWeiboRequest(const QString &url,
                                            const QString &httpMethod,
                                            const QVariant &params);
    QSinaWeiboRequest *createSinaWeiboRequest(const QString &url,
                                              const QString &httpMethod,
                                              const QList<QSinaWeiboRequestParam *> &params);

    void requestAccessToken(const QString &code);

    void logIn();
    void logOut();

signals:
    void authorizeExpired();

    void userIDChanged();
    void accessTokenChanged();
    void expirationDateChanged();

    void loginSuccess(const QString &userID,
                      const QString &accessToken,
                      const QString &expirationDateString);

    void loginFailed();

    void logOutSuccess();

private slots:
    void requestAccessTokenFinished(const QString &tokenResult);

private:
    QString m_appKey;
    QString m_appSecret;
    QString m_appRedirectURI;

    bool m_isMobile;

    QString m_loginUrl;

    QString m_userID;
    QString m_accessToken;
    QDateTime m_expirationDate;

    bool m_isLoggedIn;
    bool m_isisAuthorizeExpired;

    QSinaWeiboAuthorizeWidget *m_sinaWeiboAuthorizeWidget;
};

#endif // QSINAWEIBO_H
