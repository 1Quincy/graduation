#pragma once

#include <QWidget>
#include "ui_ContactItem.h"

class ContactItem : public QWidget
{
	Q_OBJECT

public:
	ContactItem(QWidget *parent = Q_NULLPTR);
	~ContactItem();

	void setUserName(const QString& userName);
    //void setSignName(const QString& signName);
	void setHeadPixmap(const QPixmap& pixmap);
	QString getUserName();
	QSize getHeadLabelSize();

private:
	Ui::ContactItem ui;
};
