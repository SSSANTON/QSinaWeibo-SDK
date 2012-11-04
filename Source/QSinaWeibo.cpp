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

#include <QtCore/QPair>
#include <QtCore/QMap>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QDebug>

#include "QSinaWeiboConstants.h"
#include "QSinaWeiboRequest.h"
#include "QSinaWeiboRequestParam.h"
#include "QSinaWeiboRequestManager.h"

QSinaWeibo::QSinaWeibo(QObject *parent) :
    QObject(parent)
{
    m_loginUrl = QString("%1?client_id=%2&response_type=%3&redirect_uri=%4&%5").
            arg(QSinaWeiboWebAuthURL).
            arg(QSinaWeiboAppKey).
            arg("code").
            arg(QSinaWeiBoAppRedirectURI).
            arg("display=mobile");

    QSinaWeiboRequestManager::init();
}

QSinaWeibo::~QSinaWeibo()
{
    QSinaWeiboRequestManager::destroy();
}

QString QSinaWeibo::loginUrl() const
{
    return m_loginUrl;
}

bool QSinaWeibo::isLoggedIn() const
{
    return false;
}

bool QSinaWeibo::isAuthorizeExpired() const
{
    return false;
}

void QSinaWeibo::requestAccessToken(const QString &authorizationCode)
{
    QList<QSinaWeiboRequestParam *> params;

    QSinaWeiboRequestParam *clientIdParam = new QSinaWeiboRequestParam;
    clientIdParam->setKey(QString("client_id"));
    clientIdParam->setType(QString(""));
    clientIdParam->setValue(QSinaWeiboAppKey);
    params.append(clientIdParam);

    QSinaWeiboRequestParam *clientSecretParam = new QSinaWeiboRequestParam;
    clientSecretParam->setKey(QString("client_secret"));
    clientSecretParam->setType(QString(""));
    clientSecretParam->setValue(QSinaWeiBoAppSecret);
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
    codeParam->setValue(authorizationCode);
    params.append(codeParam);

    QSinaWeiboRequest *tokeRequest = QSinaWeiboRequest::createRequest(QSinaWeiboWebAccessTokenURL,
                                                                      QString("POST"),
                                                                      params);
    connect(tokeRequest, SIGNAL(requestFinished(const QString&)),
            SLOT(requestAccessTokenFinished(const QString &)));
    tokeRequest->send();
}

QSinaWeiboRequest *QSinaWeibo::createSinaWeiboRequest(const QString &url, const QString &httpMethod, const QVariant &params)
{
    QList<QSinaWeiboRequestParam *> paramsList;

    foreach (QVariant paramVar, params.toList()) {
        QMap<QString, QVariant> paramMap = paramVar.toMap();
        QSinaWeiboRequestParam *param = new QSinaWeiboRequestParam;

        param->setKey(paramMap.value("key").toString());
        param->setType(paramMap.value("type").toString());
        param->setValue(paramMap.value("value").toString());
    }

    return QSinaWeiboRequest::createRequest(url, httpMethod, paramsList);
}

QSinaWeiboRequest *QSinaWeibo::createSinaWeiboRequest(const QString &url, const QString &httpMethod, const QList<QSinaWeiboRequestParam *> &params)
{
    return QSinaWeiboRequest::createRequest(url, httpMethod, params);
}

void QSinaWeibo::requestAccessTokenFinished(const QString &tokenResult)
{
    qDebug() << "requestAccessTokenFinished:" <<tokenResult;
}
