#ifndef DIALOGWORKTIME_H
#define DIALOGWORKTIME_H

#include <QDialog>
#include "userinfo.h"
#include "mysql.h"

namespace Ui {
class DialogWorkTime;
}

class DialogWorkTime : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWorkTime(QWidget *parent = nullptr);
    ~DialogWorkTime();

private slots:
    void on_BtnFind_clicked();

    void on_BtnSelectAll_clicked();

    void on_BtnLateNum_clicked();

    void on_BtnEarlyNum_clicked();

public slots:
    void exportExcel();

private:
    Ui::DialogWorkTime *ui;

    void Init();//初始化工作时长窗口
    MySql *mysql = NULL;

};

#endif // DIALOGWORKTIME_H
