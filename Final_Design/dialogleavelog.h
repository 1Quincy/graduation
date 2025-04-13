#ifndef DIALOGLEAVELOG_H
#define DIALOGLEAVELOG_H

#include <QDialog>
#include "userinfo.h"
#include "mysql.h"

namespace Ui {
class DialogLeaveLog;
}

class DialogLeaveLog : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLeaveLog(QWidget *parent = nullptr);
    ~DialogLeaveLog();

public slots:
    void exportExcel();

private:
    Ui::DialogLeaveLog *ui;    

    void Init();//初始化我的请假记录
     MySql *mysql = NULL;
};

#endif // DIALOGLEAVELOG_H
