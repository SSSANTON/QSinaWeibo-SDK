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

#ifndef QSINAWEIBOCONSTANTS_H
#define QSINAWEIBOCONSTANTS_H

#define QSinaWeiboAppKey             "3888915020"
#define QSinaWeiBoAppSecret          "5d76ceb511497b21fa5e00c618d73c47"
#define QSinaWeiBoAppRedirectURI     "https://api.weibo.com/oauth2/default.html"

#define QSinaWeiboSDKErrorDomain           "SinaWeiboSDKErrorDomain"
#define QSinaWeiboSDKErrorCodeKey          "SinaWeiboSDKErrorCodeKey"

#define QSinaWeiboSDKAPIDomain             "https://open.weibo.cn/2/"
#define QSinaWeiboSDKOAuth2APIDomain       "https://open.weibo.cn/2/oauth2/"
#define QSinaWeiboWebAuthURL               "https://open.weibo.cn/2/oauth2/authorize"
#define QSinaWeiboWebAccessTokenURL        "https://open.weibo.cn/2/oauth2/access_token"


typedef enum
{
    QSinaWeiboSDKErrorCodeParseError       = 200,
    QSinaWeiboSDKErrorCodeSSOParamsError   = 202
} SinaWeiboSDKErrorCode;


#endif // QSINAWEIBOCONSTANTS_H
