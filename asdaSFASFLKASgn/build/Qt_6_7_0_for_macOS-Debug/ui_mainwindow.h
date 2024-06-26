/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionasfasf;
    QAction *actionUPDATE;
    QAction *actionLOAD;
    QAction *actionSAVE;
    QAction *actionHELP;
    QAction *actionSAVE_2;
    QAction *actionLOAD_2;
    QAction *actionCOLORS;
    QWidget *centralwidget;
    QPushButton *BoldPenButton;
    QPushButton *DefaultPenButton;
    QWidget *widget;
    QPushButton *ChangeColorButton;
    QPushButton *ChangeColorButton_4;
    QPushButton *ChangeColorButton_3;
    QPushButton *ChangeColorButton_2;
    QMenuBar *menubar;
    QMenu *menuMENU;
    QMenu *menuEDIT;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionasfasf = new QAction(MainWindow);
        actionasfasf->setObjectName("actionasfasf");
        actionUPDATE = new QAction(MainWindow);
        actionUPDATE->setObjectName("actionUPDATE");
        actionLOAD = new QAction(MainWindow);
        actionLOAD->setObjectName("actionLOAD");
        actionSAVE = new QAction(MainWindow);
        actionSAVE->setObjectName("actionSAVE");
        actionHELP = new QAction(MainWindow);
        actionHELP->setObjectName("actionHELP");
        actionHELP->setCheckable(true);
        actionHELP->setChecked(true);
        actionSAVE_2 = new QAction(MainWindow);
        actionSAVE_2->setObjectName("actionSAVE_2");
        actionLOAD_2 = new QAction(MainWindow);
        actionLOAD_2->setObjectName("actionLOAD_2");
        actionCOLORS = new QAction(MainWindow);
        actionCOLORS->setObjectName("actionCOLORS");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        BoldPenButton = new QPushButton(centralwidget);
        BoldPenButton->setObjectName("BoldPenButton");
        BoldPenButton->setGeometry(QRect(110, 0, 100, 31));
        QFont font;
        font.setBold(true);
        BoldPenButton->setFont(font);
        DefaultPenButton = new QPushButton(centralwidget);
        DefaultPenButton->setObjectName("DefaultPenButton");
        DefaultPenButton->setGeometry(QRect(110, 30, 100, 31));
        DefaultPenButton->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 131, 551));
        ChangeColorButton = new QPushButton(widget);
        ChangeColorButton->setObjectName("ChangeColorButton");
        ChangeColorButton->setGeometry(QRect(0, 0, 100, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        ChangeColorButton->setFont(font1);
        ChangeColorButton->setIconSize(QSize(100, 32));
        ChangeColorButton->setFlat(false);
        ChangeColorButton_4 = new QPushButton(widget);
        ChangeColorButton_4->setObjectName("ChangeColorButton_4");
        ChangeColorButton_4->setGeometry(QRect(0, 90, 100, 31));
        ChangeColorButton_4->setFont(font1);
        ChangeColorButton_3 = new QPushButton(widget);
        ChangeColorButton_3->setObjectName("ChangeColorButton_3");
        ChangeColorButton_3->setGeometry(QRect(0, 60, 100, 31));
        ChangeColorButton_3->setFont(font1);
        ChangeColorButton_2 = new QPushButton(widget);
        ChangeColorButton_2->setObjectName("ChangeColorButton_2");
        ChangeColorButton_2->setGeometry(QRect(0, 30, 100, 31));
        ChangeColorButton_2->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuMENU = new QMenu(menubar);
        menuMENU->setObjectName("menuMENU");
        menuEDIT = new QMenu(menuMENU);
        menuEDIT->setObjectName("menuEDIT");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMENU->menuAction());
        menuMENU->addSeparator();
        menuMENU->addSeparator();
        menuMENU->addSeparator();
        menuMENU->addAction(menuEDIT->menuAction());
        menuMENU->addAction(actionUPDATE);
        menuMENU->addSeparator();
        menuMENU->addSeparator();
        menuMENU->addAction(actionHELP);
        menuMENU->addSeparator();
        menuMENU->addSeparator();
        menuEDIT->addSeparator();
        menuEDIT->addAction(actionSAVE_2);
        menuEDIT->addSeparator();
        menuEDIT->addAction(actionLOAD_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionasfasf->setText(QCoreApplication::translate("MainWindow", "asfasf", nullptr));
        actionUPDATE->setText(QCoreApplication::translate("MainWindow", "UPDATE", nullptr));
#if QT_CONFIG(shortcut)
        actionUPDATE->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLOAD->setText(QCoreApplication::translate("MainWindow", "LOAD", nullptr));
        actionSAVE->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        actionHELP->setText(QCoreApplication::translate("MainWindow", "HELP", nullptr));
        actionSAVE_2->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        actionLOAD_2->setText(QCoreApplication::translate("MainWindow", "LOAD", nullptr));
        actionCOLORS->setText(QCoreApplication::translate("MainWindow", "COLORS", nullptr));
        BoldPenButton->setText(QCoreApplication::translate("MainWindow", "Bold pen", nullptr));
        DefaultPenButton->setText(QCoreApplication::translate("MainWindow", "Default pen", nullptr));
        ChangeColorButton->setText(QCoreApplication::translate("MainWindow", "Black", nullptr));
        ChangeColorButton_4->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        ChangeColorButton_3->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        ChangeColorButton_2->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        menuMENU->setTitle(QCoreApplication::translate("MainWindow", "MENU", nullptr));
        menuEDIT->setTitle(QCoreApplication::translate("MainWindow", "EDIT", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
