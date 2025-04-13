#include "dialogworktime.h"
#include "ui_dialogworktime.h"
#include "function.h"

DialogWorkTime::DialogWorkTime(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogWorkTime)
{
    ui->setupUi(this);

    mysql = new MySql;
    Init();
}

DialogWorkTime::~DialogWorkTime()
{
    delete ui;
}

void DialogWorkTime::Init()
{
    //初始化控件
    ui->lineEditNo->setText(usr.getNo());
    ui->dateEdit->setDate(QDate::currentDate());
    ui->BtnLateNum->setVisible(false);
    ui->BtnEarlyNum->setVisible(false);
    ui->labelDays->setVisible(true);

    //记录本月工作天数，本月工作时长，本月加班时长
    int days = 0;
    float worktime = 0.0;
    float overtime = 0.0;

    QStringList headStr = {"工号","姓名","日期","上班时间","签到时间","下班时间","签退时间","工作时长","加班时长","是否迟到","是否早退"};
    //创建表
    Function::instance()->createTable(headStr,ui->tableWidget);

    //如果是管理员用户则可以查看所有用户的工作时长，非管理员用户只能查看自己的工作时长
    if(usr.getRole() == "管理员"){
        QStringList list = mysql->MySql_Select("select employeeNo,employeeName,date,workStartTimeNormal,workStartTimeReal,workEndTimeNormal,workEndTimeReal,workTime,overTime,beLate,leaveEarly from worktime");   //查询结果
        // 设置表格行数
        //ui->tableWidget->setRowCount(list.count());     //设置行数
        for(int i = 0 ;i<list.count();i++){
            QStringList list2 = list.at(i).split("|");    //分割查询结果
            int rowCount = ui->tableWidget->rowCount(); //记录当前行号
            ui->tableWidget->insertRow(rowCount);   //插入一空白行

            // 获取数据并填充到表格中
            for(int j = 0;j<list2.count();j++){
                QTableWidgetItem *item = new QTableWidgetItem(list2.at(j));
                // 设置单元格文本居中对齐
                item->setTextAlignment(Qt::AlignCenter);
                item->setToolTip(item->text());//鼠标悬停显示文本
                item->setFlags(item->flags() & ~Qt::ItemIsEditable); // 设置不可编辑
                ui->tableWidget->setItem(rowCount , j, item);
            }
        }

        //查询自己工作记录，并设置本月工作天数，本月工作时长，本月加班时长
        list = mysql->MySql_Select
               (QString("SELECT workTime,overTime FROM worktime WHERE employeeNo = '%1' AND YEAR(date) = YEAR(CURDATE()) AND MONTH(date) = MONTH(CURDATE())").arg(usr.getNo()));   //查询本月工作记录
        ui->labelDays->setText(QString("本月我的工作天数：%1 天").arg(list.count()));
        for(int i = 0;i<list.count();i++){
            QStringList list2 = list.at(i).split("|");    //分割查询结果
            worktime += list2.at(0).toFloat();
            overtime += list2.at(1).toFloat();
        }
        ui->labelWorkHours->setText(QString("本月我的工作时长：%1 小时").arg(worktime));
        ui->labelOverHours->setText(QString("本月我的加班时长：%1 小时").arg(overtime));

    }else{
        //普通用户只能查找自己的信息
        ui->lineEditNo->setEnabled(false);
        ui->BtnSelectAll->setEnabled(false);

        QStringList list = mysql->MySql_Select
                           (QString("select employeeNo,employeeName,date,workStartTimeNormal,workStartTimeReal,workEndTimeNormal,workEndTimeReal,workTime,overTime,beLate,leaveEarly from worktime where employeeNo = '%1'").arg(usr.getNo()));   //查询结果

        // 设置表格行数
        //ui->tableWidget->setRowCount(list.count());     //设置行数
        for(int i = 0 ;i<list.count();i++){
            QStringList list2 = list.at(i).split("|");    //分割查询结果
            int rowCount = ui->tableWidget->rowCount(); //记录当前行号
            ui->tableWidget->insertRow(rowCount);   //插入一空白行

            // 获取数据并填充到表格中
            for(int j = 0;j<list2.count();j++){
                QTableWidgetItem *item = new QTableWidgetItem(list2.at(j));
                // 设置单元格文本居中对齐
                item->setTextAlignment(Qt::AlignCenter);
                item->setToolTip(item->text());//鼠标悬停显示文本
                item->setFlags(item->flags() & ~Qt::ItemIsEditable); // 设置不可编辑
                ui->tableWidget->setItem(rowCount , j, item);
            }
        }

        //设置本月工作天数，本月工作时长，本月加班时长
        list = mysql->MySql_Select
               (QString("SELECT workTime,overTime FROM worktime WHERE employeeNo = '%1' AND YEAR(date) = YEAR(CURDATE()) AND MONTH(date) = MONTH(CURDATE())").arg(usr.getNo()));   //查询本月工作记录
        ui->labelDays->setText(QString("本月我的工作天数：%1 天").arg(list.count()));
        for(int i = 0;i<list.count();i++){
            QStringList list2 = list.at(i).split("|");    //分割查询结果
            worktime += list2.at(0).toFloat();
            overtime += list2.at(1).toFloat();
        }
        ui->labelWorkHours->setText(QString("本月我的工作时长：%1 小时").arg(worktime));
        ui->labelOverHours->setText(QString("本月我的加班时长：%1 小时").arg(overtime));
    }

}

