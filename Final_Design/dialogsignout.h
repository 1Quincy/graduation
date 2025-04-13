#ifndef DIALOGSIGNOUT_H
#define DIALOGSIGNOUT_H

#include <QDialog>
#include "userinfo.h"
#include "mysql.h"

namespace Ui {
class DialogSignOut;
}

class DialogSignOut : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSignOut(QWidget *parent = nullptr);
    ~DialogSignOut();

private slots:
    void on_BtnCancel_clicked();

    void on_BtnOk_clicked();

private:
    Ui::DialogSignOut *ui;

    void Init();//初始化对话框
    MySql *mysql = NULL;
};

#endif // DIALOGSIGNOUT_H
