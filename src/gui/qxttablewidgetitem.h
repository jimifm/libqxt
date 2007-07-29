/****************************************************************************
**
** Copyright (C) Qxt Foundation. Some rights reserved.
**
** This file is part of the QxtCore module of the Qt eXTension library
**
** This library is free software; you can redistribute it and/or modify it
** under the terms of th Common Public License, version 1.0, as published by
** IBM.
**
** This file is provided "AS IS", without WARRANTIES OR CONDITIONS OF ANY
** KIND, EITHER EXPRESS OR IMPLIED INCLUDING, WITHOUT LIMITATION, ANY
** WARRANTIES OR CONDITIONS OF TITLE, NON-INFRINGEMENT, MERCHANTABILITY OR
** FITNESS FOR A PARTICULAR PURPOSE. 
**
** You should have received a copy of the CPL along with this file.
** See the LICENSE file and the cpl1.0.txt file included with the source
** distribution for more information. If you did not receive a copy of the
** license, contact the Qxt Foundation.
** 
** <http://libqxt.sourceforge.net>  <libqxt@gmail.com>
**
****************************************************************************/
#ifndef QXTTABLEWIDGETITEM_H
#define QXTTABLEWIDGETITEM_H

#include <QTableWidgetItem>
#include "qxtnamespace.h"
#include "qxtglobal.h"

class QXT_GUI_EXPORT QxtTableWidgetItem : public QTableWidgetItem
{
public:
	explicit QxtTableWidgetItem(int type = Type);
	explicit QxtTableWidgetItem(const QString& text, int type = Type);
	explicit QxtTableWidgetItem(const QIcon& icon, const QString& text, int type = Type);
	explicit QxtTableWidgetItem(const QTableWidgetItem& other);
	virtual ~QxtTableWidgetItem();
	
	bool testFlag(Qt::ItemFlag flag) const;
	void setFlag(Qt::ItemFlag flag, bool enabled = true);
	
#ifndef QXT_DOXYGEN_RUN
	virtual void setData(int role, const QVariant& value);
#endif // QXT_DOXYGEN_RUN
};

#endif // QXTTABLEWIDGETITEM_H