/********************************************************************************
** Form generated from reading UI file 'dialogsignout.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSIGNOUT_H
#define UI_DIALOGSIGNOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSignOut
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *labelPhoto;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelNo;
    QLabel *labelName;
    QLabel *labelDate;
    QLabel *labelTime;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *BtnOk;
    QPushButton *BtnCancel;

    void setupUi(QDialog *DialogSignOut)
    {
        if (DialogSignOut->objectName().isEmpty())
            DialogSignOut->setObjectName("DialogSignOut");
        DialogSignOut->resize(400, 300);
        DialogSignOut->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
        gridLayout = new QGridLayout(DialogSignOut);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labelPhoto = new QLabel(DialogSignOut);
        labelPhoto->setObjectName("labelPhoto");
        labelPhoto->setStyleSheet(QString::fromUtf8("border: 2px solid #dddddd; border-radius: 5px;"));

        horizontalLayout_2->addWidget(labelPhoto);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        labelNo = new QLabel(DialogSignOut);
        labelNo->setObjectName("labelNo");
        QFont font;
        font.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font.setPointSize(14);
        labelNo->setFont(font);

        verticalLayout->addWidget(labelNo);

        labelName = new QLabel(DialogSignOut);
        labelName->setObjectName("labelName");
        labelName->setFont(font);

        verticalLayout->addWidget(labelName);

        labelDate = new QLabel(DialogSignOut);
        labelDate->setObjectName("labelDate");
        labelDate->setFont(font);

        verticalLayout->addWidget(labelDate);

        labelTime = new QLabel(DialogSignOut);
        labelTime->setObjectName("labelTime");
        labelTime->setFont(font);

        verticalLayout->addWidget(labelTime);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        BtnOk = new QPushButton(DialogSignOut);
        BtnOk->setObjectName("BtnOk");
        BtnOk->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/ok.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnOk->setIcon(icon);

        horizontalLayout_3->addWidget(BtnOk);

        BtnCancel = new QPushButton(DialogSignOut);
        BtnCancel->setObjectName("BtnCancel");
        BtnCancel->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/\345\217\226\346\266\210.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnCancel->setIcon(icon1);

        horizontalLayout_3->addWidget(BtnCancel);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        retranslateUi(DialogSignOut);

        QMetaObject::connectSlotsByName(DialogSignOut);
    } // setupUi

    void retranslateUi(QDialog *DialogSignOut)
    {
        DialogSignOut->setWindowTitle(QCoreApplication::translate("DialogSignOut", "\347\255\276\351\200\200", nullptr));
        labelPhoto->setText(QString());
        labelNo->setText(QCoreApplication::translate("DialogSignOut", "\345\267\245\345\217\267\357\274\232", nullptr));
        labelName->setText(QCoreApplication::translate("DialogSignOut", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelDate->setText(QCoreApplication::translate("DialogSignOut", "\347\255\276\351\200\200\346\227\266\351\227\264\357\274\232", nullptr));
        labelTime->setText(QCoreApplication::translate("DialogSignOut", "\347\255\276\351\200\200\346\227\266\351\227\264\357\274\232", nullptr));
        BtnOk->setText(QCoreApplication::translate("DialogSignOut", "\347\255\276\351\200\200", nullptr));
        BtnCancel->setText(QCoreApplication::translate("DialogSignOut", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSignOut: public Ui_DialogSignOut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSIGNOUT_H
