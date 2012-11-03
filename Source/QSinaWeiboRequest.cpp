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

#include "QSinaWeiboRequest.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QHttpPart>
#include <QtNetwork/QHttpMultiPart>
#include <QtCore/QFile>
#include <QtCore/QDebug>

#include "QSinaWeiboRequestManager.h"

QSinaWeiboRequest::QSinaWeiboRequest(QObject *parent) :
    QObject(parent),
    m_reply(NULL)
{

}

QSinaWeiboRequest::~QSinaWeiboRequest()
{
    qDeleteAll(m_params);
}

/*
QNetworkReply *QSinaWeiboRequest::requestSinaWeiboAPI(const QString &url, const QString &httpMethod, const QMap<QString, QString> &params)
{
    QNetworkRequest req;
    QNetworkReply *reply;

    QString reqUrl = url + "?";

    QList< QString > keys = params.keys();
    foreach (QString key, keys) {
        reqUrl = reqUrl.append(key).append("=").append(params.value(key)).append("&");
    }
    reqUrl.chop(1);

    req.setUrl(QUrl(reqUrl));
    if ("Get" == httpMethod) {
         reply = m_networkAccessManager->get(req);
    }    
    else if ("Post" == httpMethod) {
        reply = m_networkAccessManager->post(req, QByteArray());
    }

    return reply;
}
*/

QNetworkReply *QSinaWeiboRequest::requestSinaWeiboByGet(const QString &url, const QMap<QString, QString> &params)
{
    /*
    QNetworkRequest req;
    QString reqUrl = url + "?";

    QList< QString > keys = params.keys();
    foreach (QString key, keys) {
        reqUrl = reqUrl.append(key).append("=").append(params.value(key)).append("&");
    }
    reqUrl.chop(1);

    req.setUrl(QUrl(reqUrl));
    QNetworkReply *reply = m_networkAccessManager->get(req);
    */
    return NULL;
}

QNetworkReply *QSinaWeiboRequest::requestSinaWeiboByPost(const QString &url, const QMap<QString, QPair<QString, QString> > &params)
{
    /*
    QNetworkRequest req;
    req.setUrl(url);

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QList< QString > keys = params.keys();
    foreach (QString key, keys) {
        QPair< QString, QString > valuePair = params.value(key);
        QString valueType = valuePair.first;
        QString value = valuePair.second;

        if ( "Var" == valueType ) {
            QHttpPart varPart;
            varPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"%1\"").arg(key)));
            varPart.setBody(value.toUtf8());
            multiPart->append(varPart);
        }
        else if ( "ImageFile" == valueType ) {
            QHttpPart imagePart;
            imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"%1\"").arg(key)));
            QFile *file = new QFile(value);
            file->open(QFile::ReadOnly);
            imagePart.setBodyDevice(file);
            file->setParent(multiPart);
            multiPart->append(imagePart);
        }
    }

    QNetworkReply *reply = m_networkAccessManager->post(req, multiPart);

    return reply;
    */
    return NULL;
}

QSinaWeiboRequest *QSinaWeiboRequest::createRequest(const QString &url, const QString &httpMethod, const QMap<QString, QObject *> &params)
{
    QSinaWeiboRequest *request = new QSinaWeiboRequest;
    request->setUrl(url);
    request->setHttpMethod(httpMethod);
    request->setParams(params);
    return request;
}

void QSinaWeiboRequest::send()
{
    QSinaWeiboRequestManager *requestManager = QSinaWeiboRequestManager::requetManager();
}

void QSinaWeiboRequest::cancel()
{
    disconnect(m_reply, SIGNAL(finished()), this,
               SLOT(finished()));
    m_reply->abort();
    m_reply->close();
    m_reply->deleteLater();
}

void QSinaWeiboRequest::setUrl(const QString &url)
{
    m_url = url;
}

void QSinaWeiboRequest::setHttpMethod(const QString &httpMehtod)
{
    m_httpMethod = httpMehtod;
}

void QSinaWeiboRequest::setParams(const QMap<QString, QObject *> &params)
{
    m_params = params;
}

void QSinaWeiboRequest::serializeURL()
{

}

void QSinaWeiboRequest::finished()
{

}

void QSinaWeiboRequest::error()
{
}
