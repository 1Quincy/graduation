#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include "QLineEdit"
#include "QMessageBox"
#include "QCryptographicHash"
#include "qsettings.h"
#include "define.h"
#include "QFile"
#include "dialogfindpwd.h"
#include "function.h"

DialogLogin::DialogLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogLogin)
{
    ui->setupUi(this);

    Init();
}

DialogLogin::~DialogLogin()
{
    mysql->MySql_DisLink(); // 断开数据库链接
    delete ui;
}

void DialogLogin::on_BtnCancel_clicked()
{
    this->close(); // 关闭
}

void DialogLogin::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) { // 如果左键按下
        m_moving = true;                     // 可以移动
        // qDebug()<<event->globalPos()<<"  "<<this->pos();
        m_lastPosition = event->globalPos() - this->pos(); // 更新登录界面的上个位置为：点击的位置减去对话框左上角的位置
    }

    return QDialog::mousePressEvent(event); // 让父类继续处理
}

void DialogLogin::mouseReleaseEvent(QMouseEvent *event)
{
    m_moving = false; // 不可移动
}

void DialogLogin::mouseMoveEvent(QMouseEvent *event)
{
    if (m_moving) { // 如果可以移动，更新窗口位置
        move(event->globalPos() - m_lastPosition);
        m_lastPosition = event->globalPos() - pos();
    }
    return QDialog::mouseMoveEvent(event);
}

void DialogLogin::on_BtnLogin_clicked()
{
    m_user = ui->lineEditUserName->text(); // 获取输入的用户名
    m_pwd = ui->lineEditPassWord->text();  // 获取输入的密码
    QString pwd = Function::instance()->encrypt(m_pwd);
    QString str = "select * from employeeinfo";
    auto list = mysql->MySql_Select(str);
    bool ok = false; // 查询用户名密码是否存在
    for (int i = 0; i < list.count(); i++) {
        QStringList list2 = list.at(i).split("|");
        if (list2.at(1) == m_user && list2.at(9) == pwd) {
            qDebug() << list2.at(1) << " " << list2.at(9);
            ok = true;
            // 登录成功 记录用户信息
            usr.setNo(list2.at(0));
            usr.setUsername(list2.at(1));
            usr.setGender(list2.at(2));
            usr.setDate(list2.at(3));
            usr.setDepartment(list2.at(4));
            usr.setPosition(list2.at(5));
            usr.setTelephone(list2.at(6));
            usr.setEmail(list2.at(7));
            usr.setPhotograph(list2.at(8));
            usr.setPwd(list2.at(9));
            usr.setRole(list2.at(10));
            // qDebug()<<usr.getNo()<<"|"<<usr.getUsername()<<"|"<<usr.getGender()<<"|"<<usr.getDate()<<"|"<<usr.getPosition()<<"|"<<usr.getPwd()<<"|"<<usr.getRole();
            this->accept();
            break;
        }
    }
    if (!ok) {
        m_count++;
        if (m_count > 3) {
            QMessageBox::critical(this, "错误", "用户名或密码错误次数太多！");
            this->reject();
        } else {
            QMessageBox::warning(this, "错误", "用户名或密码错误！");
        }
    }
    if(ok && ui->Remember->isChecked()){
        saveUserinfo(m_user,m_pwd);
    }else if(ok && !ui->Remember->isChecked()){
        saveUserinfo(m_user,"");
    }
}

void DialogLogin::on_lineEditUserName_textChanged(const QString &arg1)
{
    if (!ui->lineEditUserName->text().isEmpty() && !ui->lineEditPassWord->text().isEmpty()) {
        ui->BtnLogin->setEnabled(true); // 如果用户名和密码都非空，登录按钮可用
    } else {
        ui->BtnLogin->setEnabled(false);
    }
}

void DialogLogin::on_lineEditPassWord_textChanged(const QString &arg1)
{
    if (!ui->lineEditUserName->text().isEmpty() && !ui->lineEditPassWord->text().isEmpty()) {
        ui->BtnLogin->setEnabled(true); // 如果用户名和密码都非空，登录按钮可用
    } else {
        ui->BtnLogin->setEnabled(false);
    }
}

void DialogLogin::getUserinfo(QString &username, QString &password)
{
    const QString path = INI_PATH("user.ini");
    if(!QFile::exists(path)){   //如果文件不存在，则返回空
        username = "";
        password = "";
        return ;
    }

    QSettings set(path,QSettings::IniFormat);
    username = set.value("USER/username").toString();
    password = set.value("USER/password").toString();
}

void DialogLogin::saveUserinfo(const QString &username, const QString &password)
{
    const QString path = INI_PATH("user.ini");
    QSettings set(path, QSettings::IniFormat);
    set.setValue("USER/username",username);
    set.setValue("USER/password",password);
}

