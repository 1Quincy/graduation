#ifndef DIALOGPERMIT_H
#define DIALOGPERMIT_H

#include <QDialog>
#include "mysql.h"
#include "function.h"

namespace Ui {
class DialogPermit;
}

class DialogPermit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPermit(QWidget *parent = nullptr);
    ~DialogPermit();

private slots:
    void on_comboBox_changed(int index);  //是否批准发生改变时触发
private:
    Ui::DialogPermit *ui;
    void Init();//初始化批假界面

    MySql *mysql = NULL;
};

#endif // DIALOGPERMIT_H
