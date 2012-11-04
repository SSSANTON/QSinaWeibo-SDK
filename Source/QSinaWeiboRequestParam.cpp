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

#include "QSinaWeiboRequestParam.h"

QSinaWeiboRequestParam::QSinaWeiboRequestParam(QObject *parent) :
    QObject(parent)
{
}

QString QSinaWeiboRequestParam::key() const
{
    return m_key;
}

void QSinaWeiboRequestParam::setKey(const QString &key)
{
    m_key = key;
}

QString QSinaWeiboRequestParam::value() const
{
    return m_value;
}

void QSinaWeiboRequestParam::setValue(const QString &value)
{
    m_value = value;
}

QString QSinaWeiboRequestParam::type() const
{
    return m_type;
}

void QSinaWeiboRequestParam::setType(const QString &type)
{
    m_type = type;
}
