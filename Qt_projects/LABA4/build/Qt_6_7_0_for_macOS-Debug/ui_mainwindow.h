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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionasfasf;
    QWidget *centralwidget;
    QPushButton *ChangeColorButton_2;
    QPushButton *ChangeColorButton;
    QPushButton *ChangeColorButton_3;
    QPushButton *ChangeColorButton_4;
    QPushButton *BoldPenButton;
    QPushButton *DefaultPenButton;
    QPushButton *Savebutton;
    QPushButton *Loadbutton;
    QPushButton *Updatebutton;
    QPushButton *Helpbutton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionasfasf = new QAction(MainWindow);
        actionasfasf->setObjectName("actionasfasf");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        ChangeColorButton_2 = new QPushButton(centralwidget);
        ChangeColorButton_2->setObjectName("ChangeColorButton_2");
        ChangeColorButton_2->setGeometry(QRect(0, 30, 100, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        ChangeColorButton_2->setFont(font);
        ChangeColorButton = new QPushButton(centralwidget);
        ChangeColorButton->setObjectName("ChangeColorButton");
        ChangeColorButton->setGeometry(QRect(0, 0, 100, 31));
        ChangeColorButton->setFont(font);
        ChangeColorButton->setIconSize(QSize(100, 32));
        ChangeColorButton->setFlat(false);
        ChangeColorButton_3 = new QPushButton(centralwidget);
        ChangeColorButton_3->setObjectName("ChangeColorButton_3");
        ChangeColorButton_3->setGeometry(QRect(0, 60, 100, 31));
        ChangeColorButton_3->setFont(font);
        ChangeColorButton_4 = new QPushButton(centralwidget);
        ChangeColorButton_4->setObjectName("ChangeColorButton_4");
        ChangeColorButton_4->setGeometry(QRect(0, 90, 100, 31));
        ChangeColorButton_4->setFont(font);
        BoldPenButton = new QPushButton(centralwidget);
        BoldPenButton->setObjectName("BoldPenButton");
        BoldPenButton->setGeometry(QRect(130, 0, 100, 31));
        QFont font1;
        font1.setBold(true);
        BoldPenButton->setFont(font1);
        DefaultPenButton = new QPushButton(centralwidget);
        DefaultPenButton->setObjectName("DefaultPenButton");
        DefaultPenButton->setGeometry(QRect(130, 30, 100, 31));
        DefaultPenButton->setFont(font1);
        Savebutton = new QPushButton(centralwidget);
        Savebutton->setObjectName("Savebutton");
        Savebutton->setGeometry(QRect(300, 30, 41, 32));
        Loadbutton = new QPushButton(centralwidget);
        Loadbutton->setObjectName("Loadbutton");
        Loadbutton->setGeometry(QRect(250, 30, 41, 32));
        Updatebutton = new QPushButton(centralwidget);
        Updatebutton->setObjectName("Updatebutton");
        Updatebutton->setGeometry(QRect(250, 0, 141, 32));
        Helpbutton = new QPushButton(centralwidget);
        Helpbutton->setObjectName("Helpbutton");
        Helpbutton->setGeometry(QRect(350, 30, 41, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionasfasf->setText(QCoreApplication::translate("MainWindow", "asfasf", nullptr));
        ChangeColorButton_2->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        ChangeColorButton->setText(QCoreApplication::translate("MainWindow", "Black", nullptr));
        ChangeColorButton_3->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        ChangeColorButton_4->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        BoldPenButton->setText(QCoreApplication::translate("MainWindow", "Bold pen", nullptr));
        DefaultPenButton->setText(QCoreApplication::translate("MainWindow", "Default pen", nullptr));
        Savebutton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        Loadbutton->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        Updatebutton->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        Helpbutton->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
