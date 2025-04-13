#ifndef MAINWINDOWTOTAL_H
#define MAINWINDOWTOTAL_H

#include <QMainWindow>
#include "dialoglogin.h"
#include "userinfo.h"
#include "mysql.h"
#include "dialogemployeeinfo.h"
#include "dialogpersoninfo.h"
#include "dialogsignin.h"
#include "dialogsignout.h"
#include "dialogleave.h"
#include "dialogpermit.h"
#include "dialogleavelog.h"
#include "dialogworktime.h"

    //#include "userinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowTotal;
}
QT_END_NAMESPACE

class MainWindowTotal : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowTotal(QWidget *parent = nullptr);
    ~MainWindowTotal();

    static MainWindowTotal* instance();

private slots:
    void on_actionExit_triggered();

    void on_actionEmployeeInfo_triggered();     //点击员工信息action

    void on_tabWidget_tabCloseRequested(int index); //tab关闭请求时槽函数
    void on_actionPerson_triggered();       //点击个人信息action
    void on_actionSignIn_triggered();       //点击签到action
    void on_actionSign_out_triggered();     //点击签退action

    void on_actionLeave_triggered();

    void on_actionPermit_triggered();

    void on_actionRecord_triggered();

    void on_actionWorkTime_triggered();

    void on_actionExport_triggered();

signals:
    void exportEmit();

protected:
    // 重写按键按下事件处理函数
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindowTotal *ui;

    void Init(); //初始化主界面

   // UserInfo user;  //记录登录用户的信息
    // DialogLogin *login = NULL;
    MySql *mysql = NULL;

   // void GetUserInfo();
};
#endif // MAINWINDOWTOTAL_H
