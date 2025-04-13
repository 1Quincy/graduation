#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>
#include "QMouseEvent"
#include "mysql.h"
#include "userinfo.h"
#include "dialogregister.h"


namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    ~DialogLogin();

private slots:
    void on_BtnCancel_clicked();

    void on_BtnLogin_clicked();

    void on_lineEditUserName_textChanged(const QString &arg1);

    void on_lineEditPassWord_textChanged(const QString &arg1);

    void on_BtnRegister_clicked();

    void on_ActionShowPassword_triggered();

    void on_BtnModifyPwd_clicked();

private:
    Ui::DialogLogin *ui;

    QString m_user;                 //用户名
    QString m_pwd;                  //密码
    int m_count;
    bool m_moving = false;          //是否可以移动
    QPoint m_lastPosition ;         //登录界面上个位置
    //QString encrypt(const QString &str);//加密函数
    void saveUserinfo(const QString& username, const QString& password);
    void getUserinfo(QString &username, QString& password);
    void Init();    //初始化界面

    QAction *actionShowPassword;  //查看密码action
    MySql *mysql = NULL;

    virtual void mousePressEvent(QMouseEvent *event);       //继承父类的虚函数：鼠标按下
    virtual void mouseReleaseEvent(QMouseEvent *event);     //鼠标释放
    virtual void mouseMoveEvent(QMouseEvent *event);        //鼠标移动
    virtual void keyPressEvent(QKeyEvent *event);           //键盘按下
};

#endif // DIALOGLOGIN_H
