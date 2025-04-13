#ifndef DIALOGEMPLOYEEINFO_H
#define DIALOGEMPLOYEEINFO_H

#include <QDialog>
#include "mysql.h"
#include "function.h"

namespace Ui {
class DialogEmployeeInfo;
}

class DialogEmployeeInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEmployeeInfo(QWidget *parent = nullptr);
    ~DialogEmployeeInfo();

public slots:
    void exportExcel();

private:
    Ui::DialogEmployeeInfo *ui;
    void Init();

    MySql *mysql = NULL;
    // QSqlDatabase db;
};

#endif // DIALOGEMPLOYEEINFO_H
