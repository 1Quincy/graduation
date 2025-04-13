#include "clockwidget.h"
#include "ui_clockwidget.h"
#include "QVBoxLayout"
#include "qtimer.h"
#include "qdatetime.h"
#include "QGraphicsColorizeEffect"
#include "QPropertyAnimation"

ClockWidget::ClockWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClockWidget)
{
    ui->setupUi(this);

    setWindowTitle("Qt时钟");
    setMinimumSize(400, 200);

    // 设置字体样式
    QFont font("Arial", 24, QFont::Bold);
    ui->timeLabel->setFont(font);
    ui->dateLabel->setFont(QFont("Arial", 18));
    ui->dayLabel->setFont(QFont("Arial", 18));

    // 设置对齐方式
    ui->timeLabel->setAlignment(Qt::AlignCenter);
    ui->dateLabel->setAlignment(Qt::AlignCenter);
    ui->dayLabel->setAlignment(Qt::AlignCenter);

    // 设置布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(ui->timeLabel);
    layout->addWidget(ui->dateLabel);
    layout->addWidget(ui->dayLabel);

    // 设置定时器
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ClockWidget::updateTime);
    timer->start(1000); // 每秒更新一次

    // 添加颜色动画
    // QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect(this);
    // ui->timeLabel->setGraphicsEffect(effect);

    // QPropertyAnimation *anim = new QPropertyAnimation(effect, "color");
    // anim->setDuration(3000);
    // anim->setLoopCount(-1); // 无限循环
    // anim->setKeyValueAt(0, QColor("#ffffff"));
    // anim->setKeyValueAt(1.5, QColor("#80deea"));
    // anim->setKeyValueAt(3, QColor("#ffffff"));
    // anim->start();

    // 初始化显示
    updateTime();
}

ClockWidget::~ClockWidget()
{
    delete ui;
}

void ClockWidget::updateTime()
{
    QDateTime current = QDateTime::currentDateTime();

    // 格式化时间
    ui->timeLabel->setText(current.toString("HH:mm:ss"));
    ui->dateLabel->setText(current.toString("yyyy年MM月dd日"));
    ui->dayLabel->setText(current.toString("dddd")); // 本地化星期显示
}
