#include "right.h"
#include "ui_right.h"
#include <QVBoxLayout>
#include <QFontMetrics>
#include <QResizeEvent>

Right::Right(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Right)
{
    ui->setupUi(this);
    ui->msgLabel->adjustSize();
    ui->msgLabel->setWordWrap(true);
    ui->msgLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    ui->msgLabel->setAlignment(Qt::AlignRight | Qt::AlignTop);
    ui->msgLabel->setTextInteractionFlags(Qt::NoTextInteraction);   //设置不可选中
}

Right::~Right()
{
    delete ui;
}


void Right::setUsername(const QString &name)
{
    ui->nameLabel->setText(name);
    ui->nameLabel->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
}

void Right::setPhoto(const QPixmap &photo)
{
    ui->photoLabel->setPixmap(photo);
    ui->photoLabel->setScaledContents(true);
}

void Right::setMsg(const QString &msg)
{
    ui->msgLabel->setMaximumWidth(500);

    // 2. 关键尺寸策略
    ui->msgLabel->setSizePolicy(
        QSizePolicy::Preferred,  //
        QSizePolicy::Minimum   //
    );

    // 3. 动态计算宽度
    // const int parentWidth = this->width();
    // const int maxLabelWidth = parentWidth * 0.7 - 24; // 减去左右边距总和
    //ui->msgLabel->setMinimumWidth(maxLabelWidth);

    // 4. 自动高度计算
    //QFontMetrics fm(ui->msgLabel->font());
    //QRect textRect = fm.boundingRect(
    //    QRect(0, 0, maxLabelWidth, 500), // 限制最大宽度
    //    Qt::TextWordWrap,                 // 启用换行
    //    msg
    //    );

    // 5. 计算总高度（包含边距和样式）
    //const int verticalMargin = 8 * 2;     // 样式表 padding
    //const int totalHeight = textRect.height() + verticalMargin;

    // 6. 应用动态高度（不要使用 setFixedHeight!）
    // ui->msgLabel->setMinimumHeight(totalHeight);

    // 7. 样式设置（关键调整）
    ui->msgLabel->setStyleSheet(
        "background-color: #DCF8C6;"
        "border-radius: 10px;"
        "padding: 8px;"                   // 统一使用 padding
        "margin: 0 12px 0 12px;"          // 外间距代替 contentsMargins
        );

    ui->msgLabel->setText(msg);

    // 8. 强制布局更新
    this->adjustSize();
    QApplication::processEvents();
}

