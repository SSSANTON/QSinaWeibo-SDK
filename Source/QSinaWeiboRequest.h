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

#ifndef QSINAWEIBOREQUEST_H
#define QSINAWEIBOREQUEST_H

#include <QtCore/QObject>
#include <QtCore/QMap>
#include <QtCore/QPair>
#include <QtCore/QMutex>
#include <QtCore/QUrl>

QT_FORWARD_DECLARE_CLASS(QNetworkRequest)
QT_FORWARD_DECLARE_CLASS(QNetworkReply)
QT_FORWARD_DECLARE_CLASS(QHttpMultiPart)

class QSinaWeiboRequest : public QObject
{
    Q_OBJECT

public:
    explicit QSinaWeiboRequest(QObject *parent = 0);
    ~QSinaWeiboRequest();

    QNetworkReply *requestSinaWeiboByGet(const QString &url,
                                                const QMap<QString, QString> &params);
    QNetworkReply *requestSinaWeiboByPost(const QString &url,
                                                const QMap< QString, QPair< QString, QString > > &params);

    static QSinaWeiboRequest *createRequest(const QString &url,
                                            const QString &httpMethod,
                                            const QMap<QString, QObject *> &params);

    void send();
    void cancel();

    void setUrl(const QString &url);
    void setHttpMethod(const QString &httpMehtod);
    void setParams(const QMap<QString, QObject *> &params);

signals:
    void requestFinished(const QString &result);
    void requestFailed(const QString &error);

private slots:
    void error();
    void finished();

private:
    void serializeURL();

private:
    QString m_url;
    QString m_httpMethod;
    QMap<QString, QObject *> m_params;

    QNetworkReply *m_reply;
    QHttpMultiPart *multiPart;

    QString m_responseData;
};

#endif // QSINAWEIBOREQUEST_H