void DialogWorkTime::on_BtnFind_clicked()
{
    QString no = ui->lineEditNo->text();
    QDate date = ui->dateEdit->date();

    //隐藏查看迟到列表和查看早退列表按钮
    ui->BtnLateNum->setVisible(false);
    ui->BtnEarlyNum->setVisible(false);

    if(no.isEmpty()){
        //创建tablewidget
        QStringList headStr = {"工号","姓名","日期","上班时间","签到时间","下班时间","签退时间","工作时长","加班时长","是否迟到","是否早退"};
        Function::instance()->createTable(headStr,ui->tableWidget);

        QStringList list = mysql->MySql_Select
                           (QString("select employeeNo,employeeName,date,workStartTimeNormal,workStartTimeReal,workEndTimeNormal,workEndTimeReal,workTime,overTime,beLate,leaveEarly from worktime where date = '%1'")
                                                   .arg(date.toString("yyyy-MM-dd")));   //查询结果
        // 设置表格行数
        //ui->tableWidget->setRowCount(list.count());     //设置行数
        for(int i = 0 ;i<list.count();i++){
            QStringList list2 = list.at(i).split("|");    //分割查询结果
            int rowCount = ui->tableWidget->rowCount(); //记录当前行号
            ui->tableWidget->insertRow(rowCount);   //插入一空白行

            // 获取数据并填充到表格中
            for(int j = 0;j<list2.count();j++){
                QTableWidgetItem *item = new QTableWidgetItem(list2.at(j));
                // 设置单元格文本居中对齐
                item->setTextAlignment(Qt::AlignCenter);
                item->setToolTip(item->text());//鼠标悬停显示文本
                item->setFlags(item->flags() & ~Qt::ItemIsEditable); // 设置不可编辑
                ui->tableWidget->setItem(rowCount , j, item);
            }
        }

        //显示当日上班人数
        ui->labelDays->setVisible(true);
        ui->labelDays->setText(QString("当日上班人数：%1 人").arg(list.count()));   //当日上班人数
        //显示当日迟到人数和本人早退人数
        int late = 0;
        int early = 0;
        for(int i = 0;i<list.count();i++){
            QStringList list2 = list.at(i).split("|");    //分割查询结果
            if(list2.at(9)=="是"){
                late++;
            }
            if(list2.at(10)=="是"){
                early++;
            }
        }
        ui->labelWorkHours->setText(QString("当日迟到人数：%1 人").arg(late));  //当日迟到人数
        ui->labelOverHours->setText(QString("当日早退人数：%1 人").arg(early)); //当日早退人数

        //显示查看迟到列表和查看早退列表按钮
        ui->BtnLateNum->setVisible(true);
        ui->BtnEarlyNum->setVisible(true);

    }else{
        //创建tablewidget
        QStringList headStr = {"工号","姓名","日期","上班时间","签到时间","下班时间","签退时间","工作时长","加班时长","是否迟到","是否早退"};
        Function::instance()->createTable(headStr,ui->tableWidget);

        QStringList list = mysql->MySql_Select
                           (QString("select employeeNo,employeeName,date,workStartTimeNormal,workStartTimeReal,workEndTimeNormal,workEndTimeReal,workTime,overTime,beLate,leaveEarly from worktime where date = '%1' and employeeNo = '%2'")
                                .arg(date.toString("yyyy-MM-dd"))
                                .arg(no));   //查询结果
        // 设置表格行数
        //ui->tableWidget->setRowCount(list.count());     //设置行数
        for(int i = 0 ;i<list.count();i++){
            QStringList list2 = list.at(i).split("|");    //分割查询结果
            int rowCount = ui->tableWidget->rowCount(); //记录当前行号
            ui->tableWidget->insertRow(rowCount);   //插入一空白行

            // 获取数据并填充到表格中
            for(int j = 0;j<list2.count();j++){
                QTableWidgetItem *item = new QTableWidgetItem(list2.at(j));
                // 设置单元格文本居中对齐
                item->setTextAlignment(Qt::AlignCenter);
                item->setToolTip(item->text());//鼠标悬停显示文本
                item->setFlags(item->flags() & ~Qt::ItemIsEditable); // 设置不可编辑
                ui->tableWidget->setItem(rowCount , j, item);
            }
        }

        //设置当日工作时长，当日加班时长
        list = mysql->MySql_Select
               (QString("SELECT workTime,overTime FROM worktime WHERE employeeNo = '%1' AND date = '%2'")
                                       .arg(no)
                                       .arg(date.toString("yyyy-MM-dd")));   //查询指定员工指定日期的工作记录
        if(list.count()!=0){
            QStringList list2 = list.at(0).split("|");    //分割查询结果
            float worktime = list2.at(0).toFloat();
            float overtime = list2.at(1).toFloat();
            ui->labelWorkHours->setText(QString("当日工作时长：%1 小时").arg(worktime));   //当日工作时长
            ui->labelDays->setVisible(false);   //隐藏工作天数label
            ui->labelOverHours->setText(QString("当日加班时长：%1 小时").arg(overtime));   //当日加班时长
        }else{
            ui->labelWorkHours->setText(QString("当日工作时长：%1 小时").arg(0));   //当日工作时长
            ui->labelDays->setVisible(false);   //隐藏工作天数label
            ui->labelOverHours->setText(QString("当日加班时长：%1 小时").arg(0));   //当日加班时长
        }
    }
}


