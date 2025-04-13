#ifndef DIALOGLEAVE_H
#define DIALOGLEAVE_H

#include <QDialog>
#include "userinfo.h"
#include "mysql.h"

namespace Ui {
class DialogLeave;
}

class DialogLeave : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLeave(QWidget *parent = nullptr);
    ~DialogLeave();

private slots:
    void on_dateTimeEditStart_dateTimeChanged(const QDateTime &dateTime);

    void on_dateTimeEditEnd_dateTimeChanged(const QDateTime &dateTime);

    void on_BtnCancel_clicked();

    void on_BtnOk_clicked();

private:
    Ui::DialogLeave *ui;

    void Init();//初始化请假界面
    MySql *mysql = NULL;
};

#endif // DIALOGLEAVE_H
