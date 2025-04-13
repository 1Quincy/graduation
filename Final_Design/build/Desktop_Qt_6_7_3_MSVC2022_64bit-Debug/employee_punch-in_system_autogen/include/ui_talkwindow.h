/********************************************************************************
** Form generated from reading UI file 'talkwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALKWINDOW_H
#define UI_TALKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TalkWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *msgWidget;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sendButton;

    void setupUi(QWidget *TalkWindow)
    {
        if (TalkWindow->objectName().isEmpty())
            TalkWindow->setObjectName("TalkWindow");
        TalkWindow->resize(450, 336);
        verticalLayout = new QVBoxLayout(TalkWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(TalkWindow);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(200, 40));
        label->setMaximumSize(QSize(166666, 40));
        label->setFrameShape(QFrame::Shape::StyledPanel);

        verticalLayout->addWidget(label);

        msgWidget = new QListWidget(TalkWindow);
        msgWidget->setObjectName("msgWidget");
        msgWidget->setMinimumSize(QSize(260, 0));
        msgWidget->setMaximumSize(QSize(16777215, 16666));
        msgWidget->setFrameShape(QFrame::Shape::StyledPanel);
        msgWidget->setLineWidth(1);

        verticalLayout->addWidget(msgWidget);

        textEdit = new QTextEdit(TalkWindow);
        textEdit->setObjectName("textEdit");
        textEdit->setMinimumSize(QSize(0, 90));
        textEdit->setMaximumSize(QSize(16777215, 90));
        textEdit->setFrameShape(QFrame::Shape::StyledPanel);
        textEdit->setLineWidth(1);

        verticalLayout->addWidget(textEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        sendButton = new QPushButton(TalkWindow);
        sendButton->setObjectName("sendButton");

        horizontalLayout_4->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(2, 1);

        retranslateUi(TalkWindow);

        QMetaObject::connectSlotsByName(TalkWindow);
    } // setupUi

    void retranslateUi(QWidget *TalkWindow)
    {
        TalkWindow->setWindowTitle(QCoreApplication::translate("TalkWindow", "Form", nullptr));
        label->setText(QString());
        sendButton->setText(QCoreApplication::translate("TalkWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TalkWindow: public Ui_TalkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKWINDOW_H
