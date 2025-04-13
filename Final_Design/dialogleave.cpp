#include "dialogleave.h"
#include "ui_dialogleave.h"
#include "QMessageBox"

DialogLeave::DialogLeave(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogLeave)
{
    ui->setupUi(this);

    Init();
}

DialogLeave::~DialogLeave()
{
    delete ui;
}

void DialogLeave::on_dateTimeEditStart_dateTimeChanged(const QDateTime &dateTime)   //日期改变时更新请假天数和限制
{
    int days = ui->dateTimeEditStart->dateTime().daysTo(ui->dateTimeEditEnd->dateTime());
    ui->labelDays->setText(QString("请假天数: %1 天").arg(days));
    ui->dateTimeEditEnd->setMinimumDateTime(ui->dateTimeEditStart->dateTime());
}


void DialogLeave::on_dateTimeEditEnd_dateTimeChanged(const QDateTime &dateTime)     //日期改变时更新请假天数和限制
{
    int days = ui->dateTimeEditStart->dateTime().daysTo(ui->dateTimeEditEnd->dateTime());
    ui->labelDays->setText(QString("请假天数: %1 天").arg(days));
    ui->dateTimeEditStart->setMaximumDateTime(ui->dateTimeEditEnd->dateTime());
}

void DialogLeave::Init()
{
    //获取当前用户工号和姓名
    ui->labelNo->setText("工号：" + usr.getNo());
    ui->labelName->setText("姓名： " + usr.getUsername());

    //设置默认日期时间
    ui->dateTimeEditStart->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEditEnd->setDateTime(QDateTime::currentDateTime());

    //设置弹出日历
    ui->dateTimeEditStart->setCalendarPopup(true);
    ui->dateTimeEditEnd->setCalendarPopup(true);

    //设置请假天数只读，并算出请假天数
    ui->labelDays->setEnabled(false);
    int days = ui->dateTimeEditStart->dateTime().daysTo(ui->dateTimeEditEnd->dateTime());
    ui->labelDays->setText(QString("请假天数: %1 天").arg(days));
    //设置可选择的请假开始日期和结束日期限制
    ui->dateTimeEditEnd->setMinimumDateTime(ui->dateTimeEditStart->dateTime());
    ui->dateTimeEditStart->setMaximumDateTime(ui->dateTimeEditEnd->dateTime());

    //链接数据库
    mysql = new MySql;
}


void DialogLeave::on_BtnCancel_clicked()
{
    this->close();
}

void DialogLeave::on_BtnOk_clicked()
{
    // 使用 QString::arg 构建 SQL 语句
    qDebug()<<12345;
    QString str = QString("INSERT INTO qingjiainfo (employeeNo, employeeName, department, position, startTime,endTime,days,reason,permit) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8' ,'否')")
                      .arg(usr.getNo())
                      .arg(usr.getUsername())
                      .arg(usr.getDepartment())
                      .arg(usr.getPosition())
                      .arg(ui->dateTimeEditStart->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                      .arg(ui->dateTimeEditEnd->dateTime().toString("yyyy-MM-dd hh:mm:ss"))
                      .arg(ui->dateTimeEditStart->dateTime().daysTo(ui->dateTimeEditEnd->dateTime()))
                      .arg(ui->plainTextEditReason->toPlainText());

    qDebug() << str;
    mysql->MySql_Update(str);
    //"INSERT INTO table_name (col1, col2, col3) VALUES (1, 1, 2)");

    QMessageBox::information(this, "请假", "请假提交成功！");
    this->accept();
}

