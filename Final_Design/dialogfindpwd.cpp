#include "dialogfindpwd.h"
#include "ui_dialogfindpwd.h"
#include "qmessagebox.h"
#include "mysql.h"
#include "qsqlquery.h"
#include "qsqlerror.h"
#include "function.h"

DialogFindPwd::DialogFindPwd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogFindPwd)
{
    ui->setupUi(this);
    init();
}

DialogFindPwd::~DialogFindPwd()
{
    delete ui;
}

void DialogFindPwd::init()
{

}

void DialogFindPwd::on_BtnOK_clicked()
{
    // 检查必填项是否为空
    if (ui->newPwdLineEdit->text().isEmpty() ||
        ui->userLineEdit->text().isEmpty() ||
        ui->oldPwdLineEdit->text().isEmpty() ||
        ui->confirmPwdLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名，旧密码和新密码都不能为空！");
        return;
    }
    QSqlDatabase db = MySql::instance()->getDatabase();
    QSqlQuery sql(db);

    // 使用占位符（如:send, :receive）
    sql.prepare("select password from employeeinfo where employeeNO = :ID");

    // 绑定参数（自动处理转义和类型）
    sql.bindValue(":ID", ui->userLineEdit->text());

    if (sql.exec()) {
        // 查询成功
        qDebug() << "查询成功，行数:" << sql.numRowsAffected();
    } else {
        // 获取详细错误信息
        QSqlError error = sql.lastError();
        qDebug() << "SQL 错误:" << error.text();
        qDebug() << "错误代码:" << error.nativeErrorCode();    
    }
    if(sql.next()){
        QString pwd = sql.value(0).toString();
        qDebug()<<pwd;
        if(Function::instance()->encrypt(ui->oldPwdLineEdit->text()) != pwd){
            QMessageBox::warning(this, "警告", "用户名或密码错误！");
            ui->oldPwdLineEdit->clear();
            ui->userLineEdit->clear();
            ui->newPwdLineEdit->clear();
            ui->confirmPwdLineEdit->clear();
            return;
        }
    }else{
        QMessageBox::warning(this, "警告", "用户名不存在！");
        ui->userLineEdit->clear();
        ui->oldPwdLineEdit->clear();
        ui->newPwdLineEdit->clear();
        ui->confirmPwdLineEdit->clear();
        return;
    }
    if(ui->newPwdLineEdit->text() != ui->confirmPwdLineEdit->text()){
        QMessageBox::warning(this, "警告", "新密码和确认密码不一致！");
        ui->newPwdLineEdit->clear();
        ui->confirmPwdLineEdit->clear();
        return;
    }

    sql.prepare("update employeeinfo set password = :pwd where employeeNO = :ID");
    sql.bindValue(":pwd",Function::instance()->encrypt(ui->newPwdLineEdit->text()));
    sql.bindValue(":ID",ui->userLineEdit->text());

    if (sql.exec()) {
        // 更新成功
        qDebug() << "更新成功！";
        QMessageBox::information(this, "提示", "密码修改成功！");
    } else {
        // 获取详细错误信息
        QSqlError error = sql.lastError();
        qDebug() << "SQL 错误:" << error.text();
        qDebug() << "错误代码:" << error.nativeErrorCode();
        QMessageBox::information(this, "提示", "密码修改失败！");
    }
    this->accept();
}


void DialogFindPwd::on_BtnCancel_clicked()
{
    this->close();
}

