/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QPushButton *pushButton1;
    QPushButton *pushButton4;
    QPushButton *pushButton7;
    QPushButton *pushButton5;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton6;
    QPushButton *pushButton9;
    QPushButton *pushButton8;
    QPushButton *pushButton0;
    QPushButton *pushButtonPlus;
    QPushButton *pushButtonMinus;
    QPushButton *pushButtonEq;
    QPushButton *pushButtonMultiply;
    QPushButton *pushButtonDiv;
    QPushButton *pushButtonClear;
    QLineEdit *lineEdit;
    QLineEdit *lineEditExpression;
    QPushButton *pushButtonDot;
    QPushButton *pushButtonBack;
    QPushButton *pushButtonQuo;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(268, 407);
        MainWindow->setMinimumSize(QSize(268, 407));
        MainWindow->setMaximumSize(QSize(268, 407));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setGeometry(QRect(20, 200, 51, 41));
        pushButton4 = new QPushButton(centralwidget);
        pushButton4->setObjectName(QString::fromUtf8("pushButton4"));
        pushButton4->setGeometry(QRect(20, 240, 51, 41));
        pushButton7 = new QPushButton(centralwidget);
        pushButton7->setObjectName(QString::fromUtf8("pushButton7"));
        pushButton7->setGeometry(QRect(20, 280, 51, 41));
        pushButton5 = new QPushButton(centralwidget);
        pushButton5->setObjectName(QString::fromUtf8("pushButton5"));
        pushButton5->setGeometry(QRect(80, 240, 51, 41));
        pushButton2 = new QPushButton(centralwidget);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        pushButton2->setGeometry(QRect(80, 200, 51, 41));
        pushButton3 = new QPushButton(centralwidget);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));
        pushButton3->setGeometry(QRect(140, 200, 51, 41));
        pushButton6 = new QPushButton(centralwidget);
        pushButton6->setObjectName(QString::fromUtf8("pushButton6"));
        pushButton6->setGeometry(QRect(140, 240, 51, 41));
        pushButton9 = new QPushButton(centralwidget);
        pushButton9->setObjectName(QString::fromUtf8("pushButton9"));
        pushButton9->setGeometry(QRect(140, 280, 51, 41));
        pushButton8 = new QPushButton(centralwidget);
        pushButton8->setObjectName(QString::fromUtf8("pushButton8"));
        pushButton8->setGeometry(QRect(80, 280, 51, 41));
        pushButton0 = new QPushButton(centralwidget);
        pushButton0->setObjectName(QString::fromUtf8("pushButton0"));
        pushButton0->setGeometry(QRect(80, 320, 51, 41));
        pushButtonPlus = new QPushButton(centralwidget);
        pushButtonPlus->setObjectName(QString::fromUtf8("pushButtonPlus"));
        pushButtonPlus->setGeometry(QRect(200, 200, 51, 41));
        pushButtonMinus = new QPushButton(centralwidget);
        pushButtonMinus->setObjectName(QString::fromUtf8("pushButtonMinus"));
        pushButtonMinus->setGeometry(QRect(200, 240, 51, 41));
        pushButtonEq = new QPushButton(centralwidget);
        pushButtonEq->setObjectName(QString::fromUtf8("pushButtonEq"));
        pushButtonEq->setGeometry(QRect(140, 320, 111, 41));
        pushButtonMultiply = new QPushButton(centralwidget);
        pushButtonMultiply->setObjectName(QString::fromUtf8("pushButtonMultiply"));
        pushButtonMultiply->setGeometry(QRect(200, 280, 51, 41));
        pushButtonDiv = new QPushButton(centralwidget);
        pushButtonDiv->setObjectName(QString::fromUtf8("pushButtonDiv"));
        pushButtonDiv->setGeometry(QRect(20, 160, 51, 41));
        pushButtonClear = new QPushButton(centralwidget);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(200, 160, 51, 41));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 100, 231, 51));
        QFont font;
        font.setPointSize(14);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditExpression = new QLineEdit(centralwidget);
        lineEditExpression->setObjectName(QString::fromUtf8("lineEditExpression"));
        lineEditExpression->setGeometry(QRect(20, 50, 231, 51));
        lineEditExpression->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonDot = new QPushButton(centralwidget);
        pushButtonDot->setObjectName(QString::fromUtf8("pushButtonDot"));
        pushButtonDot->setGeometry(QRect(20, 320, 51, 41));
        pushButtonBack = new QPushButton(centralwidget);
        pushButtonBack->setObjectName(QString::fromUtf8("pushButtonBack"));
        pushButtonBack->setGeometry(QRect(140, 160, 51, 41));
        pushButtonQuo = new QPushButton(centralwidget);
        pushButtonQuo->setObjectName(QString::fromUtf8("pushButtonQuo"));
        pushButtonQuo->setGeometry(QRect(80, 160, 51, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 101, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 268, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QTCalculator", nullptr));
        pushButton1->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton4->setText(QApplication::translate("MainWindow", "4", nullptr));
        pushButton7->setText(QApplication::translate("MainWindow", "7", nullptr));
        pushButton5->setText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton2->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton6->setText(QApplication::translate("MainWindow", "6", nullptr));
        pushButton9->setText(QApplication::translate("MainWindow", "9", nullptr));
        pushButton8->setText(QApplication::translate("MainWindow", "8", nullptr));
        pushButton0->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButtonPlus->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButtonMinus->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushButtonEq->setText(QApplication::translate("MainWindow", "EQ", nullptr));
        pushButtonMultiply->setText(QApplication::translate("MainWindow", "*", nullptr));
        pushButtonDiv->setText(QApplication::translate("MainWindow", "%", nullptr));
        pushButtonClear->setText(QApplication::translate("MainWindow", "clear", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        lineEditExpression->setText(QString());
        pushButtonDot->setText(QApplication::translate("MainWindow", ".", nullptr));
        pushButtonBack->setText(QApplication::translate("MainWindow", "back", nullptr));
        pushButtonQuo->setText(QApplication::translate("MainWindow", "/", nullptr));
        label->setText(QApplication::translate("MainWindow", "Calculator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
