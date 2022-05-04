/********************************************************************************
** Form generated from reading UI file 'nameplayers.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMEPLAYERS_H
#define UI_NAMEPLAYERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NamePlayers
{
public:
    QLineEdit *p1Entry;
    QLabel *title;
    QLabel *p1Label;
    QLabel *p2Label;
    QLineEdit *p2Entry;
    QLabel *p3Label;
    QLineEdit *p3Entry;
    QLabel *p4Label;
    QLineEdit *p4Entry;
    QPushButton *startGameButton;

    void setupUi(QDialog *NamePlayers)
    {
        if (NamePlayers->objectName().isEmpty())
            NamePlayers->setObjectName(QString::fromUtf8("NamePlayers"));
        NamePlayers->resize(530, 460);
        p1Entry = new QLineEdit(NamePlayers);
        p1Entry->setObjectName(QString::fromUtf8("p1Entry"));
        p1Entry->setGeometry(QRect(260, 110, 141, 21));
        title = new QLabel(NamePlayers);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(160, 10, 191, 51));
        QFont font;
        font.setPointSize(24);
        title->setFont(font);
        title->setScaledContents(false);
        title->setAlignment(Qt::AlignCenter);
        p1Label = new QLabel(NamePlayers);
        p1Label->setObjectName(QString::fromUtf8("p1Label"));
        p1Label->setGeometry(QRect(120, 110, 121, 21));
        p1Label->setAlignment(Qt::AlignCenter);
        p2Label = new QLabel(NamePlayers);
        p2Label->setObjectName(QString::fromUtf8("p2Label"));
        p2Label->setGeometry(QRect(120, 150, 121, 21));
        p2Label->setAlignment(Qt::AlignCenter);
        p2Entry = new QLineEdit(NamePlayers);
        p2Entry->setObjectName(QString::fromUtf8("p2Entry"));
        p2Entry->setGeometry(QRect(260, 150, 141, 21));
        p3Label = new QLabel(NamePlayers);
        p3Label->setObjectName(QString::fromUtf8("p3Label"));
        p3Label->setGeometry(QRect(120, 190, 121, 21));
        p3Label->setAlignment(Qt::AlignCenter);
        p3Entry = new QLineEdit(NamePlayers);
        p3Entry->setObjectName(QString::fromUtf8("p3Entry"));
        p3Entry->setGeometry(QRect(260, 190, 141, 21));
        p4Label = new QLabel(NamePlayers);
        p4Label->setObjectName(QString::fromUtf8("p4Label"));
        p4Label->setGeometry(QRect(120, 230, 121, 21));
        p4Label->setAlignment(Qt::AlignCenter);
        p4Entry = new QLineEdit(NamePlayers);
        p4Entry->setObjectName(QString::fromUtf8("p4Entry"));
        p4Entry->setGeometry(QRect(260, 230, 141, 21));
        startGameButton = new QPushButton(NamePlayers);
        startGameButton->setObjectName(QString::fromUtf8("startGameButton"));
        startGameButton->setGeometry(QRect(200, 330, 101, 24));

        retranslateUi(NamePlayers);

        QMetaObject::connectSlotsByName(NamePlayers);
    } // setupUi

    void retranslateUi(QDialog *NamePlayers)
    {
        NamePlayers->setWindowTitle(QCoreApplication::translate("NamePlayers", "Dialog", nullptr));
        title->setText(QCoreApplication::translate("NamePlayers", "Player Setup:", nullptr));
        p1Label->setText(QCoreApplication::translate("NamePlayers", "Player 1 (Red):", nullptr));
        p2Label->setText(QCoreApplication::translate("NamePlayers", "Player 2 (Green):", nullptr));
        p3Label->setText(QCoreApplication::translate("NamePlayers", "Player 3 (Blue):", nullptr));
        p4Label->setText(QCoreApplication::translate("NamePlayers", "Player 4 (Yellow):", nullptr));
        startGameButton->setText(QCoreApplication::translate("NamePlayers", "Start Game!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NamePlayers: public Ui_NamePlayers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMEPLAYERS_H