void DialogWorkTime::on_BtnSelectAll_clicked()
{
    Init(); //查询全部工作时长信息
}


void DialogWorkTime::on_BtnLateNum_clicked()
{
    //记录查询的日期
    QString date;
    for(int i = 0;i<ui->tableWidget->rowCount();i++){
        if(ui->tableWidget->item(i,9)->text()=="是"){
            date = ui->tableWidget->item(0,2)->text();
            break;
        }
    }

    //创建table
    QStringList headStr = {"工号","姓名","日期","上班时间","签到时间","下班时间","签退时间","工作时长","加班时长","是否迟到","是否早退"};
    Function::instance()->createTable(headStr,ui->tableWidget);

     QStringList list = mysql->MySql_Select
                        (QString("select employeeNo,employeeName,date,workStartTimeNormal,workStartTimeReal,workEndTimeNormal,workEndTimeReal,workTime,overTime,beLate,leaveEarly from worktime where date = '%1' and beLate = '是'")
                             .arg(date));   //查询结果
    // 设置表格行数
    //ui->tableWidget->setRowCount(list.count());     //设置行数
    for(int i = 0 ;i<list.count();i++){
        QStringList list2 = list.at(i).split("|");    //分割查询结果
        int rowCount = ui->tableWidget->rowCount(); //记录当前行号
        ui->tableWidget->insertRow(rowCount);   //插入一空白行

        // 获取数据并填充到表格中
        for(int j = 0;j<list2.count();j++){
            QTableWidgetItem *item = new QTableWidgetItem(list2.at(j));
            // 设置单元格文本居中对齐
            item->setTextAlignment(Qt::AlignCenter);
            item->setToolTip(item->text());//鼠标悬停显示文本
            item->setFlags(item->flags() & ~Qt::ItemIsEditable); // 设置不可编辑
            ui->tableWidget->setItem(rowCount , j, item);
        }
    }
}

void DialogWorkTime::on_BtnEarlyNum_clicked()
{
    //记录查询的日期
    QString date;
    for(int i = 0;i<ui->tableWidget->rowCount();i++){
        if(ui->tableWidget->item(i,10)->text()=="是"){
            date = ui->tableWidget->item(0,2)->text();
            break;
        }
    }

    //创建table
    QStringList headStr = {"工号","姓名","日期","上班时间","签到时间","下班时间","签退时间","工作时长","加班时长","是否迟到","是否早退"};
    Function::instance()->createTable(headStr,ui->tableWidget);

    QStringList list = mysql->MySql_Select
                       (QString("select employeeNo,employeeName,date,workStartTimeNormal,workStartTimeReal,workEndTimeNormal,workEndTimeReal,workTime,overTime,beLate,leaveEarly from worktime where date = '%1' and leaveEarly = '是'")
                            .arg(date));   //查询结果
    // 设置表格行数
    //ui->tableWidget->setRowCount(list.count());     //设置行数
    for(int i = 0 ;i<list.count();i++){
        QStringList list2 = list.at(i).split("|");    //分割查询结果
        int rowCount = ui->tableWidget->rowCount(); //记录当前行号
        ui->tableWidget->insertRow(rowCount);   //插入一空白行

        // 获取数据并填充到表格中
        for(int j = 0;j<list2.count();j++){
            QTableWidgetItem *item = new QTableWidgetItem(list2.at(j));
            // 设置单元格文本居中对齐
            item->setTextAlignment(Qt::AlignCenter);
            item->setToolTip(item->text());//鼠标悬停显示文本
            item->setFlags(item->flags() & ~Qt::ItemIsEditable); // 设置不可编辑
            ui->tableWidget->setItem(rowCount , j, item);
        }
    }
}

void DialogWorkTime::exportExcel()
{
    Function::instance()->exportToExcel(ui->tableWidget);
}

