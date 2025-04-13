#ifndef DIALOGFINDPWD_H
#define DIALOGFINDPWD_H

#include <QDialog>

namespace Ui {
class DialogFindPwd;
}

class DialogFindPwd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFindPwd(QWidget *parent = nullptr);
    ~DialogFindPwd();

    void init();

private slots:
    void on_BtnOK_clicked();

    void on_BtnCancel_clicked();

private:
    Ui::DialogFindPwd *ui;
    int count = 0; //记录错误次数
};

#endif // DIALOGFINDPWD_H
