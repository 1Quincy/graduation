#include "dialogregister.h"
#include "ui_dialogregister.h"
#include <QDate>
#include "QCryptographicHash"
#include "QComboBox"

DialogRegister::DialogRegister(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogRegister)
{
    ui->setupUi(this);

    Init();
}

DialogRegister::~DialogRegister()
{
    delete ui;
}

void DialogRegister::Init()
{
    // 设置日期为当天
    ui->dateEdit->setDate(QDate::currentDate());

    //设置不可修改注册日期
    ui->dateEdit->setEnabled(false);

    // 设置性别选项
    ui->comboBoxGender->addItem("男");
    ui->comboBoxGender->addItem("女");

    // 设置用户角色选项
    ui->comboBoxRole->addItem("员工");
    ui->comboBoxRole->addItem("管理员");

    //设置部门选项
    ui->comboBoxDepartment->addItem("行政部");
    ui->comboBoxDepartment->addItem("财政部");
    ui->comboBoxDepartment->addItem("技术部");

    //设置职位选项
    ui->comboBoxPosition->clear();
    ui->comboBoxPosition->addItem("行政经理");
    ui->comboBoxPosition->addItem("行政主管");
    ui->comboBoxPosition->addItem("行政助理");
    ui->comboBoxPosition->addItem("文件档案专员");

    //链接信号与槽函数
    connect(ui->comboBoxDepartment, QOverload<int>::of(&QComboBox::currentIndexChanged),  //当 QComboBox 的当前选项发生变化时，它会发出 currentIndexChanged 信号。
            /* QComboBox::currentIndexChanged 是一个重载信号，有两种形式：
                    currentIndexChanged(int index)：带有当前索引的参数。
                    currentIndexChanged(const QString &text)：带有当前文本的参数。
                    由于信号是重载的，直接使用 &QComboBox::currentIndexChanged 会导致编译器无法确定使用哪个重载版本。
                    QOverload<int>::of 是 Qt 提供的一个辅助函数，用于明确选择 currentIndexChanged(int index) 这个重载版本。*/
            this, &DialogRegister::on_comboBoxDepartment_currentIndexChanged);
    //设置lineEditPhoto不可输入
    ui->lineEditPhoto->setEnabled(false);

    //设置密码框输入模式
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);

    //设置浅灰色提示文本
    ui->lineEditEmployeeID->setPlaceholderText("请输入工号");
    ui->lineEditName->setPlaceholderText("请输入姓名");
    ui->lineEditTelephone->setPlaceholderText("请输入电话");
    ui->lineEditEmail->setPlaceholderText("请输入邮箱");
    ui->lineEditPassword->setPlaceholderText("请输入密码");
    ui->lineEditPhoto->setPlaceholderText("请选择一个照片");

    //限制lineEdit的输入位数
    ui->lineEditEmployeeID->setMaxLength(5);
    ui->lineEditName->setMaxLength(20);
    ui->lineEditTelephone->setMaxLength(20);
    ui->lineEditEmail->setMaxLength(50);
    ui->lineEditPassword->setMaxLength(20);

}

QString DialogRegister::getEmployeeID() const {
    return ui->lineEditEmployeeID->text();
}

QString DialogRegister::getName() const {
    return ui->lineEditName->text();
}

QString DialogRegister::getGender() const {
    return ui->comboBoxGender->currentText();
}

QString DialogRegister::getDate() const {
    return ui->dateEdit->date().toString("yyyy-MM-dd");
}

QString DialogRegister::getDepartment() const {
    return ui->comboBoxDepartment->currentText();
}

QString DialogRegister::getPosition() const {
    return ui->comboBoxPosition->currentText();;
}

QString DialogRegister::getTelephone() const {
    return ui->lineEditTelephone->text();
}

QString DialogRegister::getEmail() const {
    return ui->lineEditEmail->text();
}

QString DialogRegister::getPhotoPath() const {
    return ui->lineEditPhoto->text();
}

QString DialogRegister::getPassword() const {
    return ui->lineEditPassword->text();
}

QString DialogRegister::getRole() const {
    return ui->comboBoxRole->currentText();
}

QString DialogRegister::encrypt(const QString &str)
{
    // MD5加密
    QByteArray array;
    array.append(str.toUtf8());
    QCryptographicHash hash(QCryptographicHash::Md5); // 设置hash的加密算法
    hash.addData(array);

    QByteArray resultArray = hash.result();
    QString md5 = resultArray.toHex(); // 转成16进制字符串
    return md5;
}

void DialogRegister::on_BtnBrowse_clicked()
{
    // 打开文件对话框选择照片
    QString photoPath = QFileDialog::getOpenFileName(this, "选择照片", "", "Images (*.png *.jpg *.bmp)");
    if (!photoPath.isEmpty()) {
        ui->lineEditPhoto->setText(photoPath);
    }
}

void DialogRegister::on_BtnSubmit_clicked()
{
    // 检查必填项是否为空
    if (ui->lineEditEmployeeID->text().isEmpty() ||
        ui->lineEditName->text().isEmpty() ||
        ui->lineEditPassword->text().isEmpty()) {
        QMessageBox::warning(this, "警告", "工号、姓名和密码不能为空！");
        return;
    }

    //检查邮箱是否有效
    QString email = ui->lineEditEmail->text();
    QRegularExpression emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    if (!emailRegex.match(email).hasMatch()) {
        // 邮箱格式错误
        QMessageBox::warning(this, "错误", "请输入有效的邮箱地址！");
       // this->reject();
        return;
    }

    /*
    //存储注册信息
    QString insert = QString("insert into employeeinfo values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11')")
                            .arg(getEmployeeID())
                            .arg(getName())
                            .arg(getGender())
                            .arg(getDate())
                            .arg(getDepartment())
                            .arg(getPosition())
                            .arg(getTelephone())
                            .arg(getEmail())
                            .arg(getPhotoPath())
                            .arg(encrypt(getPassword()))
                            .arg(getRole());
    qDebug()<<insert;
    */

    // 提交注册信息
    accept();
}

void DialogRegister::on_BtnCancel_clicked()
{
    // 取消注册
    reject();
}

void DialogRegister::on_comboBoxDepartment_currentIndexChanged(int index)
{
    if(ui->comboBoxDepartment->currentText() == "财政部"){
        //设置职位选项
        ui->comboBoxPosition->clear();
        ui->comboBoxPosition->addItem("财务负责人");
        ui->comboBoxPosition->addItem("会计");
        ui->comboBoxPosition->addItem("出纳");
    }else if(ui->comboBoxDepartment->currentText()  == "行政部"){
        //设置职位选项
        ui->comboBoxPosition->clear();
        ui->comboBoxPosition->addItem("行政经理");
        ui->comboBoxPosition->addItem("行政主管");
        ui->comboBoxPosition->addItem("行政助理");
        ui->comboBoxPosition->addItem("文件档案专员");
    }else if(ui->comboBoxDepartment->currentText()  == "技术部"){
        //设置职位选项
        ui->comboBoxPosition->clear();
        ui->comboBoxPosition->addItem("项目经理");
        ui->comboBoxPosition->addItem("技术工程师");
        ui->comboBoxPosition->addItem("软件工程师");
        ui->comboBoxPosition->addItem("程序员");
    }
}
