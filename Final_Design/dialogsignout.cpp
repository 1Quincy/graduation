#include "dialogsignout.h"
#include "ui_dialogsignout.h"
#include "QDir"

DialogSignOut::DialogSignOut(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogSignOut)
{
    ui->setupUi(this);

    Init();
    mysql = new MySql;
}

DialogSignOut::~DialogSignOut()
{
    delete ui;
}

void DialogSignOut::on_BtnCancel_clicked()
{
    this->close();
}

void DialogSignOut::Init()
{
    ui->labelNo->setText("工号：" + usr.getNo());
    ui->labelName->setText("姓名：" + usr.getUsername());
    ui->labelDate->setText("签退日期：" + QDate::currentDate().toString("yyyy-MM-dd"));
    ui->labelTime->setText("签退时间：" + QTime::currentTime().toString("hh:mm:ss"));

    QString photo = usr.getPhotograph();
    QImage image;   //添加图片
    image.load(photo);
    ui->labelPhoto->setPixmap(QPixmap::fromImage(image));
    ui->labelPhoto->resize(QSize(image.width(),image.height()));
}

void DialogSignOut::on_BtnOk_clicked()
{
    // 使用 QString::arg 构建 SQL 语句
    QString str = QString("INSERT INTO qiantuiinfo (employeeNo, employeeName, department, position,leaveDate, leaveTime) VALUES ('%1', '%2', '%3', '%4', '%5','%6')")
                      .arg(usr.getNo())
                      .arg(usr.getUsername())
                      .arg(usr.getDepartment())
                      .arg(usr.getPosition())
                      .arg(QDate::currentDate().toString("yyyy-MM-dd"))
                      .arg(QTime::currentTime().toString("hh:mm:ss"));

    qDebug() << str;
    mysql->MySql_Insert(str);
    //"INSERT INTO table_name (col1, col2, col3) VALUES (1, 1, 2)");

    //查询当前用户的今日签到时间和正常下班时间
    QString select = QString("SELECT workStartTimeReal,workEndTimeNormal FROM worktime WHERE employeeNo = '%1' and date = '%2'").arg(usr.getNo()).arg(QDate::currentDate().toString("yyyy-MM-dd"));
    QStringList res = mysql->MySql_Select(select);
    QStringList list = res.at(0).split("|");
    QString workStartTimeReal = list.at(0);
    QString workEndTimeNormal = list.at(1);

    //计算今日工作时间和加班时间
    QTime current = QTime::currentTime();
    QTime timestart = QTime::fromString(workStartTimeReal);
    QTime timeend = QTime::fromString(workEndTimeNormal);
    float workTime = timestart.secsTo(current)/3600.0;
    float overTime = timeend.secsTo(current)/3600.0;
    if(overTime < 1.0) overTime = 0;

    //更新工作时长信息
    QString update = QString("UPDATE worktime SET workEndTimeReal = '%1' ,workTime = '%2',overTime = '%3' , leaveEarly = '%4' WHERE employeeNo = '%5' and date = '%6'")
                         .arg(QTime::currentTime().toString("hh:mm:ss"))
                         .arg(workTime,0,'f',1)  //值，最小宽度，定点小数，保留一位
                         .arg(overTime,0,'f',1)
                         .arg(QTime::fromString("17:00:00") > QTime::currentTime() ? "是" : "否")
                         .arg(usr.getNo())
                         .arg(QDate::currentDate().toString("yyyy-MM-dd"));
    mysql->MySql_Update(update);
    this->accept();
}

