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

#include "QSinaWeibo.h"

#include <QtCore/QSettings>
#include <QtScript/QScriptEngine>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QDebug>

#include "QSinaWeiboConstants.h"
#include "QSinaWeiboRequest.h"
#include "QSinaWeiboRequestParam.h"
#include "QSinaWeiboRequestManager.h"
#include "QSinaWeiboAuthorizeWidget.h"

QSinaWeibo::QSinaWeibo(const QString &appKey, const QString &appSecret, const QString &appRedirectURI, bool isMobile, QObject *parent) :
    QObject(parent),
    m_appKey(appKey),
    m_appSecret(appSecret),
    m_appRedirectURI(appRedirectURI),
    m_isMobile(isMobile),
    m_sinaWeiboAuthorizeWidget(NULL)
{
    QSinaWeiboRequestManager::init();

    m_loginUrl = QString("%1?client_id=%2&response_type=%3&redirect_uri=%4").
            arg(QSinaWeiboWebAuthURL).
            arg(m_appKey).
            arg("code").
            arg(m_appRedirectURI);

    if (m_isMobile)
        m_loginUrl.append("&display=mobile");
}

QSinaWeibo::~QSinaWeibo()
{
    QSinaWeiboRequestManager::destroy();
}

QString QSinaWeibo::loginUrl() const
{
    return m_loginUrl;
}

bool QSinaWeibo::isAuthValid() const
{
    return isLoggedIn() && !isAuthorizeExpired();
}

bool QSinaWeibo::isLoggedIn() const
{
    return m_userID.isEmpty() && m_accessToken.isEmpty() && m_expirationDate.toString().isEmpty();
}

bool QSinaWeibo::isAuthorizeExpired() const
{
    return QDateTime::currentDateTime() > m_expirationDate;
}

QString QSinaWeibo::userID() const
{
    return m_userID;
}

void QSinaWeibo::setUserID(const QString &userID)
{
    m_userID = userID;
    emit userIDChanged();
}

QString QSinaWeibo::accessToken() const
{
    return m_accessToken;
}

void QSinaWeibo::setAccessToken(const QString &accessToken)
{
    m_accessToken = accessToken;
    emit accessTokenChanged();
}

QDateTime QSinaWeibo::expirationDate() const
{
    return m_expirationDate;
}

void QSinaWeibo::setExpirationDate(const QDateTime &expirationDate)
{
    m_expirationDate = expirationDate;
    emit expirationDateChanged();
}

void QSinaWeibo::logIn()
{
    m_sinaWeiboAuthorizeWidget = new QSinaWeiboAuthorizeWidget;
    connect(m_sinaWeiboAuthorizeWidget, SIGNAL(requestAccessToken(const QString &)),
            SLOT(requestAccessToken(const QString &)));

    m_sinaWeiboAuthorizeWidget->loadUrl(m_loginUrl);
    m_sinaWeiboAuthorizeWidget->showAuthorizeWidget();
}

void QSinaWeibo::logOut()
{
    m_userID = "";
    m_accessToken = "";
    m_expirationDate = QDateTime();
}

QSinaWeiboRequest *QSinaWeibo::createSinaWeiboRequest(const QString &url, const QString &httpMethod, const QVariant &params)
{
    if (!isAuthValid()) {
        emit authorizeExpired();
        return NULL;
    }

    QList<QSinaWeiboRequestParam *> paramsList;

    foreach (QVariant paramVar, params.toList()) {
        QMap<QString, QVariant> paramMap = paramVar.toMap();
        QSinaWeiboRequestParam *param = new QSinaWeiboRequestParam;

        param->setKey(paramMap.value("key").toString());
        param->setType(paramMap.value("type").toString());
        param->setValue(paramMap.value("value").toString());
    }

    QSinaWeiboRequestParam *param = new QSinaWeiboRequestParam;
    param->setKey("access_token");
    param->setType("Text");
    param->setValue(m_accessToken);

    return QSinaWeiboRequest::createRequest(url, httpMethod, paramsList);
}

QSinaWeiboRequest *QSinaWeibo::createSinaWeiboRequest(const QString &url, const QString &httpMethod, const QList<QSinaWeiboRequestParam *> &params)
{
    return QSinaWeiboRequest::createRequest(url, httpMethod, params);
}

void QSinaWeibo::requestAccessToken(const QString &code)
{
    qDebug() << "requestAccessToken";
    QList<QSinaWeiboRequestParam *> params;

    QSinaWeiboRequestParam *clientIdParam = new QSinaWeiboRequestParam;
    clientIdParam->setKey(QString("client_id"));
    clientIdParam->setType(QString(""));
    clientIdParam->setValue(m_appKey);
    params.append(clientIdParam);

    QSinaWeiboRequestParam *clientSecretParam = new QSinaWeiboRequestParam;
    clientSecretParam->setKey(QString("client_secret"));
    clientSecretParam->setType(QString(""));
    clientSecretParam->setValue(m_appSecret);
    params.append(clientSecretParam);

    QSinaWeiboRequestParam *grantTypeParam = new QSinaWeiboRequestParam;
    grantTypeParam->setKey(QString("grant_type"));
    grantTypeParam->setType(QString("Text"));
    grantTypeParam->setValue(QString("authorization_code"));
    params.append(grantTypeParam);

    QSinaWeiboRequestParam *redirectUriParam = new QSinaWeiboRequestParam;
    redirectUriParam->setKey(QString("redirect_uri"));
    redirectUriParam->setType(QString("Text"));
    redirectUriParam->setValue("https://api.weibo.com/oauth2/default.html");
    params.append(redirectUriParam);

    QSinaWeiboRequestParam *codeParam = new QSinaWeiboRequestParam;
    codeParam->setKey(QString("code"));
    codeParam->setType(QString("Text"));
    codeParam->setValue(code);
    params.append(codeParam);

    QSinaWeiboRequest *tokeRequest = QSinaWeiboRequest::createRequest(QSinaWeiboWebAccessTokenURL,
                                                                      QString("POST"),                                                                  params);
    connect(tokeRequest, SIGNAL(requestFinished(const QString&)),
            SLOT(requestAccessTokenFinished(const QString &)));
    tokeRequest->send();

}

void QSinaWeibo::requestAccessTokenFinished(const QString &tokenResult)
{
    QScriptValue sc;
    QScriptEngine engine;

    sc = engine.evaluate("(" + tokenResult + ")");

    m_userID = sc.property("uid").toString();
    m_accessToken = sc.property("access_token").toString();
    m_expirationDate = QDateTime::currentDateTime().addSecs(sc.property("expires_in").toInt32());

    qDebug() << "requestAccessTokenFinished" << m_userID << m_accessToken;
    emit loginSuccess(m_userID, m_accessToken, m_expirationDate.toString());
}
