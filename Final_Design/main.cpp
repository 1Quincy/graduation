#include "mainwindowtotal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DialogLogin *login = new DialogLogin();     //登录界面
    if(login->exec() != QDialog::Accepted){
        return 0;
    }

    MainWindowTotal w;
    w.setFixedSize(w.geometry().size()); //窗体固定大小
    w.show();
    return a.exec();
}
