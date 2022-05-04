/********************************************************************************
** Form generated from reading UI file 'numplayers.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMPLAYERS_H
#define UI_NUMPLAYERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_NumPlayers
{
public:
    QLabel *label;
    QSlider *slider;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QPushButton *pushButton;

    void setupUi(QDialog *NumPlayers)
    {
        if (NumPlayers->objectName().isEmpty())
            NumPlayers->setObjectName(QString::fromUtf8("NumPlayers"));
        NumPlayers->resize(464, 269);
        label = new QLabel(NumPlayers);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 20, 121, 16));
        label->setAlignment(Qt::AlignCenter);
        slider = new QSlider(NumPlayers);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(150, 110, 161, 31));
        slider->setMinimum(2);
        slider->setMaximum(4);
        slider->setPageStep(1);
        slider->setOrientation(Qt::Horizontal);
        slider->setInvertedControls(false);
        slider->setTickPosition(QSlider::TicksBothSides);
        slider->setTickInterval(1);
        label_3 = new QLabel(NumPlayers);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 90, 21, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(NumPlayers);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 90, 21, 20));
        label_4->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(NumPlayers);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(150, 90, 21, 20));
        label_7->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(NumPlayers);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 160, 80, 24));

        retranslateUi(NumPlayers);

        QMetaObject::connectSlotsByName(NumPlayers);
    } // setupUi

    void retranslateUi(QDialog *NumPlayers)
    {
        NumPlayers->setWindowTitle(QCoreApplication::translate("NumPlayers", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NumPlayers", "How Many Players?", nullptr));
        label_3->setText(QCoreApplication::translate("NumPlayers", "3", nullptr));
        label_4->setText(QCoreApplication::translate("NumPlayers", "4", nullptr));
        label_7->setText(QCoreApplication::translate("NumPlayers", "2", nullptr));
        pushButton->setText(QCoreApplication::translate("NumPlayers", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NumPlayers: public Ui_NumPlayers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMPLAYERS_H
