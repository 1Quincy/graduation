#include "dialogmodifyinfo.h"
#include "ui_dialogmodifyinfo.h"
#include "mysql.h"
#include "userinfo.h"
#include "qsqlquery.h"
#include "qsqlerror.h"
#include "qmessagebox.h"
#include "qregularexpression.h"
#include "QMouseEvent"
#include "qfiledialog.h"
#include "QPixmap"

DialogModifyInfo::DialogModifyInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogModifyInfo)
{
    ui->setupUi(this);
    init();
}

DialogModifyInfo::~DialogModifyInfo()
{
    delete ui;
}

void DialogModifyInfo::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPoint pos = event->pos();
        if (ui->photo->geometry().contains(pos)) {
            emit photoClicked();
        }
    }
    QDialog::mousePressEvent(event);
}

void DialogModifyInfo::init()
{
    ui->photo->setPixmap(QPixmap(usr.getPhotograph()));
    ui->nameLineEdit->setText(usr.getUsername());
    ui->noLineEdit->setText(usr.getNo());
    ui->departmentLineEdit->setText(usr.getDepartment());
    ui->genderLineEdit->setText(usr.getGender());
    ui->emailLineEdit->setText(usr.getEmail());
    ui->positionLineEdit->setText(usr.getPosition());
    ui->telephoneLineEdit->setText(usr.getTelephone());

    telephone = usr.getTelephone();
    email = usr.getEmail();
    photoPath = usr.getPhotograph();
    photo = QPixmap(usr.getPhotograph());

    connect(this,&DialogModifyInfo::photoClicked,this,&DialogModifyInfo::onPhotoLabelClicked);
}

bool DialogModifyInfo::isPixmapEqual(const QPixmap &pixmap1, const QPixmap &pixmap2)
{
    //比较两个Pixmap是否相等
    if (pixmap1.isNull() && pixmap2.isNull()) {
        return true;
    }
    if (pixmap1.isNull() || pixmap2.isNull()) {
        return false;
    }
    QImage image1 = pixmap1.toImage();
    QImage image2 = pixmap2.toImage();
    return image1 == image2;
}

void DialogModifyInfo::on_BtnOK_clicked()
{
    //如果未更改则直接结束
    if(telephone == ui->telephoneLineEdit->text() && email == ui->emailLineEdit->text() && isPixmapEqual(photo,ui->photo->pixmap())){
        this->accept();
        return;
    }

    //检查邮箱是否有效
    QString email = ui->emailLineEdit->text();
    QRegularExpression emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    if (!emailRegex.match(email).hasMatch()) {
        // 邮箱格式错误
        QMessageBox::warning(this, "错误", "请输入有效的邮箱地址！");
        // this->reject();
        return;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "询问", "确定更改吗？",
                                  QMessageBox::Yes | QMessageBox::No);

    //如果确认
    if(reply == QMessageBox::Yes){
        QSqlDatabase db = MySql::instance()->getDatabase();
        QSqlQuery sql(db);

        qDebug()<<"accept";

        // 使用占位符（如:send, :receive）
        sql.prepare("update employeeinfo set telephone = :tel ,Email = :email,photograph = :pto where employeeNO = :ID");

        // 绑定参数（自动处理转义和类型）
        sql.bindValue(":ID", ui->noLineEdit->text());
        sql.bindValue(":tel", ui->telephoneLineEdit->text());
        sql.bindValue(":email", ui->emailLineEdit->text());
        sql.bindValue(":pto", photoPath);

        if (sql.exec()) {
            // 更新成功
            qDebug() << "更新成功，行数:" << sql.numRowsAffected();
        } else {
            // 获取详细错误信息
            QSqlError error = sql.lastError();
            qDebug() << "SQL 错误:" << error.text();
            qDebug() << "错误代码:" << error.nativeErrorCode();
        }

        //更新当前程序用户信息
        usr.setEmail(ui->emailLineEdit->text());
        usr.setTelephone(ui->telephoneLineEdit->text());
        usr.setPhotograph(photoPath);

    }else{
        return;
    }

    this->accept();
}


void DialogModifyInfo::on_BtnCancel_clicked()
{
    this->close();
}

void DialogModifyInfo::onPhotoLabelClicked()
{
    // 打开文件对话框选择照片
    photoPath = QFileDialog::getOpenFileName(this, "选择照片", "", "Images (*.png *.jpg *.bmp)");
    if (!photoPath.isEmpty()) {
        ui->photo->setPixmap(QPixmap(photoPath));
    }
}

