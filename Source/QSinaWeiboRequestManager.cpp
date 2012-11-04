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

#include "QSinaWeiboRequestManager.h"

#include <QtCore/QTimer>

#include "QSinaWeiboRequest.h"

QSinaWeiboRequestManager *QSinaWeiboRequestManager::singleRequestManager = NULL;
QMutex QSinaWeiboRequestManager::mutex;

QSinaWeiboRequestManager::QSinaWeiboRequestManager(QObject *parent) :
    QNetworkAccessManager(parent)
{
    m_clearTimer = new QTimer(this);
    m_clearTimer->setInterval(10 * 1000);
    connect(m_clearTimer, SIGNAL(timeout()),
            SLOT(clearFinishedRequest()));
    m_clearTimer->start();
}

QSinaWeiboRequestManager::~QSinaWeiboRequestManager()
{
    qDeleteAll(m_requestList);
}

void QSinaWeiboRequestManager::clearFinishedRequest()
{
    if (m_requestList.isEmpty())
        return ;

    int i = 5;

    while (i-- && !m_requestList.isEmpty()) {
        QSinaWeiboRequest *request = m_requestList.takeFirst();
        if (request->isFinished()) {
            delete request;
            request = NULL;
        }
        else {
            m_requestList.append(request);
        }
    }
}

void QSinaWeiboRequestManager::init()
{
    mutex.lock();
    if (singleRequestManager == NULL) {
        singleRequestManager = new QSinaWeiboRequestManager;
    }
    mutex.unlock();
}

void QSinaWeiboRequestManager::destroy()
{
    mutex.lock();
    if (singleRequestManager) {
        delete singleRequestManager;
        singleRequestManager = NULL;
    }
    mutex.unlock();
}

void QSinaWeiboRequestManager::requestStarted(QSinaWeiboRequest *request)
{
    m_requestList.append(request);
}

void QSinaWeiboRequestManager::requestFinished(QSinaWeiboRequest *request)
{
    m_requestList.removeOne(request);
    if (request) {
        delete request;
        request = NULL;
    }
}

QSinaWeiboRequestManager *QSinaWeiboRequestManager::requetManager()
{
    return singleRequestManager;
}
