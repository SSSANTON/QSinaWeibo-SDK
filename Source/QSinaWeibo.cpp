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

QSinaWeibo::QSinaWeibo(QObject *parent) :
    QObject(parent)
{
    m_loginUrl = QString("%1?client_id=%2&response_type=%3&redirect_uri=%4&%5").
            arg(QSinaWeiboWebAuthURL).
            arg(QSinaWeiboAppKey).
            arg("code").
            arg(QSinaWeiBoAppRedirectURI).
            arg("display=mobile");

    m_sinaWebiboRequest = new QSinaWeiboRequest(this);
}

QSinaWeibo::~QSinaWeibo()
{
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
    QMap< QString, QPair<QString, QString> > params;
    params.insert(QString("client_id"), QPair<QString, QString>(QString("Var"), QString("")));
    //params["client_id"] = QPair("Var", QSinaWeiboAppKey);
    //params["client_secret"] = QPair("Var", QSinaWeiBoAppSecret);
    //params["grant_type"] = QPair("Var", "authorization_code");
    //params["redirect_uri"] = QPair("Var", QSinaWeiBoAppRedirectURI);
    //params["code"] = QPair("Var", authorizationCode);

    m_requestAccessTokenReply = m_sinaWebiboRequest->requestSinaWeiboByPost(QSinaWeiboWebAccessTokenURL,
                                                                       params);
    connect(m_requestAccessTokenReply, SIGNAL(finished()), SLOT(requestAccessTokenFinished()));
}

/*!
  * 返回最新的公共微博，返回结果非完全实时
  * @param count 单页返回的记录条数，最大不超过200，默认为20。
  *
  */
void QSinaWeibo::getPublicTimeline(int count)
{
    QMap<QString, QString> params;
}

/*!
  * 获取当前登录用户及其所关注用户的最新微博
  * @param sinceId 若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
  * @param maxId 若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
  * @param count 单页返回的记录条数，最大不超过100，默认为20。
  * @param page 返回结果的页码，默认为1。
  * @param baseApp 是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
  * @param feature 过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
  * @param trimeUser 返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0
  */
void QSinaWeibo::getFriendsTimeline(qint64 sinceId, qint64 maxId, int count, int page, int baseApp, int feature, int trimeUser)
{

}

/*!
  * 获取当前登录用户及其所关注用户的最新微博
  * @param sinceId 若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
  * @param maxId 若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
  * @param count 单页返回的记录条数，最大不超过100，默认为20。
  * @param page 返回结果的页码，默认为1。
  * @param baseApp 是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
  * @param feature 过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
  * @param trimeUser 返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0
  */
void QSinaWeibo::getHomeTimeline(qint64 sinceId, qint64 maxId, int count, int page, int baseApp, int feature, int trimeUser)
{
}

/*!
  * 获取当前登录用户及其所关注用户的最新微博的ID
  * @param sinceId 若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
  * @param maxId 若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
  * @param count 单页返回的记录条数，最大不超过100，默认为20。
  * @param page 返回结果的页码，默认为1。
  * @param baseApp 是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
  * @param feature 过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
  * @param trimeUser 返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0
  */
void QSinaWeibo::getFriendsTimelineIds(qint64 sinceId, qint64 maxId, int count, int page, int baseApp, int feature, int trimeUser)
{
}

/*!
  * 获取用户发布的微博
  * @param uid 需要查询的用户ID
  * @param screenName 需要查询的用户昵称。
  * @param sinceId 若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
  * @param maxId 若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
  * @param count 单页返回的记录条数，最大不超过100，默认为20。
  * @param page 返回结果的页码，默认为1。
  * @param baseApp 是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
  * @param feature 过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
  * @param trimeUser 返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0
  */
void QSinaWeibo::getUserTimeline(const QString &uid, const QString &screenName, qint64 sinceId, qint64 maxId, int count, int page, int baseApp, int feature, int trimeUser)
{
}

/*!
  * 获取用户发布的微博的ID
  * @param uid 需要查询的用户ID
  * @param screenName 需要查询的用户昵称。
  * @param sinceId 若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
  * @param maxId 若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
  * @param count 单页返回的记录条数，最大不超过100，默认为20。
  * @param page 返回结果的页码，默认为1。
  * @param baseApp 是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
  * @param feature 过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
  * @param trimeUser 返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0
  */
void QSinaWeibo::getUserTimelineIds(const QString &uid, const QString &screenName, qint64 sinceId, qint64 maxId, int count, int page, int baseApp, int feature, int trimeUser)
{
}

/*!
  * 获取指定微博的转发微博列表
  * @param id 需要查询的微博ID。
  * @param screenName 需要查询的用户昵称。
  * @param sinceId 若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
  * @param maxId 若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
  * @param count 单页返回的记录条数，最大不超过100，默认为20。
  * @param page 返回结果的页码，默认为1。
  * @param baseApp 是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
  * @param feature 过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
  * @param trimeUser 返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0
  */
void QSinaWeibo::getRepostTimeline(qint64 id, qint64 sinceId, qint64 maxId, int count, int page, int baseApp, int feature, int trimeUser)
{

}

void QSinaWeibo::requestAccessTokenFinished()
{
    QString res = m_requestAccessTokenReply->readAll();
    qDebug() << res;
}
