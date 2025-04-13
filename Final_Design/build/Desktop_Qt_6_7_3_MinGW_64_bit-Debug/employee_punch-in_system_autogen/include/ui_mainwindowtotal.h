/********************************************************************************
** Form generated from reading UI file 'mainwindowtotal.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWTOTAL_H
#define UI_MAINWINDOWTOTAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowTotal
{
public:
    QAction *actionSignIn;
    QAction *actionLeave;
    QAction *actionPermit;
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionRecord;
    QAction *actionEmployeeInfo;
    QAction *actionSign_out;
    QAction *actionWorkTime;
    QAction *actionPerson;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindowTotal)
    {
        if (MainWindowTotal->objectName().isEmpty())
            MainWindowTotal->setObjectName("MainWindowTotal");
        MainWindowTotal->resize(800, 600);
        MainWindowTotal->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #ffffff;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"}\n"
"QMenuBar {\n"
"    background-color: #f5f5f5;\n"
"    color: #333333;\n"
"    font-size: 14px;\n"
"    border-bottom: 1px solid #dddddd;\n"
"}\n"
"QMenuBar::item {\n"
"    background-color: transparent;\n"
"    padding: 5px 10px;\n"
"}\n"
"QMenuBar::item:selected {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"QMenu {\n"
"    background-color: #f5f5f5;\n"
"    color: #333333;\n"
"    border: 1px solid #dddddd;\n"
"}\n"
"QMenu::item:selected {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"QToolBar {\n"
"    background-color: #f5f5f5;\n"
"    border: none;\n"
"    padding: 5px;\n"
"    border-bottom: 1px solid #dddddd;\n"
"}\n"
"QToolButton {\n"
"    background-color: transparent;\n"
"    color: #333333;\n"
"    padding: 5px;\n"
"    border-radius: 5px;\n"
"}\n"
"QToolButton:hover {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"QTabWidget::pane {\n"
"    border: 1px solid #dddddd;\n"
"    background-color: #fff"
                        "fff;\n"
"}\n"
"QTabBar::tab {\n"
"    background-color: #f5f5f5;\n"
"    color: #333333;\n"
"    padding: 10px;\n"
"    border: 1px solid #dddddd;\n"
"    border-bottom: none;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background-color: #ffffff;\n"
"    border-bottom: 1px solid #ffffff;\n"
"}\n"
"QTableWidget {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #dddddd;\n"
"    gridline-color: #dddddd;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #f5f5f5;\n"
"    color: #333333;\n"
"    padding: 5px;\n"
"    border: 1px solid #dddddd;\n"
"}"));
        MainWindowTotal->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        actionSignIn = new QAction(MainWindowTotal);
        actionSignIn->setObjectName("actionSignIn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/\346\211\223\345\215\241.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSignIn->setIcon(icon);
        actionSignIn->setMenuRole(QAction::NoRole);
        actionLeave = new QAction(MainWindowTotal);
        actionLeave->setObjectName("actionLeave");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/\350\257\267\345\201\207.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionLeave->setIcon(icon1);
        actionLeave->setMenuRole(QAction::NoRole);
        actionPermit = new QAction(MainWindowTotal);
        actionPermit->setObjectName("actionPermit");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/\344\272\213\345\212\241.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPermit->setIcon(icon2);
        actionPermit->setMenuRole(QAction::NoRole);
        actionAbout = new QAction(MainWindowTotal);
        actionAbout->setObjectName("actionAbout");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/\345\210\206\346\236\220.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAbout->setIcon(icon3);
        actionAbout->setMenuRole(QAction::NoRole);
        actionExit = new QAction(MainWindowTotal);
        actionExit->setObjectName("actionExit");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionExit->setIcon(icon4);
        actionExit->setMenuRole(QAction::NoRole);
        actionRecord = new QAction(MainWindowTotal);
        actionRecord->setObjectName("actionRecord");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/\345\217\260\350\264\246.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRecord->setIcon(icon5);
        actionRecord->setMenuRole(QAction::NoRole);
        actionEmployeeInfo = new QAction(MainWindowTotal);
        actionEmployeeInfo->setObjectName("actionEmployeeInfo");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/login2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionEmployeeInfo->setIcon(icon6);
        actionEmployeeInfo->setMenuRole(QAction::NoRole);
        actionSign_out = new QAction(MainWindowTotal);
        actionSign_out->setObjectName("actionSign_out");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/\350\200\203\345\213\244.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSign_out->setIcon(icon7);
        actionSign_out->setMenuRole(QAction::NoRole);
        actionWorkTime = new QAction(MainWindowTotal);
        actionWorkTime->setObjectName("actionWorkTime");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/\345\212\240\347\217\255.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionWorkTime->setIcon(icon8);
        actionWorkTime->setMenuRole(QAction::NoRole);
        actionPerson = new QAction(MainWindowTotal);
        actionPerson->setObjectName("actionPerson");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/\345\256\242\346\210\267.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPerson->setIcon(icon9);
        actionPerson->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindowTotal);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        tabWidget->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidget);

        MainWindowTotal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowTotal);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 29));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        MainWindowTotal->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowTotal);
        statusbar->setObjectName("statusbar");
        MainWindowTotal->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindowTotal);
        toolBar->setObjectName("toolBar");
        toolBar->setIconSize(QSize(40, 40));
        MainWindowTotal->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionSignIn);
        menu->addAction(actionSign_out);
        menu->addSeparator();
        menu->addAction(actionLeave);
        menu->addAction(actionPermit);
        menu->addSeparator();
        menu->addAction(actionExit);
        menu_2->addAction(actionRecord);
        menu_2->addSeparator();
        menu_2->addAction(actionPerson);
        menu_2->addAction(actionEmployeeInfo);
        menu_2->addSeparator();
        menu_2->addAction(actionWorkTime);
        menu_2->addAction(actionAbout);
        toolBar->addAction(actionSignIn);
        toolBar->addAction(actionSign_out);
        toolBar->addSeparator();
        toolBar->addAction(actionLeave);
        toolBar->addAction(actionPermit);
        toolBar->addAction(actionRecord);
        toolBar->addSeparator();
        toolBar->addAction(actionPerson);
        toolBar->addAction(actionEmployeeInfo);
        toolBar->addAction(actionWorkTime);
        toolBar->addAction(actionAbout);
        toolBar->addAction(actionExit);

        retranslateUi(MainWindowTotal);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowTotal);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowTotal)
    {
        MainWindowTotal->setWindowTitle(QCoreApplication::translate("MainWindowTotal", "\350\201\214\345\267\245\350\200\203\345\213\244", nullptr));
        actionSignIn->setText(QCoreApplication::translate("MainWindowTotal", "\347\255\276\345\210\260", nullptr));
#if QT_CONFIG(tooltip)
        actionSignIn->setToolTip(QCoreApplication::translate("MainWindowTotal", "\347\255\276\345\210\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSignIn->setShortcut(QCoreApplication::translate("MainWindowTotal", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLeave->setText(QCoreApplication::translate("MainWindowTotal", "\350\257\267\345\201\207", nullptr));
#if QT_CONFIG(tooltip)
        actionLeave->setToolTip(QCoreApplication::translate("MainWindowTotal", "\350\257\267\345\201\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionLeave->setShortcut(QCoreApplication::translate("MainWindowTotal", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPermit->setText(QCoreApplication::translate("MainWindowTotal", "\346\211\271\345\201\207", nullptr));
#if QT_CONFIG(tooltip)
        actionPermit->setToolTip(QCoreApplication::translate("MainWindowTotal", "\346\211\271\345\201\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPermit->setShortcut(QCoreApplication::translate("MainWindowTotal", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindowTotal", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindowTotal", "\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
        actionExit->setText(QCoreApplication::translate("MainWindowTotal", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("MainWindowTotal", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindowTotal", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRecord->setText(QCoreApplication::translate("MainWindowTotal", "\350\257\267\345\201\207\350\256\260\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        actionRecord->setToolTip(QCoreApplication::translate("MainWindowTotal", "\346\210\221\347\232\204\350\257\267\345\201\207\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionRecord->setShortcut(QCoreApplication::translate("MainWindowTotal", "Ctrl+M", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEmployeeInfo->setText(QCoreApplication::translate("MainWindowTotal", "\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
#if QT_CONFIG(tooltip)
        actionEmployeeInfo->setToolTip(QCoreApplication::translate("MainWindowTotal", "\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSign_out->setText(QCoreApplication::translate("MainWindowTotal", "\347\255\276\351\200\200", nullptr));
#if QT_CONFIG(tooltip)
        actionSign_out->setToolTip(QCoreApplication::translate("MainWindowTotal", "\347\255\276\351\200\200", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSign_out->setShortcut(QCoreApplication::translate("MainWindowTotal", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWorkTime->setText(QCoreApplication::translate("MainWindowTotal", "\345\267\245\344\275\234\346\227\266\351\225\277", nullptr));
#if QT_CONFIG(tooltip)
        actionWorkTime->setToolTip(QCoreApplication::translate("MainWindowTotal", "\345\267\245\344\275\234\346\227\266\351\225\277", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPerson->setText(QCoreApplication::translate("MainWindowTotal", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
#if QT_CONFIG(tooltip)
        actionPerson->setToolTip(QCoreApplication::translate("MainWindowTotal", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindowTotal", "\350\200\203\345\213\244\350\256\260\345\275\225", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindowTotal", "\350\217\234\345\215\225", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindowTotal", "\346\237\245\347\234\213", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindowTotal", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowTotal: public Ui_MainWindowTotal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWTOTAL_H
