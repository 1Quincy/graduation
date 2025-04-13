/********************************************************************************
** Form generated from reading UI file 'dialogleave.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLEAVE_H
#define UI_DIALOGLEAVE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogLeave
{
public:
    QGridLayout *gridLayout;
    QLabel *labelNo;
    QLabel *labelName;
    QHBoxLayout *horizontalLayout;
    QLabel *labelStartTime;
    QDateTimeEdit *dateTimeEditStart;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelEndTime;
    QDateTimeEdit *dateTimeEditEnd;
    QLabel *labelDays;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelReason;
    QPlainTextEdit *plainTextEditReason;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *BtnOk;
    QPushButton *BtnCancel;

    void setupUi(QDialog *DialogLeave)
    {
        if (DialogLeave->objectName().isEmpty())
            DialogLeave->setObjectName("DialogLeave");
        DialogLeave->resize(338, 341);
        DialogLeave->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #ffffff;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"}\n"
"QLabel {\n"
"    color: #222222; /* \346\233\264\346\267\261\347\232\204\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"    font-size: 16px; /* \350\277\233\344\270\200\346\255\245\345\242\236\345\244\247\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: normal; /* \345\217\226\346\266\210\345\212\240\347\262\227\357\274\214\351\201\277\345\205\215\346\250\241\347\263\212 */\n"
"}\n"
"QLineEdit, QDateTimeEdit, QPlainTextEdit {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #dddddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 16px; /* \350\277\233\344\270\200\346\255\245\345\242\236\345\244\247\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    color: #222222; /* \346\233\264\346\267\261\347\232\204\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"}\n"
"QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    color: #222222; /* \346"
                        "\233\264\346\267\261\347\232\204\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"    border: 1px solid #dddddd;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 16px; /* \350\277\233\344\270\200\346\255\245\345\242\236\345\244\247\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: normal; /* \345\217\226\346\266\210\345\212\240\347\262\227\357\274\214\351\201\277\345\205\215\346\250\241\347\263\212 */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"}"));
        gridLayout = new QGridLayout(DialogLeave);
        gridLayout->setObjectName("gridLayout");
        labelNo = new QLabel(DialogLeave);
        labelNo->setObjectName("labelNo");
        QFont font;
        font.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font.setPointSize(16);
        labelNo->setFont(font);

        gridLayout->addWidget(labelNo, 0, 0, 1, 1);

        labelName = new QLabel(DialogLeave);
        labelName->setObjectName("labelName");
        labelName->setFont(font);

        gridLayout->addWidget(labelName, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelStartTime = new QLabel(DialogLeave);
        labelStartTime->setObjectName("labelStartTime");
        labelStartTime->setFont(font);

        horizontalLayout->addWidget(labelStartTime);

        dateTimeEditStart = new QDateTimeEdit(DialogLeave);
        dateTimeEditStart->setObjectName("dateTimeEditStart");

        horizontalLayout->addWidget(dateTimeEditStart);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelEndTime = new QLabel(DialogLeave);
        labelEndTime->setObjectName("labelEndTime");
        labelEndTime->setFont(font);

        horizontalLayout_2->addWidget(labelEndTime);

        dateTimeEditEnd = new QDateTimeEdit(DialogLeave);
        dateTimeEditEnd->setObjectName("dateTimeEditEnd");

        horizontalLayout_2->addWidget(dateTimeEditEnd);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        labelDays = new QLabel(DialogLeave);
        labelDays->setObjectName("labelDays");
        labelDays->setFont(font);

        gridLayout->addWidget(labelDays, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelReason = new QLabel(DialogLeave);
        labelReason->setObjectName("labelReason");
        labelReason->setFont(font);

        horizontalLayout_3->addWidget(labelReason);

        plainTextEditReason = new QPlainTextEdit(DialogLeave);
        plainTextEditReason->setObjectName("plainTextEditReason");
        plainTextEditReason->setFont(font);

        horizontalLayout_3->addWidget(plainTextEditReason);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        BtnOk = new QPushButton(DialogLeave);
        BtnOk->setObjectName("BtnOk");
        BtnOk->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/ok.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnOk->setIcon(icon);

        horizontalLayout_4->addWidget(BtnOk);

        BtnCancel = new QPushButton(DialogLeave);
        BtnCancel->setObjectName("BtnCancel");
        BtnCancel->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/\345\217\226\346\266\210.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnCancel->setIcon(icon1);

        horizontalLayout_4->addWidget(BtnCancel);


        gridLayout->addLayout(horizontalLayout_4, 6, 0, 1, 1);


        retranslateUi(DialogLeave);

        QMetaObject::connectSlotsByName(DialogLeave);
    } // setupUi

    void retranslateUi(QDialog *DialogLeave)
    {
        DialogLeave->setWindowTitle(QCoreApplication::translate("DialogLeave", "\350\257\267\345\201\207", nullptr));
        labelNo->setText(QCoreApplication::translate("DialogLeave", "\345\267\245\345\217\267\357\274\232", nullptr));
        labelName->setText(QCoreApplication::translate("DialogLeave", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelStartTime->setText(QCoreApplication::translate("DialogLeave", "\350\257\267\345\201\207\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        labelEndTime->setText(QCoreApplication::translate("DialogLeave", "\350\257\267\345\201\207\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", nullptr));
        labelDays->setText(QCoreApplication::translate("DialogLeave", "\350\257\267\345\201\207\345\244\251\346\225\260\357\274\232", nullptr));
        labelReason->setText(QCoreApplication::translate("DialogLeave", "\350\257\267\345\201\207\347\220\206\347\224\261\357\274\232", nullptr));
        BtnOk->setText(QCoreApplication::translate("DialogLeave", "\347\241\256\345\256\232", nullptr));
        BtnCancel->setText(QCoreApplication::translate("DialogLeave", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogLeave: public Ui_DialogLeave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLEAVE_H
