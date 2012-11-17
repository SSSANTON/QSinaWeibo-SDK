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

#include "QSinaWeiboRequestParam.h"
#include "QSinaWeiboRequestManager.h"

QSinaWeiboRequest::QSinaWeiboRequest(QObject *parent) :
    QObject(parent),
    m_isFinished(false),
    m_reply(NULL)
{

}

QSinaWeiboRequest::~QSinaWeiboRequest()
{
    qDeleteAll(m_params);
}

QSinaWeiboRequest *QSinaWeiboRequest::createRequest(const QString &url, const QString &httpMethod, const QList<QSinaWeiboRequestParam *> &params)
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
    requestManager->requestStarted(this);

    m_isFinished = false;

    serializeURL();

    QNetworkRequest req;
    req.setUrl(QUrl(m_url));

    if ("GET" == m_httpMethod) {
        m_reply = requestManager->get(req);
    }
    else if ("POST" == m_httpMethod){
        serializeBodyData();
        //qDebug() << "post" << req.url().isValid() <<
        //            req.url().toString();
        m_reply = requestManager->post(req, m_httpMultiPart);
    }
    connect(m_reply, SIGNAL(finished()), this,
            SLOT(finished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this,
            SLOT(error()));
}

void QSinaWeiboRequest::cancel()
{
    disconnect(m_reply, SIGNAL(finished()), this,
               SLOT(finished()));
    m_reply->abort();
    m_reply->close();
    m_reply->deleteLater();
    m_isFinished = true;
}

void QSinaWeiboRequest::setUrl(const QString &url)
{
    m_url = url;
}

void QSinaWeiboRequest::setHttpMethod(const QString &httpMehtod)
{
    m_httpMethod = httpMehtod;
}

void QSinaWeiboRequest::setParams(const QList<QSinaWeiboRequestParam *> &params)
{
    m_params = params;
}

bool QSinaWeiboRequest::isFinished() const
{
    return m_isFinished;
}

void QSinaWeiboRequest::taskFinished()
{
    m_isFinished = true;
}

void QSinaWeiboRequest::serializeURL()
{
    m_url += "?";
    foreach (QSinaWeiboRequestParam *param, m_params) {
        if (param->type() == "Image") {
            if (m_httpMethod == "GET") {
                qDebug("can not use GET to upload a file");
            }
        }
        m_url += param->key();
        m_url += "=";
        m_url += param->value();
        m_url += "&";
    }
    m_url.chop(1);
    qDebug() << m_url;
}

void QSinaWeiboRequest::serializeBodyData()
{
    m_httpMultiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    foreach (QSinaWeiboRequestParam *param, m_params) {

        if (param->type() == "Data") {
            QHttpPart textPart;
            textPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain"));
            textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"%1\"").arg(param->key())));
            textPart.setBody(param->value().toUtf8());
            m_httpMultiPart->append(textPart);
        }
        else if (param->type() == "Image") {
            QHttpPart imagePart;
            imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
            imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"%1\"").arg(param->key())));
            QFile *file = new QFile(param->value());
            file->open(QFile::ReadOnly);
            imagePart.setBodyDevice(file);
            file->setParent(m_httpMultiPart);
            m_httpMultiPart->append(imagePart);
        }
    }

}

void QSinaWeiboRequest::finished()
{
    m_responseData = m_reply->readAll();
    emit requestFinished(m_responseData);
    m_isFinished = true;
}

void QSinaWeiboRequest::error()
{
    QString error = m_reply->errorString();
    emit requestFinished(error);
    m_isFinished = true;
}
