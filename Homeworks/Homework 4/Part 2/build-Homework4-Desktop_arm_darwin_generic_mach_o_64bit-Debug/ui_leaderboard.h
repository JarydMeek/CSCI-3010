/********************************************************************************
** Form generated from reading UI file 'leaderboard.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADERBOARD_H
#define UI_LEADERBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Leaderboard
{
public:
    QLabel *leaderboardChange;
    QLabel *leaderboardTitle;
    QPushButton *closeButton;

    void setupUi(QDialog *Leaderboard)
    {
        if (Leaderboard->objectName().isEmpty())
            Leaderboard->setObjectName(QString::fromUtf8("Leaderboard"));
        Leaderboard->resize(839, 564);
        leaderboardChange = new QLabel(Leaderboard);
        leaderboardChange->setObjectName(QString::fromUtf8("leaderboardChange"));
        leaderboardChange->setGeometry(QRect(60, 60, 701, 411));
        QFont font;
        font.setPointSize(16);
        leaderboardChange->setFont(font);
        leaderboardChange->setAlignment(Qt::AlignCenter);
        leaderboardTitle = new QLabel(Leaderboard);
        leaderboardTitle->setObjectName(QString::fromUtf8("leaderboardTitle"));
        leaderboardTitle->setGeometry(QRect(310, 20, 201, 31));
        QFont font1;
        font1.setPointSize(20);
        leaderboardTitle->setFont(font1);
        leaderboardTitle->setAlignment(Qt::AlignCenter);
        closeButton = new QPushButton(Leaderboard);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(370, 480, 80, 24));

        retranslateUi(Leaderboard);

        QMetaObject::connectSlotsByName(Leaderboard);
    } // setupUi

    void retranslateUi(QDialog *Leaderboard)
    {
        Leaderboard->setWindowTitle(QCoreApplication::translate("Leaderboard", "Dialog", nullptr));
        leaderboardChange->setText(QCoreApplication::translate("Leaderboard", "Leaderboard", nullptr));
        leaderboardTitle->setText(QCoreApplication::translate("Leaderboard", "Leaderboard:", nullptr));
        closeButton->setText(QCoreApplication::translate("Leaderboard", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Leaderboard: public Ui_Leaderboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADERBOARD_H
