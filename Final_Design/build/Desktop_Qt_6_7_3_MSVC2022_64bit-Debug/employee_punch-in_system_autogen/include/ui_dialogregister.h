/********************************************************************************
** Form generated from reading UI file 'dialogregister.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGREGISTER_H
#define UI_DIALOGREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogRegister
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *labelEmployeeID;
    QLineEdit *lineEditEmployeeID;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelGender;
    QComboBox *comboBoxGender;
    QLabel *labelDate;
    QDateEdit *dateEdit;
    QLabel *labelDepartment;
    QComboBox *comboBoxDepartment;
    QLabel *labelPosition;
    QComboBox *comboBoxPosition;
    QLabel *labelTelephone;
    QLineEdit *lineEditTelephone;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QLabel *labelPhoto;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditPhoto;
    QPushButton *BtnBrowse;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *labelRole;
    QComboBox *comboBoxRole;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BtnSubmit;
    QPushButton *BtnCancel;

    void setupUi(QDialog *DialogRegister)
    {
        if (DialogRegister->objectName().isEmpty())
            DialogRegister->setObjectName("DialogRegister");
        DialogRegister->resize(450, 550);
        DialogRegister->setStyleSheet(QString::fromUtf8("\n"
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
"    QLineEdit, QComboBox, QDateEdit {\n"
"        border: 1px solid #cccccc;\n"
"        border-radius: 4px;\n"
"        padding: 5px;\n"
"        font-size: 14px;\n"
"    }\n"
"    QLineEdit:focus, QComboBox:focus, QDateEdit:focus {\n"
"        border: 1px solid #0078d7;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #0078d7;\n"
"        color: white;\n"
"        border: none;\n"
"        border-radius: 4px;\n"
"        padding: 8px 16px;\n"
"        font-size: 14px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #005bb5;\n"
"    }\n"
" "
                        "   QPushButton:pressed {\n"
"        background-color: #004080;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(DialogRegister);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(DialogRegister);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        labelEmployeeID = new QLabel(groupBox);
        labelEmployeeID->setObjectName("labelEmployeeID");

        gridLayout->addWidget(labelEmployeeID, 0, 0, 1, 1);

        lineEditEmployeeID = new QLineEdit(groupBox);
        lineEditEmployeeID->setObjectName("lineEditEmployeeID");

        gridLayout->addWidget(lineEditEmployeeID, 0, 1, 1, 1);

        labelName = new QLabel(groupBox);
        labelName->setObjectName("labelName");

        gridLayout->addWidget(labelName, 1, 0, 1, 1);

        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName("lineEditName");

        gridLayout->addWidget(lineEditName, 1, 1, 1, 1);

        labelGender = new QLabel(groupBox);
        labelGender->setObjectName("labelGender");

        gridLayout->addWidget(labelGender, 2, 0, 1, 1);

        comboBoxGender = new QComboBox(groupBox);
        comboBoxGender->setObjectName("comboBoxGender");

        gridLayout->addWidget(comboBoxGender, 2, 1, 1, 1);

        labelDate = new QLabel(groupBox);
        labelDate->setObjectName("labelDate");

        gridLayout->addWidget(labelDate, 3, 0, 1, 1);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName("dateEdit");

        gridLayout->addWidget(dateEdit, 3, 1, 1, 1);

        labelDepartment = new QLabel(groupBox);
        labelDepartment->setObjectName("labelDepartment");

        gridLayout->addWidget(labelDepartment, 4, 0, 1, 1);

        comboBoxDepartment = new QComboBox(groupBox);
        comboBoxDepartment->setObjectName("comboBoxDepartment");

        gridLayout->addWidget(comboBoxDepartment, 4, 1, 1, 1);

        labelPosition = new QLabel(groupBox);
        labelPosition->setObjectName("labelPosition");

        gridLayout->addWidget(labelPosition, 5, 0, 1, 1);

        comboBoxPosition = new QComboBox(groupBox);
        comboBoxPosition->setObjectName("comboBoxPosition");

        gridLayout->addWidget(comboBoxPosition, 5, 1, 1, 1);

        labelTelephone = new QLabel(groupBox);
        labelTelephone->setObjectName("labelTelephone");

        gridLayout->addWidget(labelTelephone, 6, 0, 1, 1);

        lineEditTelephone = new QLineEdit(groupBox);
        lineEditTelephone->setObjectName("lineEditTelephone");

        gridLayout->addWidget(lineEditTelephone, 6, 1, 1, 1);

        labelEmail = new QLabel(groupBox);
        labelEmail->setObjectName("labelEmail");

        gridLayout->addWidget(labelEmail, 7, 0, 1, 1);

        lineEditEmail = new QLineEdit(groupBox);
        lineEditEmail->setObjectName("lineEditEmail");

        gridLayout->addWidget(lineEditEmail, 7, 1, 1, 1);

        labelPhoto = new QLabel(groupBox);
        labelPhoto->setObjectName("labelPhoto");

        gridLayout->addWidget(labelPhoto, 8, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEditPhoto = new QLineEdit(groupBox);
        lineEditPhoto->setObjectName("lineEditPhoto");

        horizontalLayout->addWidget(lineEditPhoto);

        BtnBrowse = new QPushButton(groupBox);
        BtnBrowse->setObjectName("BtnBrowse");

        horizontalLayout->addWidget(BtnBrowse);


        gridLayout->addLayout(horizontalLayout, 8, 1, 1, 1);

        labelPassword = new QLabel(groupBox);
        labelPassword->setObjectName("labelPassword");

        gridLayout->addWidget(labelPassword, 9, 0, 1, 1);

        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditPassword, 9, 1, 1, 1);

        labelRole = new QLabel(groupBox);
        labelRole->setObjectName("labelRole");

        gridLayout->addWidget(labelRole, 10, 0, 1, 1);

        comboBoxRole = new QComboBox(groupBox);
        comboBoxRole->setObjectName("comboBoxRole");

        gridLayout->addWidget(comboBoxRole, 10, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        BtnSubmit = new QPushButton(DialogRegister);
        BtnSubmit->setObjectName("BtnSubmit");
        BtnSubmit->setAutoDefault(false);

        horizontalLayout_2->addWidget(BtnSubmit);

        BtnCancel = new QPushButton(DialogRegister);
        BtnCancel->setObjectName("BtnCancel");

        horizontalLayout_2->addWidget(BtnCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DialogRegister);
        QObject::connect(BtnCancel, &QPushButton::clicked, DialogRegister, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogRegister);
    } // setupUi

    void retranslateUi(QDialog *DialogRegister)
    {
        DialogRegister->setWindowTitle(QCoreApplication::translate("DialogRegister", "\346\263\250\345\206\214", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogRegister", "\346\263\250\345\206\214\344\277\241\346\201\257", nullptr));
        labelEmployeeID->setText(QCoreApplication::translate("DialogRegister", "\345\267\245\345\217\267\357\274\232", nullptr));
        labelName->setText(QCoreApplication::translate("DialogRegister", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelGender->setText(QCoreApplication::translate("DialogRegister", "\346\200\247\345\210\253\357\274\232", nullptr));
        labelDate->setText(QCoreApplication::translate("DialogRegister", "\346\227\245\346\234\237\357\274\232", nullptr));
        labelDepartment->setText(QCoreApplication::translate("DialogRegister", "\351\203\250\351\227\250\357\274\232", nullptr));
        labelPosition->setText(QCoreApplication::translate("DialogRegister", "\350\201\214\344\275\215\357\274\232", nullptr));
        labelTelephone->setText(QCoreApplication::translate("DialogRegister", "\347\224\265\350\257\235\357\274\232", nullptr));
        labelEmail->setText(QCoreApplication::translate("DialogRegister", "\351\202\256\347\256\261\357\274\232", nullptr));
        labelPhoto->setText(QCoreApplication::translate("DialogRegister", "\347\205\247\347\211\207\357\274\232", nullptr));
        BtnBrowse->setText(QCoreApplication::translate("DialogRegister", "\346\265\217\350\247\210", nullptr));
        labelPassword->setText(QCoreApplication::translate("DialogRegister", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelRole->setText(QCoreApplication::translate("DialogRegister", "\347\224\250\346\210\267\350\247\222\350\211\262\357\274\232", nullptr));
        BtnSubmit->setText(QCoreApplication::translate("DialogRegister", "\346\217\220\344\272\244", nullptr));
        BtnCancel->setText(QCoreApplication::translate("DialogRegister", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogRegister: public Ui_DialogRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGREGISTER_H
