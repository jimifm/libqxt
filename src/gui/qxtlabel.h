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
#ifndef QXTLABEL_H
#define QXTLABEL_H

#include <QFrame>
#include "qxtnamespace.h"
#include "qxtglobal.h"
#include "qxtpimpl.h"

class QxtLabelPrivate;

class QXT_GUI_EXPORT QxtLabel : public QFrame
{
	Q_OBJECT
	QXT_DECLARE_PRIVATE(QxtLabel);
	Q_PROPERTY(QString text READ text WRITE setText)
	Q_PROPERTY(Qt::Alignment alignment READ alignment WRITE setAlignment)
	Q_PROPERTY(Qt::TextElideMode elideMode READ elideMode WRITE setElideMode)
	Q_PROPERTY(Qxt::Rotation rotation READ rotation WRITE setRotation)
	
public:
	explicit QxtLabel(QWidget* parent = 0, Qt::WindowFlags flags = 0);
	explicit QxtLabel(const QString& text, QWidget* parent = 0, Qt::WindowFlags flags = 0);
	virtual ~QxtLabel();
	
	QString text() const;
	
	Qt::Alignment alignment() const;
	void setAlignment(Qt::Alignment alignment);
	
	Qt::TextElideMode elideMode() const;
	void setElideMode(Qt::TextElideMode mode);
	
	Qxt::Rotation rotation() const;
	void setRotation(Qxt::Rotation rotation);
	
#ifndef QXT_DOXYGEN_RUN
	virtual QSize sizeHint() const;
	virtual QSize minimumSizeHint() const;
#endif // QXT_DOXYGEN_RUN
	
public slots:
	void setText(const QString& text);
	
signals:
	void clicked();
	void textChanged(const QString& text);
	
#ifndef QXT_DOXYGEN_RUN
protected:
	virtual void changeEvent(QEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual void paintEvent(QPaintEvent* event);
#endif // QXT_DOXYGEN_RUN
};

#endif // QXTLABEL_H