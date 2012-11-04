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

#ifndef QSINAWEIBOREQUESTPARAM_H
#define QSINAWEIBOREQUESTPARAM_H

#include <QObject>

class QSinaWeiboRequestParam : public QObject
{
    Q_OBJECT
public:
    explicit QSinaWeiboRequestParam(QObject *parent = 0);

    QString key() const;
    void setKey(const QString &key);

    QString value() const;
    void setValue(const QString &value);

    QString type() const;
    void setType(const QString &type);

private:
    QString m_key;
    QString m_value;
    QString m_type;
    
};

#endif // QSINAWEIBOREQUESTPARAM_H
