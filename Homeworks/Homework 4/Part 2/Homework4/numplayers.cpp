#include "numplayers.h"
#include "ui_numplayers.h"
#include "mainwindow.h"

NumPlayers::NumPlayers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumPlayers)
{
    ui->setupUi(this);
}

NumPlayers::~NumPlayers()
{
    delete ui;
}

void NumPlayers::on_pushButton_clicked()
{
    ((MainWindow*) this->parent())->setNumPlayers(ui->slider->value());

    this->close();
}

