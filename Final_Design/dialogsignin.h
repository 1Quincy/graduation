#ifndef DIALOGSIGNIN_H
#define DIALOGSIGNIN_H

#include <QDialog>
#include "mysql.h"
#include "userinfo.h"
#include "mysql.h"

namespace Ui {
class DialogSignIn;
}

class DialogSignIn : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSignIn(QWidget *parent = nullptr);
    ~DialogSignIn();

private slots:
    void on_BtnCancel_clicked();

    void on_BtnOk_clicked();

private:
    Ui::DialogSignIn *ui;

    void Init();

    MySql *mysql = NULL;
};

#endif // DIALOGSIGNIN_H
