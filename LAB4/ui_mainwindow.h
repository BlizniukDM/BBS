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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ChangeColorButton_2;
    QPushButton *ChangeColorButton;
    QPushButton *ChangeColorButton_3;
    QPushButton *ChangeColorButton_4;
    QPushButton *BoldPenButton;
    QPushButton *DefaultPenButton;
    QLabel *Options;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
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
        Options = new QLabel(centralwidget);
        Options->setObjectName("Options");
        Options->setGeometry(QRect(610, 0, 181, 71));
        QFont font2;
        font2.setUnderline(false);
        Options->setFont(font2);
        Options->setLayoutDirection(Qt::LeftToRight);
        Options->setAlignment(Qt::AlignCenter);
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
        ChangeColorButton_2->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        ChangeColorButton->setText(QCoreApplication::translate("MainWindow", "Black", nullptr));
        ChangeColorButton_3->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        ChangeColorButton_4->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        BoldPenButton->setText(QCoreApplication::translate("MainWindow", "Bold pen", nullptr));
        DefaultPenButton->setText(QCoreApplication::translate("MainWindow", "Default pen", nullptr));
        Options->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; text-decoration: underline; color: black\">\320\233\320\232\320\234 - \321\200\320\270\321\201\321\203\320\265\320\274</span></p><p><span style=\" font-size:16pt; text-decoration: underline; color: black\">\320\237\320\232\320\234 - \321\201\321\202\320\270\321\200\320\260\320\265\320\274</span></p></body></html>", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
