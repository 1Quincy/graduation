#include "dialogpersoninfo.h"
#include "ui_dialogpersoninfo.h"
#include "QDir"
#include "ContactItem.h"
#include "mysql.h"
#include "userinfo.h"
#include "talkwindow.h"
#include "qsqlquery.h"
#include "ClockWidget.h"
#include "QMouseEvent"
#include "dialogmodifyinfo.h"

extern UserInfo usr;

DialogPersonInfo::DialogPersonInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPersonInfo)
{
    ui->setupUi(this);
    Init();
}

DialogPersonInfo::~DialogPersonInfo()
{
    delete ui;
}

void DialogPersonInfo::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPoint pos = event->pos();
        if (ui->labelPhoto->geometry().contains(pos)) {
            emit photoClicked();
        }
    }
    QDialog::mousePressEvent(event);
}

void DialogPersonInfo::onListItemDoubleClicked(QListWidgetItem *item)
{
    QString talkId = item->data(Qt::UserRole).toString();
    if (talkId == usr.getNo()) return;            //不能与自己聊天

    addNewTalkWindow(talkId);
}

void DialogPersonInfo::onPhotoLabelClicked()
{
    qDebug()<<"photo";
    DialogModifyInfo *modifyInfo = new DialogModifyInfo(this);

    //如果发生更改则刷新界面
    if(modifyInfo->exec() == QDialog::Accepted){
        this->Init();
    }
}

void DialogPersonInfo::Init()
{
    QString no = "工号：" + usr.getNo();
    ui->labelNo->setText(no);
    QString name = "姓名：" + usr.getUsername();
    ui->labelName->setText(name);
    QString role = "角色：" + usr.getRole();
    ui->labelRole->setText(role);
    QString department = "部门：" + usr.getDepartment();
    ui->labelDepartment->setText(department);
    QString position = "职位：" + usr.getPosition();
    ui->labelPosition->setText(position);
    /*QString Path = QCoreApplication::applicationDirPath();  //获取exe文件的路径
    QDir dir(Path);
    dir.cdUp();
    dir.cdUp();
    //qDebug()<<dir.absolutePath();
    QString photo = dir.absolutePath()+ "/QQOldPIC/" + usr.getPhotograph();*/

    QString photo =  usr.getPhotograph();


    QImage image;   //添加图片
    image.load(photo);
    ui->labelPhoto->setPixmap(QPixmap::fromImage(image));
    ui->labelPhoto->resize(QSize(image.width(),image.height()));

    //初始化聊天功能
    InitChat();

    //设置tab位置
    //ui->rightWidget->setTabPosition(QTabWidget::East);

    //初始化右边界面

    QLocale::setDefault(QLocale(QLocale::Chinese));
    ClockWidget* clock = new ClockWidget;
    int index = ui->rightWidget->addTab(clock,"");
    qDebug()<<index;
    ui->rightWidget->setCurrentIndex(index);  //设置选中新tab

    ui->rightWidget->removeTab(index-1);  //移除之前的tab

    connect(this,&DialogPersonInfo::photoClicked,this,&DialogPersonInfo::onPhotoLabelClicked);
}

void DialogPersonInfo::InitChat()
{
    QString sql = "select * from employeeinfo";
    auto list = MySql::instance()->MySql_Select(sql);
    for (int i = 0; i < list.count(); i++) {
        QStringList list2 = list.at(i).split("|");

        QListWidgetItem* ListWidgetItem = new QListWidgetItem;
        ListWidgetItem->setSizeHint(QSize(100,30));
        ListWidgetItem->setData(Qt::UserRole,list2.at(0));
        ui->employeeList->addItem(ListWidgetItem);

        ContactItem* item = new ContactItem(ui->employeeList);
        item->setUserName(list2.at(1));
        QPixmap p(list2.at(8));
        item->setHeadPixmap(p);

        connect(ui->employeeList, &QListWidget::itemDoubleClicked, this, &DialogPersonInfo::onListItemDoubleClicked);
        ui->employeeList->setItemWidget(ListWidgetItem,item);
    }
}

QWidget *DialogPersonInfo::findWindowMap(const QString& id)
{
    if(talkWindowMap[id]){
        return talkWindowMap[id];
    }else{
        return nullptr;
    }
}

void DialogPersonInfo::addNewTalkWindow(const QString& id)
{
    //判断聊天窗口是否已经存在
    QWidget* widget = findWindowMap(id);
    if (!widget)
    {
        TalkWindow* talkWindow = new TalkWindow(usr.getNo(),id, ui->rightWidget);

        //设置聊天窗口相关信息
        QSqlQuery sql(QString("SELECT photograph FROM employeeinfo WHERE employeeNo = %1").arg(id), MySql::instance()->getDatabase());
        QString path;
        if (sql.next())
        {
            path = sql.value(0).toString();
        }
        path.replace("\\","/");
        //qDebug()<<path;
        //QPixmap p(path);
        talkWindow->setTitle(id,path);

        //聊天窗口添加
        talkWindowMap[id] = talkWindow;
        loadMessage(*talkWindow,usr.getNo(),id);
        int index = ui->rightWidget->addTab(talkWindow,"");
        qDebug()<<index;
        ui->rightWidget->setCurrentIndex(index);  //设置选中新tab

        ui->rightWidget->removeTab(index-1);  //移除之前的tab
        //ui->rightWidget->setTabVisible(index-1,false);

    }
    else        //窗口已经存在
    {
        int index = ui->rightWidget->addTab(widget,"");
        ui->rightWidget->setCurrentIndex(index);  //设置选中新tab

        ui->rightWidget->removeTab(index-1);  //移除之前的tab
        //ui->rightWidget->setCurrentWidget(widget);
    }

}

void DialogPersonInfo::loadMessage(TalkWindow& talkWindow,const QString &sendID, const QString &receiveID)
{
    QSqlQuery sql(QString("select * from msgrecord where (sendID = %1 and receiveID = %2) or (sendID = %3 and receiveID = %4) order by time")
                      .arg(sendID)
                      .arg(receiveID)
                      .arg(receiveID)
                      .arg(sendID));
    while(sql.next()){
        if(sendID == sql.value(0).toString() && receiveID == sql.value(1).toString()){
            //向外发送的消息
            // qDebug()<<sql.value(0).toString();
            // qDebug()<<sql.value(1).toString();
            // qDebug()<<sql.value(2).toString();
            QDateTime t = sql.value(3).toDateTime();
            QString Time = t.toString("yyyy-MM-dd hh:mm:ss");
            qDebug()<<Time;
            QDateTime time = QDateTime::fromString(Time,"yyyy-MM-dd hh:mm:ss");
            talkWindow.addMsg(1,sendID,receiveID,sql.value(2).toString(),time);
        }else if(sendID == sql.value(1).toString() && receiveID == sql.value(0).toString()){
            //接收的消息
            QDateTime t = sql.value(3).toDateTime();
            QString Time = t.toString("yyyy-MM-dd hh:mm:ss");
            qDebug()<<Time;
            QDateTime time = QDateTime::fromString(Time,"yyyy-MM-dd hh:mm:ss");
            talkWindow.addMsg(0,sendID,receiveID,sql.value(2).toString(),time);
        }
    }
}

