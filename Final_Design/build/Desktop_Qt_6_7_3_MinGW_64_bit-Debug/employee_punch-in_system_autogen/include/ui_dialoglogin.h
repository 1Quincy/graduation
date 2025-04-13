/********************************************************************************
** Form generated from reading UI file 'dialoglogin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLOGIN_H
#define UI_DIALOGLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogLogin
{
public:
    QPushButton *BtnRegister;
    QLabel *labelBackGround;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUserName;
    QLineEdit *lineEditUserName;
    QPushButton *BtnLogin;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPassWord;
    QLineEdit *lineEditPassWord;
    QPushButton *BtnCancel;

    void setupUi(QDialog *DialogLogin)
    {
        if (DialogLogin->objectName().isEmpty())
            DialogLogin->setObjectName("DialogLogin");
        DialogLogin->resize(788, 501);
        DialogLogin->setMinimumSize(QSize(0, 0));
        DialogLogin->setMaximumSize(QSize(10000, 10000));
        DialogLogin->setAutoFillBackground(true);
        BtnRegister = new QPushButton(DialogLogin);
        BtnRegister->setObjectName("BtnRegister");
        BtnRegister->setGeometry(QRect(670, 330, 81, 25));
        QFont font;
        font.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font.setPointSize(10);
        font.setBold(false);
        BtnRegister->setFont(font);
        BtnRegister->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}"));
        labelBackGround = new QLabel(DialogLogin);
        labelBackGround->setObjectName("labelBackGround");
        labelBackGround->setGeometry(QRect(-30, -10, 848, 521));
        labelBackGround->setMinimumSize(QSize(0, 0));
        labelBackGround->setMaximumSize(QSize(10000, 10000));
        labelBackGround->setAutoFillBackground(false);
        labelBackGround->setStyleSheet(QString::fromUtf8("background-image: url(:/images/\347\231\273\345\275\225.jpg); background-repeat: no-repeat; \n"
"background-position: center;"));
        labelBackGround->setFrameShape(QFrame::Panel);
        labelBackGround->setLineWidth(2);
        labelBackGround->setScaledContents(true);
        layoutWidget = new QWidget(DialogLogin);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(451, 241, 302, 82));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelUserName = new QLabel(layoutWidget);
        labelUserName->setObjectName("labelUserName");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font1.setPointSize(12);
        font1.setBold(true);
        labelUserName->setFont(font1);
        labelUserName->setStyleSheet(QString::fromUtf8("color: #2c3e50;"));

        horizontalLayout->addWidget(labelUserName);

        lineEditUserName = new QLineEdit(layoutWidget);
        lineEditUserName->setObjectName("lineEditUserName");
        QFont font2;
        font2.setPointSize(11);
        lineEditUserName->setFont(font2);
        lineEditUserName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #2c3e50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));
        lineEditUserName->setMaxLength(10);

        horizontalLayout->addWidget(lineEditUserName);

        BtnLogin = new QPushButton(layoutWidget);
        BtnLogin->setObjectName("BtnLogin");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font3.setPointSize(11);
        font3.setBold(true);
        BtnLogin->setFont(font3);
        BtnLogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/login2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnLogin->setIcon(icon);

        horizontalLayout->addWidget(BtnLogin);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelPassWord = new QLabel(layoutWidget);
        labelPassWord->setObjectName("labelPassWord");
        labelPassWord->setFont(font1);
        labelPassWord->setStyleSheet(QString::fromUtf8("color: #2c3e50;"));

        horizontalLayout_2->addWidget(labelPassWord);

        lineEditPassWord = new QLineEdit(layoutWidget);
        lineEditPassWord->setObjectName("lineEditPassWord");
        lineEditPassWord->setFont(font2);
        lineEditPassWord->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #2c3e50;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));
        lineEditPassWord->setMaxLength(20);

        horizontalLayout_2->addWidget(lineEditPassWord);

        BtnCancel = new QPushButton(layoutWidget);
        BtnCancel->setObjectName("BtnCancel");
        BtnCancel->setFont(font3);
        BtnCancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e74c3c;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #c0392b;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cancel.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnCancel->setIcon(icon1);

        horizontalLayout_2->addWidget(BtnCancel);


        verticalLayout->addLayout(horizontalLayout_2);

        labelBackGround->raise();
        layoutWidget->raise();
        BtnRegister->raise();

        retranslateUi(DialogLogin);

        QMetaObject::connectSlotsByName(DialogLogin);
    } // setupUi

    void retranslateUi(QDialog *DialogLogin)
    {
        DialogLogin->setWindowTitle(QCoreApplication::translate("DialogLogin", "\350\201\214\345\267\245\350\200\203\345\213\244\345\271\263\345\217\260", nullptr));
        BtnRegister->setText(QCoreApplication::translate("DialogLogin", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        labelBackGround->setText(QString());
        labelUserName->setText(QCoreApplication::translate("DialogLogin", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        BtnLogin->setText(QCoreApplication::translate("DialogLogin", "\347\231\273\345\275\225", nullptr));
        labelPassWord->setText(QCoreApplication::translate("DialogLogin", "\345\257\206  \347\240\201\357\274\232", nullptr));
        BtnCancel->setText(QCoreApplication::translate("DialogLogin", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogLogin: public Ui_DialogLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLOGIN_H
