/********************************************************************************
** Form generated from reading UI file 'dialogmodifyinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODIFYINFO_H
#define UI_DIALOGMODIFYINFO_H

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

class Ui_DialogModifyInfo
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *photo;
    QLabel *noLabel;
    QLineEdit *noLineEdit;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *genderLabel;
    QLineEdit *genderLineEdit;
    QLabel *departmentLabel;
    QLineEdit *departmentLineEdit;
    QLabel *positionLabel;
    QLineEdit *positionLineEdit;
    QLabel *telephoneLabel;
    QLineEdit *telephoneLineEdit;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacerLeft;
    QPushButton *BtnOK;
    QPushButton *BtnCancel;
    QSpacerItem *horizontalSpacerRight;

    void setupUi(QDialog *DialogModifyInfo)
    {
        if (DialogModifyInfo->objectName().isEmpty())
            DialogModifyInfo->setObjectName("DialogModifyInfo");
        DialogModifyInfo->resize(413, 484);
        DialogModifyInfo->setStyleSheet(QString::fromUtf8("\n"
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
"    QLineEdit:disabled {\n"
"        background-color: #eeeeee;\n"
"        color: #666666;\n"
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
"        "
                        "min-height: 34px;\n"
"        font-size: 14px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #005bb5;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #004080;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(DialogModifyInfo);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(DialogModifyInfo);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setVerticalSpacing(10);
        photo = new QLabel(groupBox);
        photo->setObjectName("photo");
        photo->setStyleSheet(QString::fromUtf8("background-color: white; border: 1px dashed #cccccc;"));
        photo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(photo, 0, 0, 1, 2);

        noLabel = new QLabel(groupBox);
        noLabel->setObjectName("noLabel");

        gridLayout->addWidget(noLabel, 1, 0, 1, 1);

        noLineEdit = new QLineEdit(groupBox);
        noLineEdit->setObjectName("noLineEdit");
        noLineEdit->setEnabled(false);

        gridLayout->addWidget(noLineEdit, 1, 1, 1, 1);

        nameLabel = new QLabel(groupBox);
        nameLabel->setObjectName("nameLabel");

        gridLayout->addWidget(nameLabel, 2, 0, 1, 1);

        nameLineEdit = new QLineEdit(groupBox);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setEnabled(false);

        gridLayout->addWidget(nameLineEdit, 2, 1, 1, 1);

        genderLabel = new QLabel(groupBox);
        genderLabel->setObjectName("genderLabel");

        gridLayout->addWidget(genderLabel, 3, 0, 1, 1);

        genderLineEdit = new QLineEdit(groupBox);
        genderLineEdit->setObjectName("genderLineEdit");
        genderLineEdit->setEnabled(false);

        gridLayout->addWidget(genderLineEdit, 3, 1, 1, 1);

        departmentLabel = new QLabel(groupBox);
        departmentLabel->setObjectName("departmentLabel");

        gridLayout->addWidget(departmentLabel, 4, 0, 1, 1);

        departmentLineEdit = new QLineEdit(groupBox);
        departmentLineEdit->setObjectName("departmentLineEdit");
        departmentLineEdit->setEnabled(false);

        gridLayout->addWidget(departmentLineEdit, 4, 1, 1, 1);

        positionLabel = new QLabel(groupBox);
        positionLabel->setObjectName("positionLabel");

        gridLayout->addWidget(positionLabel, 5, 0, 1, 1);

        positionLineEdit = new QLineEdit(groupBox);
        positionLineEdit->setObjectName("positionLineEdit");
        positionLineEdit->setEnabled(false);

        gridLayout->addWidget(positionLineEdit, 5, 1, 1, 1);

        telephoneLabel = new QLabel(groupBox);
        telephoneLabel->setObjectName("telephoneLabel");

        gridLayout->addWidget(telephoneLabel, 6, 0, 1, 1);

        telephoneLineEdit = new QLineEdit(groupBox);
        telephoneLineEdit->setObjectName("telephoneLineEdit");

        gridLayout->addWidget(telephoneLineEdit, 6, 1, 1, 1);

        emailLabel = new QLabel(groupBox);
        emailLabel->setObjectName("emailLabel");

        gridLayout->addWidget(emailLabel, 7, 0, 1, 1);

        emailLineEdit = new QLineEdit(groupBox);
        emailLineEdit->setObjectName("emailLineEdit");

        gridLayout->addWidget(emailLineEdit, 7, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacerLeft);

        BtnOK = new QPushButton(DialogModifyInfo);
        BtnOK->setObjectName("BtnOK");

        horizontalLayout->addWidget(BtnOK);

        BtnCancel = new QPushButton(DialogModifyInfo);
        BtnCancel->setObjectName("BtnCancel");

        horizontalLayout->addWidget(BtnCancel);

        horizontalSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacerRight);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogModifyInfo);

        QMetaObject::connectSlotsByName(DialogModifyInfo);
    } // setupUi

    void retranslateUi(QDialog *DialogModifyInfo)
    {
        DialogModifyInfo->setWindowTitle(QCoreApplication::translate("DialogModifyInfo", "\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogModifyInfo", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        photo->setText(QCoreApplication::translate("DialogModifyInfo", "[\347\205\247\347\211\207\351\242\204\350\247\210]", nullptr));
        noLabel->setText(QCoreApplication::translate("DialogModifyInfo", "\345\267\245\345\217\267\357\274\232", nullptr));
        nameLabel->setText(QCoreApplication::translate("DialogModifyInfo", "\345\247\223\345\220\215\357\274\232", nullptr));
        genderLabel->setText(QCoreApplication::translate("DialogModifyInfo", "\346\200\247\345\210\253\357\274\232", nullptr));
        departmentLabel->setText(QCoreApplication::translate("DialogModifyInfo", "\351\203\250\351\227\250\357\274\232", nullptr));
        positionLabel->setText(QCoreApplication::translate("DialogModifyInfo", "\350\201\214\344\275\215\357\274\232", nullptr));
        telephoneLabel->setText(QCoreApplication::translate("DialogModifyInfo", "\347\224\265\350\257\235\357\274\232", nullptr));
        emailLabel->setText(QCoreApplication::translate("DialogModifyInfo", "\351\202\256\347\256\261\357\274\232", nullptr));
        emailLineEdit->setPlaceholderText(QCoreApplication::translate("DialogModifyInfo", "example@domain.com", nullptr));
        BtnOK->setText(QCoreApplication::translate("DialogModifyInfo", "\347\241\256\350\256\244", nullptr));
        BtnCancel->setText(QCoreApplication::translate("DialogModifyInfo", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogModifyInfo: public Ui_DialogModifyInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODIFYINFO_H
