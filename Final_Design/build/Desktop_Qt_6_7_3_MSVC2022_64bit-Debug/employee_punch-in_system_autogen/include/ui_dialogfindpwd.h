/********************************************************************************
** Form generated from reading UI file 'dialogfindpwd.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFINDPWD_H
#define UI_DIALOGFINDPWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogFindPwd
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *userLabel;
    QLineEdit *userLineEdit;
    QLabel *oldPwdLabel;
    QLineEdit *oldPwdLineEdit;
    QLabel *newPwdLabel;
    QLineEdit *newPwdLineEdit;
    QLabel *confirmPwdLabel;
    QLineEdit *confirmPwdLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacerLeft;
    QPushButton *BtnOK;
    QPushButton *BtnCancel;
    QSpacerItem *horizontalSpacerRight;

    void setupUi(QDialog *DialogFindPwd)
    {
        if (DialogFindPwd->objectName().isEmpty())
            DialogFindPwd->setObjectName("DialogFindPwd");
        DialogFindPwd->resize(400, 350);
        DialogFindPwd->setStyleSheet(QString::fromUtf8("\n"
"    QDialog {\n"
"        background-color: #f5f5f5;\n"
"        font-family: \"Segoe UI\";\n"
"        font-size: 14px;\n"
"    }\n"
"    QGroupBox {\n"
"        border: 2px solid #0078d7;\n"
"        border-radius: 8px;\n"
"        margin-top: 10px;\n"
"        padding-top: 15px;\n"
"        font-size: 16px;\n"
"        font-weight: bold;\n"
"        color: #0078d7;\n"
"    }\n"
"    QLabel {\n"
"        color: #333333;\n"
"    }\n"
"    QLineEdit {\n"
"        border: 1px solid #cccccc;\n"
"        border-radius: 4px;\n"
"        padding: 5px;\n"
"        font-size: 14px;\n"
"        min-height: 28px;\n"
"    }\n"
"    QLineEdit:focus {\n"
"        border: 1px solid #0078d7;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #0078d7;\n"
"        color: white;\n"
"        border: none;\n"
"        border-radius: 4px;\n"
"        padding: 8px 16px;\n"
"        min-width: 80px;\n"
"        min-height: 34px;\n"
"        font-size: 14px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        backgroun"
                        "d-color: #005bb5;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #004080;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(DialogFindPwd);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(DialogFindPwd);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(10);
        gridLayout->setHorizontalSpacing(15);
        userLabel = new QLabel(groupBox);
        userLabel->setObjectName("userLabel");

        gridLayout->addWidget(userLabel, 0, 0, 1, 1);

        userLineEdit = new QLineEdit(groupBox);
        userLineEdit->setObjectName("userLineEdit");

        gridLayout->addWidget(userLineEdit, 0, 1, 1, 1);

        oldPwdLabel = new QLabel(groupBox);
        oldPwdLabel->setObjectName("oldPwdLabel");

        gridLayout->addWidget(oldPwdLabel, 1, 0, 1, 1);

        oldPwdLineEdit = new QLineEdit(groupBox);
        oldPwdLineEdit->setObjectName("oldPwdLineEdit");
        oldPwdLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(oldPwdLineEdit, 1, 1, 1, 1);

        newPwdLabel = new QLabel(groupBox);
        newPwdLabel->setObjectName("newPwdLabel");

        gridLayout->addWidget(newPwdLabel, 2, 0, 1, 1);

        newPwdLineEdit = new QLineEdit(groupBox);
        newPwdLineEdit->setObjectName("newPwdLineEdit");
        newPwdLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(newPwdLineEdit, 2, 1, 1, 1);

        confirmPwdLabel = new QLabel(groupBox);
        confirmPwdLabel->setObjectName("confirmPwdLabel");

        gridLayout->addWidget(confirmPwdLabel, 3, 0, 1, 1);

        confirmPwdLineEdit = new QLineEdit(groupBox);
        confirmPwdLineEdit->setObjectName("confirmPwdLineEdit");
        confirmPwdLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(confirmPwdLineEdit, 3, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacerLeft);

        BtnOK = new QPushButton(DialogFindPwd);
        BtnOK->setObjectName("BtnOK");

        horizontalLayout->addWidget(BtnOK);

        BtnCancel = new QPushButton(DialogFindPwd);
        BtnCancel->setObjectName("BtnCancel");

        horizontalLayout->addWidget(BtnCancel);

        horizontalSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacerRight);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogFindPwd);

        QMetaObject::connectSlotsByName(DialogFindPwd);
    } // setupUi

    void retranslateUi(QDialog *DialogFindPwd)
    {
        DialogFindPwd->setWindowTitle(QCoreApplication::translate("DialogFindPwd", "\345\257\206\347\240\201\351\207\215\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogFindPwd", "\345\257\206\347\240\201\351\207\215\347\275\256", nullptr));
        userLabel->setText(QCoreApplication::translate("DialogFindPwd", "\350\264\246\345\217\267\357\274\232", nullptr));
        oldPwdLabel->setText(QCoreApplication::translate("DialogFindPwd", "\345\216\237\345\257\206\347\240\201\357\274\232", nullptr));
        newPwdLabel->setText(QCoreApplication::translate("DialogFindPwd", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        confirmPwdLabel->setText(QCoreApplication::translate("DialogFindPwd", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        BtnOK->setText(QCoreApplication::translate("DialogFindPwd", "\347\241\256\350\256\244", nullptr));
        BtnCancel->setText(QCoreApplication::translate("DialogFindPwd", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFindPwd: public Ui_DialogFindPwd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFINDPWD_H
