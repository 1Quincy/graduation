#include "mainwindowtotal.h"
#include "./ui_mainwindowtotal.h"
#include "QTableWidget"
#include "QMessageBox"
#include "function.h"

Q_GLOBAL_STATIC(MainWindowTotal,theInstance);

MainWindowTotal::MainWindowTotal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowTotal)
{
    ui->setupUi(this);
    Init();

}

MainWindowTotal::~MainWindowTotal()
{
    delete ui;
}

MainWindowTotal *MainWindowTotal::instance()
{
    return theInstance();
}

void MainWindowTotal::on_actionExit_triggered()
{
    this->close();  //退出
}


void MainWindowTotal::on_actionEmployeeInfo_triggered()
{
    DialogEmployeeInfo *employeeinfo = new DialogEmployeeInfo(this);        //创建雇员信息对话框
    employeeinfo->setAttribute(Qt::WA_DeleteOnClose);                       //设置对话框关闭时自动删除

    //链接导出excel信号槽
    connect(this,&MainWindowTotal::exportEmit,employeeinfo,&DialogEmployeeInfo::exportExcel);

    int index = ui->tabWidget->addTab(employeeinfo,QString::asprintf("窗口%d",ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(index);  //设置选中新tab

    if (index > 0) {
        QWidget *previousWidget = ui->tabWidget->widget(index - 1);
        ui->tabWidget->removeTab(index - 1);
        delete previousWidget; // 手动删除之前的widget
    }

}

void MainWindowTotal::on_tabWidget_tabCloseRequested(int index) //关闭tab
{
    //获取对应的窗口
    QWidget *widget = ui->tabWidget->widget(index);
    widget->close();
}


void MainWindowTotal::on_actionPerson_triggered()
{
    DialogPersonInfo *personinfo = new DialogPersonInfo(this);        //创建个人信息对话框
    personinfo->setAttribute(Qt::WA_DeleteOnClose);                       //设置对话框关闭时自动删除

    int index = ui->tabWidget->addTab(personinfo,QString::asprintf("窗口%d",ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(index);  //设置选中新tab

    if (index > 0) {
        QWidget *previousWidget = ui->tabWidget->widget(index - 1);
        ui->tabWidget->removeTab(index - 1);
        delete previousWidget; // 手动删除之前的widget
    }
}


void MainWindowTotal::on_actionSignIn_triggered()
{
    //每天只能签到一次，如果查询到当天的签到记录则给出提醒
    QString str = "select * from dakainfo where employeeNo = '%1' ";
    mysql = new MySql;
    QStringList result = mysql->MySql_Select(QString(str).arg(usr.getNo()));
    bool ok = false;
    for(int i = 0;i<result.count();i++){
        QStringList list = result.at(i).split("|");
        if(list.at(5)==QDate::currentDate().toString("yyyy-MM-dd")){
            ok = true;
            break;
        }
    }
    if(ok){
        QMessageBox::information(this,"提示","您今天已经签过到了！");
        return;
    }

    DialogSignIn *signin = new DialogSignIn(this);  //创建签到对话框
    signin->setAttribute(Qt::WA_DeleteOnClose);     //关闭对话框时自动删除对话框

    signin->setWindowFlags(signin->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);   //原有属性加上固定大小

    signin->exec();   //模态方式显示

}


void MainWindowTotal::on_actionSign_out_triggered()
{
    //设置签到之后才能签退
    QString str = "select * from dakainfo where employeeNo = '%1' ";
    mysql = new MySql;
    QStringList result = mysql->MySql_Select(QString(str).arg(usr.getNo()));
    bool ok = false;
    for(int i = 0;i<result.count();i++){
        QStringList list = result.at(i).split("|");
        if(list.at(5)==QDate::currentDate().toString("yyyy-MM-dd")){
            ok = true;
            break;
        }
    }
    if(!ok){
        QMessageBox::information(this,"提示","您今天还未签到！");
        return;
    }

    //设置每天只能签退一次
    str = "select * from qiantuiinfo where employeeNo = '%1' ";
    mysql = new MySql;
    result = mysql->MySql_Select(QString(str).arg(usr.getNo()));
    ok = false;
    for(int i = 0;i<result.count();i++){
        QStringList list = result.at(i).split("|");
        if(list.at(5)==QDate::currentDate().toString("yyyy-MM-dd")){
            ok = true;
            break;
        }
    }
    if(ok){
        QMessageBox::information(this,"提示","您今天已经签退过！");
        return;
    }

    DialogSignOut *signout = new DialogSignOut(this);  //创建签退对话框
    signout->setAttribute(Qt::WA_DeleteOnClose);     //关闭对话框时自动删除对话框

    signout->setWindowFlags(signout->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);   //原有属性加上固定大小

    signout->exec();   //模态方式显示
}


void MainWindowTotal::on_actionLeave_triggered()
{
    DialogLeave *leave = new DialogLeave(this);  //创建签退对话框
    leave->setAttribute(Qt::WA_DeleteOnClose);     //关闭对话框时自动删除对话框

    leave->setWindowFlags(leave->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);   //原有属性加上固定大小

    leave->exec();   //模态方式显示
}

void MainWindowTotal::Init()
{
    ui->tabWidget->setTabsClosable(true);       //设置tab子窗口可关闭按钮，当点击关闭按钮之后会自动发送信号：tabCloseRequested
    ui->tabWidget->setTabBarAutoHide(true);     //tab数量小于2时，标签自动隐藏

    on_actionPerson_triggered();    //进入时显示个人信息界面

    if(usr.getRole() == "管理员"){
        ui->actionPermit->setEnabled(true);
        ui->actionEmployeeInfo->setEnabled(true);
    }else{
        ui->actionPermit->setEnabled(false);
        ui->actionEmployeeInfo->setEnabled(false);
    }
}


void MainWindowTotal::on_actionPermit_triggered()
{
    DialogPermit *permit = new DialogPermit(this);        //创建雇员信息对话框
    permit->setAttribute(Qt::WA_DeleteOnClose);                       //设置对话框关闭时自动删除

    int index = ui->tabWidget->addTab(permit,QString::asprintf("窗口%d",ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(index);  //设置选中新tab

    if (index > 0) {
        QWidget *previousWidget = ui->tabWidget->widget(index - 1);
        ui->tabWidget->removeTab(index - 1);
        delete previousWidget; // 手动删除之前的widget
    }

}

void MainWindowTotal::on_actionRecord_triggered()
{
    DialogLeaveLog *leaveLog = new DialogLeaveLog(this);        //创建我的请假记录对话框
    leaveLog->setAttribute(Qt::WA_DeleteOnClose);                       //设置对话框关闭时自动删除

    //链接导出excel信号槽
    connect(this,&MainWindowTotal::exportEmit,leaveLog,&DialogLeaveLog::exportExcel);

    int index = ui->tabWidget->addTab(leaveLog,QString::asprintf("窗口%d",ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(index);  //设置选中新tab

    if (index > 0) {
        QWidget *previousWidget = ui->tabWidget->widget(index - 1);
        ui->tabWidget->removeTab(index - 1);
        delete previousWidget; // 手动删除之前的widget
    }
    //ui->tabWidget->removeTab(index-1);  //移除之前的tab
}

void MainWindowTotal::on_actionWorkTime_triggered()
{
    DialogWorkTime *workTime = new DialogWorkTime(this);        //创建工作时长对话框
    workTime->setAttribute(Qt::WA_DeleteOnClose);                       //设置对话框关闭时自动删除

    //链接导出excel信号槽
    connect(this,&MainWindowTotal::exportEmit,workTime,&DialogWorkTime::exportExcel);

    int index = ui->tabWidget->addTab(workTime,QString::asprintf("窗口%d",ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(index);  //设置选中新tab

    if (index > 0) {
        QWidget *previousWidget = ui->tabWidget->widget(index - 1);
        ui->tabWidget->removeTab(index - 1);
        delete previousWidget; // 手动删除之前的widget
    }
}

void MainWindowTotal::keyPressEvent(QKeyEvent *event)
{
    // 重写按键按下事件处理函数
    if (event->key() == Qt::Key_Escape) {
        // 忽略 Esc 键事件
        event->ignore();
    } else {
        // 其他按键事件按默认方式处理
        QWidget::keyPressEvent(event);
    }
}


void MainWindowTotal::on_actionExport_triggered()
{
    emit exportEmit();
}

