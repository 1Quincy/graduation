/********************************************************************************
** Form generated from reading UI file 'dialogsignin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSIGNIN_H
#define UI_DIALOGSIGNIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSignIn
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *labelPhoto;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelNo;
    QLabel *labelName;
    QLabel *labelDate;
    QLabel *labelTime;
    QHBoxLayout *horizontalLayout;
    QPushButton *BtnOk;
    QPushButton *BtnCancel;

    void setupUi(QDialog *DialogSignIn)
    {
        if (DialogSignIn->objectName().isEmpty())
            DialogSignIn->setObjectName("DialogSignIn");
        DialogSignIn->resize(267, 347);
        DialogSignIn->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #ffffff;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"}\n"
"QLabel {\n"
"    color: #222222; /* \346\233\264\346\267\261\347\232\204\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"    font-size: 16px; /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: bold; /* \344\277\235\347\225\231\345\212\240\347\262\227 */\n"
"}\n"
"QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    color: #222222; /* \346\233\264\346\267\261\347\232\204\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"    border: 1px solid #dddddd;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 16px; /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: bold; /* \344\277\235\347\225\231\345\212\240\347\262\227 */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"}"));
        verticalLayout = new QVBoxLayout(DialogSignIn);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labelPhoto = new QLabel(DialogSignIn);
        labelPhoto->setObjectName("labelPhoto");
        labelPhoto->setStyleSheet(QString::fromUtf8("border: 2px solid #dddddd; border-radius: 5px;"));

        horizontalLayout_2->addWidget(labelPhoto);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        labelNo = new QLabel(DialogSignIn);
        labelNo->setObjectName("labelNo");
        QFont font;
        font.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font.setPointSize(14);
        labelNo->setFont(font);

        verticalLayout->addWidget(labelNo);

        labelName = new QLabel(DialogSignIn);
        labelName->setObjectName("labelName");
        labelName->setFont(font);

        verticalLayout->addWidget(labelName);

        labelDate = new QLabel(DialogSignIn);
        labelDate->setObjectName("labelDate");
        labelDate->setFont(font);

        verticalLayout->addWidget(labelDate);

        labelTime = new QLabel(DialogSignIn);
        labelTime->setObjectName("labelTime");
        labelTime->setFont(font);

        verticalLayout->addWidget(labelTime);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        BtnOk = new QPushButton(DialogSignIn);
        BtnOk->setObjectName("BtnOk");
        BtnOk->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/ok.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnOk->setIcon(icon);

        horizontalLayout->addWidget(BtnOk);

        BtnCancel = new QPushButton(DialogSignIn);
        BtnCancel->setObjectName("BtnCancel");
        BtnCancel->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/\345\217\226\346\266\210.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnCancel->setIcon(icon1);

        horizontalLayout->addWidget(BtnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogSignIn);

        QMetaObject::connectSlotsByName(DialogSignIn);
    } // setupUi

    void retranslateUi(QDialog *DialogSignIn)
    {
        DialogSignIn->setWindowTitle(QCoreApplication::translate("DialogSignIn", "\347\255\276\345\210\260", nullptr));
        labelPhoto->setText(QString());
        labelNo->setText(QCoreApplication::translate("DialogSignIn", "\345\267\245\345\217\267\357\274\232", nullptr));
        labelName->setText(QCoreApplication::translate("DialogSignIn", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelDate->setText(QCoreApplication::translate("DialogSignIn", "\347\255\276\345\210\260\346\227\245\346\234\237\357\274\232", nullptr));
        labelTime->setText(QCoreApplication::translate("DialogSignIn", "\347\255\276\345\210\260\346\227\266\351\227\264\357\274\232", nullptr));
        BtnOk->setText(QCoreApplication::translate("DialogSignIn", "\347\255\276\345\210\260", nullptr));
        BtnCancel->setText(QCoreApplication::translate("DialogSignIn", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSignIn: public Ui_DialogSignIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSIGNIN_H
