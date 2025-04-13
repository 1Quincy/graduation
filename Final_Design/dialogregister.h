#ifndef DIALOGREGISTER_H
#define DIALOGREGISTER_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include "mysql.h"
#include "userinfo.h"

namespace Ui {
class DialogRegister;
}

class DialogRegister : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRegister(QWidget *parent = nullptr);
    ~DialogRegister();

    void Init(); //初始化注册窗口

    QString getEmployeeID() const;
    QString getName() const;
    QString getGender() const;
    QString getDate() const;
    QString getDepartment() const;
    QString getPosition() const;
    QString getTelephone() const;
    QString getEmail() const;
    QString getPhotoPath() const;
    QString getPassword() const;
    QString getRole() const;

    QString encrypt(const QString &str);//加密函数

private slots:
    void on_BtnBrowse_clicked(); // 浏览照片
    void on_BtnSubmit_clicked(); // 提交注册信息
    void on_BtnCancel_clicked(); // 取消注册
    void on_comboBoxDepartment_currentIndexChanged(int index);

private:
    Ui::DialogRegister *ui;

    MySql *mysql = NULL;
};

#endif // DIALOGREGISTER_H