void DialogLogin::Init()
{
    m_count = 0;

    mysql = new MySql;

    // 取消标题栏
    this->setWindowFlags(Qt::FramelessWindowHint); // 没有标题栏，但是任务栏有标题
    // this->setWindowFlags(Qt::SplashScreen);     // 没有标题栏，也没有任务栏

    ui->lineEditPassWord->setEchoMode(QLineEdit::Password); // 设置密码输入格式
    this->setAttribute(Qt::WA_DeleteOnClose); // 关闭窗口自动销毁

    ui->BtnLogin->setEnabled(false); // 初始设置登录按钮不可用

    // 默认焦点在lineEditUserName
    ui->lineEditUserName->setFocus();

    //设置浅灰色提示文本
    ui->lineEditUserName->setPlaceholderText("请输入用户名");
    ui->lineEditPassWord->setPlaceholderText("请输入密码");

    //设置密码输入框样式qss
    ui->lineEditPassWord->setStyleSheet("QLineEdit#lineEditPassWord {"
                                        "border-radius: 5px;"
                                        "padding: 5px 5px;"
                                        "border: 2px solid #000000;"
                                        "background-color: #E8E8E8;"
                                        "font-size: 15px;}"

                                        "QLineEdit#lineEditPassWord:hover {"
                                        "background-color: #F5F5F5;"
                                        "border: 2px solid #BDBDBD;}"

                                        "QLineEdit#lineEditPassWord:focus { "
                                        "background-color: #FFFFFF;"
                                        "border: 2px solid black;}");

    //设置注册按钮样式
    ui->BtnRegister->setStyleSheet("QPushButton#BtnRegister {"
                                   "border:none;}"

                                   "QPushButton#BtnRegister:hover {"
                                   "color: #BDBDBD;}");


    //设置找回密码按钮样式
    ui->BtnModifyPwd->setStyleSheet("QPushButton#BtnModifyPwd {"
                                   "border:none;}"

                                   "QPushButton#BtnModifyPwd:hover {"
                                   "color: #BDBDBD;}");

    // 加载图像
    QString photo = ":/images/查看密码.png";
    QImage image; //添加图片
    image.load(photo);
    if (!image.isNull()) {
        // 从 QImage 创建 QIcon
        qDebug()<<1111;
        QIcon iconShow = QIcon(QPixmap::fromImage(image));
        //添加查看密码action
        actionShowPassword = ui->lineEditPassWord->addAction(iconShow, QLineEdit::TrailingPosition);
    }

    //加载用户名和密码
    getUserinfo(m_user,m_pwd);
    ui->lineEditUserName->setText(m_user);
    ui->lineEditPassWord->setText(m_pwd);
    if(m_pwd != ""){
        ui->Remember->setChecked(true);
    }

    //链接信号槽
    connect(actionShowPassword,&QAction::triggered,this,&DialogLogin::on_ActionShowPassword_triggered);
}

void DialogLogin::on_BtnRegister_clicked()
{
    // 创建注册界面
    DialogRegister dialogRegister(this);

    // 显示注册界面
    if (dialogRegister.exec() == QDialog::Accepted) {
        // 获取注册信息
        QString employeeID = dialogRegister.getEmployeeID();
        QString name = dialogRegister.getName();
        QString gender = dialogRegister.getGender();
        QString date = dialogRegister.getDate();
        QString department = dialogRegister.getDepartment();
        QString position = dialogRegister.getPosition();
        QString telephone = dialogRegister.getTelephone();
        QString email = dialogRegister.getEmail();
        QString photoPath = dialogRegister.getPhotoPath();
        QString password = dialogRegister.getPassword();
        QString role = dialogRegister.getRole();

        // 将注册信息插入数据库
        QString sql = QString("INSERT INTO employeeinfo VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11')")
                          .arg(employeeID)
                          .arg(name)
                          .arg(gender)
                          .arg(date)
                          .arg(department)
                          .arg(position)
                          .arg(telephone)
                          .arg(email)
                          .arg(photoPath)
                          .arg(Function::instance()->encrypt(password)) // 密码加密
                          .arg(role);

        qDebug()<<sql;
        if (mysql->MySql_Insert(sql)) {
            QMessageBox::information(this, "成功", "注册成功！");
        } else {
            QMessageBox::warning(this, "错误", "注册失败，请重试！");

        }
    }
}

void DialogLogin::on_ActionShowPassword_triggered()
{
    QIcon iconShow(":/images/查看密码.png");
    QIcon iconHide(":/images/密码修改-查看密码.png");
    if(ui->lineEditPassWord->echoMode() == QLineEdit::Password){
        ui->lineEditPassWord->setEchoMode(QLineEdit::Normal);
        actionShowPassword->setIcon(iconHide);
    }else if(ui->lineEditPassWord->echoMode() == QLineEdit::Normal){
        ui->lineEditPassWord->setEchoMode(QLineEdit::Password);
        actionShowPassword->setIcon(iconShow);
    }
}

void DialogLogin::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        // 如果BtnLogin可用，则触发点击事件
        if (ui->BtnLogin->isEnabled()) {
            ui->BtnLogin->click();
        }
    } else {
        // 其他按键事件交给父类处理
        QDialog::keyPressEvent(event);
    }
}

void DialogLogin::on_BtnModifyPwd_clicked()
{
    // 创建修改密码界面
    DialogFindPwd dialogFindPwd(this);

    // 显示修改密码界面
    dialogFindPwd.exec();
}

