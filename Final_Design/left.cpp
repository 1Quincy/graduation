#include "left.h"
#include "ui_left.h"

left::left(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::left)
{
    ui->setupUi(this);
    ui->msgLabel->adjustSize();
    ui->msgLabel->setWordWrap(true);
    ui->msgLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    ui->msgLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->msgLabel->setTextInteractionFlags(Qt::NoTextInteraction);
}

left::~left()
{
    delete ui;
}

void left::setUsername(const QString &name)
{
    ui->nameLabel->setText(name);
    ui->nameLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
}

void left::setPhoto(const QPixmap &photo)
{
    ui->photoLabel->setPixmap(photo);
    ui->photoLabel->setScaledContents(true);
}

void left::setMsg(const QString &msg)
{
    ui->msgLabel->setMaximumWidth(500);

    //  关键尺寸策略
    ui->msgLabel->setSizePolicy(
        QSizePolicy::Preferred,  //
        QSizePolicy::Minimum   //
        );

    //  样式设置
    ui->msgLabel->setStyleSheet(
        "background-color: #DCF8C6;"
        "border-radius: 10px;"
        "padding: 8px;"                   // 统一使用 padding
        "margin: 0 12px 0 12px;"          // 外间距代替 contentsMargins
        );

    ui->msgLabel->setText(msg);

    //  强制布局更新
    this->adjustSize();
    QApplication::processEvents();
}
