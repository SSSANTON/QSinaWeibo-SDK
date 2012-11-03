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

#include "QSinaWeiboRequest.h"

QSinaWeiboRequestManager *QSinaWeiboRequestManager::singleRequestManager = NULL;

QSinaWeiboRequestManager::QSinaWeiboRequestManager(QObject *parent) :
    QNetworkAccessManager(parent)
{
}

QSinaWeiboRequestManager::~QSinaWeiboRequestManager()
{
    qDeleteAll(m_requestsSet);
}

void QSinaWeiboRequestManager::init()
{
    m_mutex.lock();
    if (singleRequestManager == NULL) {
        singleRequestManager = new QSinaWeiboRequestManager;
    }
    m_mutex.unlock();
}

void QSinaWeiboRequestManager::destroy()
{
    m_mutex.lock();
    if (singleRequestManager) {
        delete singleRequestManager;
        singleRequestManager = NULL;
    }
    m_mutex.unlock();
}

void QSinaWeiboRequestManager::requestStarted(QSinaWeiboRequest *request)
{
    m_requestsSet.insert(request);
}

void QSinaWeiboRequestManager::requestFinished(QSinaWeiboRequest *request)
{
    m_requestsSet.remove(request);
    if (request) {
        delete request;
        request = NULL;
    }
}

QSinaWeiboRequestManager *QSinaWeiboRequestManager::requetManager()
{
    return singleRequestManager;
}
