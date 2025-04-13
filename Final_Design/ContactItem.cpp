#include "ContactItem.h"

ContactItem::ContactItem(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ContactItem::~ContactItem()
{
}

void ContactItem::setUserName(const QString & userName)
{
	ui.userName->setText(userName);
}

// void ContactItem::setSignName(const QString & signName)
// {
// 	ui.signName->setText(signName);
// }

void ContactItem::setHeadPixmap(const QPixmap & pixmap)
{
	ui.label->setPixmap(pixmap);
    ui.label->setScaledContents(true);
}

QString ContactItem::getUserName()
{
	return ui.userName->text();
}

QSize ContactItem::getHeadLabelSize()
{
	return ui.label->size();
}
