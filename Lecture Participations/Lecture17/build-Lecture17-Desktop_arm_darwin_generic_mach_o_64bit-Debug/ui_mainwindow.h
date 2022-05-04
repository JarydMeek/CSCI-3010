/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *addPoint;
    QPushButton *deletePoint;
    QPushButton *changeColor;
    QLabel *xCoordBoxLabel;
    QLabel *yCoordBoxLabel;
    QLabel *selectedCoordinatesLabel;
    QLabel *pt1Coords;
    QLabel *pt2Coords;
    QLabel *distanceLabel;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(50, 20, 161, 31));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(240, 20, 161, 31));
        addPoint = new QPushButton(centralwidget);
        addPoint->setObjectName(QString::fromUtf8("addPoint"));
        addPoint->setGeometry(QRect(50, 50, 100, 32));
        deletePoint = new QPushButton(centralwidget);
        deletePoint->setObjectName(QString::fromUtf8("deletePoint"));
        deletePoint->setGeometry(QRect(170, 50, 100, 32));
        changeColor = new QPushButton(centralwidget);
        changeColor->setObjectName(QString::fromUtf8("changeColor"));
        changeColor->setGeometry(QRect(300, 50, 100, 32));
        xCoordBoxLabel = new QLabel(centralwidget);
        xCoordBoxLabel->setObjectName(QString::fromUtf8("xCoordBoxLabel"));
        xCoordBoxLabel->setGeometry(QRect(50, 0, 81, 16));
        yCoordBoxLabel = new QLabel(centralwidget);
        yCoordBoxLabel->setObjectName(QString::fromUtf8("yCoordBoxLabel"));
        yCoordBoxLabel->setGeometry(QRect(240, 0, 81, 16));
        selectedCoordinatesLabel = new QLabel(centralwidget);
        selectedCoordinatesLabel->setObjectName(QString::fromUtf8("selectedCoordinatesLabel"));
        selectedCoordinatesLabel->setGeometry(QRect(50, 85, 351, 31));
        selectedCoordinatesLabel->setAlignment(Qt::AlignCenter);
        pt1Coords = new QLabel(centralwidget);
        pt1Coords->setObjectName(QString::fromUtf8("pt1Coords"));
        pt1Coords->setGeometry(QRect(50, 120, 141, 16));
        pt2Coords = new QLabel(centralwidget);
        pt2Coords->setObjectName(QString::fromUtf8("pt2Coords"));
        pt2Coords->setGeometry(QRect(50, 140, 141, 16));
        distanceLabel = new QLabel(centralwidget);
        distanceLabel->setObjectName(QString::fromUtf8("distanceLabel"));
        distanceLabel->setGeometry(QRect(290, 120, 141, 16));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(50, 170, 361, 271));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 37));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        addPoint->setText(QCoreApplication::translate("MainWindow", "Add Point", nullptr));
        deletePoint->setText(QCoreApplication::translate("MainWindow", "Delete Point", nullptr));
        changeColor->setText(QCoreApplication::translate("MainWindow", "Change Color", nullptr));
        xCoordBoxLabel->setText(QCoreApplication::translate("MainWindow", "X Coordinate", nullptr));
        yCoordBoxLabel->setText(QCoreApplication::translate("MainWindow", "Y Coordinate", nullptr));
        selectedCoordinatesLabel->setText(QCoreApplication::translate("MainWindow", "Selected Coordinates", nullptr));
        pt1Coords->setText(QCoreApplication::translate("MainWindow", "Point 1 Coordinates:", nullptr));
        pt2Coords->setText(QCoreApplication::translate("MainWindow", "Point 2 Coordinates:", nullptr));
        distanceLabel->setText(QCoreApplication::translate("MainWindow", "Distance:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
