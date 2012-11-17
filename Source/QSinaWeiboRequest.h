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
#include <QtCore/QList>
#include <QtCore/QMutex>
#include <QtCore/QUrl>

QT_FORWARD_DECLARE_CLASS(QNetworkRequest)
QT_FORWARD_DECLARE_CLASS(QNetworkReply)
QT_FORWARD_DECLARE_CLASS(QHttpMultiPart)
QT_FORWARD_DECLARE_CLASS(QSinaWeiboRequestParam)

class QSinaWeiboRequest : public QObject
{
    Q_OBJECT

public:
    explicit QSinaWeiboRequest(QObject *parent = 0);
    ~QSinaWeiboRequest();

    static QSinaWeiboRequest *createRequest(const QString &url,
                                            const QString &httpMethod,
                                            const QList<QSinaWeiboRequestParam *> &params);

    void setUrl(const QString &url);
    void setHttpMethod(const QString &httpMehtod);
    void setParams(const QList<QSinaWeiboRequestParam *> &params);

    bool isFinished() const;

public slots:
    void send();
    void cancel();
    void taskFinished();

signals:
    void requestFinished(const QString &result);
    void requestFailed(const QString &error);

private slots:
    void error();
    void finished();

private:
    void serializeURL();
    void serializeBodyData();

private:
    bool m_isFinished;
    QString m_url;
    QString m_httpMethod;
    QList<QSinaWeiboRequestParam *> m_params;

    QNetworkReply *m_reply;
    QHttpMultiPart *m_httpMultiPart;

    QString m_responseData;
};

#endif // QSINAWEIBOREQUEST_H
