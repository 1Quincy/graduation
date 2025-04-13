#include "dialogsignin.h"
#include "ui_dialogsignin.h"
#include "QTime"
#include "QDir"

DialogSignIn::DialogSignIn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogSignIn)
{
    ui->setupUi(this);
    Init();
    mysql = new MySql;
}

DialogSignIn::~DialogSignIn()
{
    delete ui;
}

void DialogSignIn::Init()
{
    ui->labelNo->setText("工号：" + usr.getNo());
    ui->labelName->setText("姓名：" + usr.getUsername());
    ui->labelTime->setText("签到时间："+QTime::currentTime().toString("hh:mm:ss"));
    ui->labelDate->setText("签到日期：" + QDate::currentDate().toString("yyyy-MM-dd"));

    QString photo = usr.getPhotograph();
    QImage image;   //添加图片
    image.load(photo);
    ui->labelPhoto->setPixmap(QPixmap::fromImage(image));
    ui->labelPhoto->resize(QSize(image.width(),image.height()));
}

void DialogSignIn::on_BtnCancel_clicked()
{
    this->close();  //关闭签到对话框
}

void DialogSignIn::on_BtnOk_clicked()
{
    // 使用 QString::arg 构建 SQL 语句
    QString str = QString("INSERT INTO dakainfo (employeeNo, employeeName, department, position, startDate,startTime) VALUES ('%1', '%2', '%3', '%4', '%5','%6')")
                      .arg(usr.getNo())
                      .arg(usr.getUsername())
                      .arg(usr.getDepartment())
                      .arg(usr.getPosition())
                      .arg(QDate::currentDate().toString("yyyy-MM-dd"))
                      .arg(QTime::currentTime().toString("hh:mm:ss"));

    //qDebug() << str;
    mysql->MySql_Insert(str);
    //"INSERT INTO table_name (col1, col2, col3) VALUES (1, 1, 2)");

    //记录工作时长信息
    QString insert = QString("INSERT INTO worktime (employeeNo, employeeName, date, workStartTimeNormal,workStartTimeReal, workEndTimeNormal,beLate) VALUES ('%1', '%2', '%3', '%4', '%5','%6','%7')")
                         .arg(usr.getNo())
                         .arg(usr.getUsername())
                         .arg(QDate::currentDate().toString("yyyy-MM-dd"))
                         .arg("09:00:00")
                         .arg(QTime::currentTime().toString("hh:mm:ss"))
                         .arg("17:00:00")
                         .arg(QTime::fromString("09:00:00") > QTime::currentTime() ? "否" : "是" );
    mysql->MySql_Insert(insert);
    this->accept();
}

