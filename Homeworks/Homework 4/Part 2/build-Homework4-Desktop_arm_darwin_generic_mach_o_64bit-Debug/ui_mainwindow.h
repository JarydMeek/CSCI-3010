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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *mainView;
    QLabel *turnLabel;
    QPushButton *startGameButton;
    QPushButton *newGameButton;
    QPushButton *endGameButton;
    QGraphicsView *homeView;
    QPushButton *quitGameButton;
    QPushButton *reRollButton;
    QPushButton *RollButton;
    QPushButton *moveButton;
    QLabel *timeLabel;
    QLabel *rollChange;
    QLabel *timeChange;
    QGraphicsView *currentTurnView;
    QPushButton *undoButton;
    QPushButton *showLeaderboard;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 510);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainView = new QGraphicsView(centralwidget);
        mainView->setObjectName(QString::fromUtf8("mainView"));
        mainView->setGeometry(QRect(160, 50, 491, 401));
        turnLabel = new QLabel(centralwidget);
        turnLabel->setObjectName(QString::fromUtf8("turnLabel"));
        turnLabel->setGeometry(QRect(680, 60, 91, 16));
        turnLabel->setLayoutDirection(Qt::LeftToRight);
        turnLabel->setAlignment(Qt::AlignCenter);
        startGameButton = new QPushButton(centralwidget);
        startGameButton->setObjectName(QString::fromUtf8("startGameButton"));
        startGameButton->setGeometry(QRect(350, 10, 111, 32));
        newGameButton = new QPushButton(centralwidget);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));
        newGameButton->setGeometry(QRect(160, 10, 111, 32));
        endGameButton = new QPushButton(centralwidget);
        endGameButton->setObjectName(QString::fromUtf8("endGameButton"));
        endGameButton->setGeometry(QRect(539, 10, 111, 32));
        homeView = new QGraphicsView(centralwidget);
        homeView->setObjectName(QString::fromUtf8("homeView"));
        homeView->setGeometry(QRect(30, 370, 81, 81));
        quitGameButton = new QPushButton(centralwidget);
        quitGameButton->setObjectName(QString::fromUtf8("quitGameButton"));
        quitGameButton->setGeometry(QRect(670, 210, 111, 32));
        reRollButton = new QPushButton(centralwidget);
        reRollButton->setObjectName(QString::fromUtf8("reRollButton"));
        reRollButton->setGeometry(QRect(670, 290, 111, 32));
        RollButton = new QPushButton(centralwidget);
        RollButton->setObjectName(QString::fromUtf8("RollButton"));
        RollButton->setGeometry(QRect(670, 330, 111, 32));
        moveButton = new QPushButton(centralwidget);
        moveButton->setObjectName(QString::fromUtf8("moveButton"));
        moveButton->setGeometry(QRect(670, 410, 111, 32));
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(670, 150, 111, 20));
        timeLabel->setLayoutDirection(Qt::LeftToRight);
        timeLabel->setAlignment(Qt::AlignCenter);
        rollChange = new QLabel(centralwidget);
        rollChange->setObjectName(QString::fromUtf8("rollChange"));
        rollChange->setGeometry(QRect(670, 360, 111, 51));
        rollChange->setLayoutDirection(Qt::LeftToRight);
        rollChange->setScaledContents(false);
        rollChange->setAlignment(Qt::AlignCenter);
        timeChange = new QLabel(centralwidget);
        timeChange->setObjectName(QString::fromUtf8("timeChange"));
        timeChange->setGeometry(QRect(670, 180, 111, 20));
        timeChange->setLayoutDirection(Qt::LeftToRight);
        timeChange->setAlignment(Qt::AlignCenter);
        currentTurnView = new QGraphicsView(centralwidget);
        currentTurnView->setObjectName(QString::fromUtf8("currentTurnView"));
        currentTurnView->setGeometry(QRect(700, 90, 51, 41));
        undoButton = new QPushButton(centralwidget);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));
        undoButton->setGeometry(QRect(670, 250, 111, 32));
        showLeaderboard = new QPushButton(centralwidget);
        showLeaderboard->setObjectName(QString::fromUtf8("showLeaderboard"));
        showLeaderboard->setGeometry(QRect(10, 60, 131, 32));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        turnLabel->setText(QCoreApplication::translate("MainWindow", "Current Turn:", nullptr));
        startGameButton->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        newGameButton->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        endGameButton->setText(QCoreApplication::translate("MainWindow", "End Game", nullptr));
        quitGameButton->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        reRollButton->setText(QCoreApplication::translate("MainWindow", "Re-Roll", nullptr));
        RollButton->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        moveButton->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "Time Remaining:", nullptr));
        rollChange->setText(QString());
        timeChange->setText(QCoreApplication::translate("MainWindow", "10s", nullptr));
        undoButton->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        showLeaderboard->setText(QCoreApplication::translate("MainWindow", "Show Leaderboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
