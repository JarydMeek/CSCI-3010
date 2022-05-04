#include "nameplayers.h"
#include "ui_nameplayers.h"
#include "mainwindow.h"

NamePlayers::NamePlayers(QWidget *parent, int num_players) :
    QDialog(parent),
    ui(new Ui::NamePlayers)
{
    ui->setupUi(this);
    if  (num_players < 3) {
        ui->p3Entry->setHidden(true);
        ui->p3Label->setHidden(true);
    }
    if  (num_players < 4) {
        ui->p4Entry->setHidden(true);
        ui->p4Label->setHidden(true);
    }
}

NamePlayers::~NamePlayers()
{
    delete ui;
}

void NamePlayers::on_startGameButton_clicked()
{
    std::string storage[6];
    storage[0] = ui->p1Entry->text().toStdString();
    storage[1] = ui->p2Entry->text().toStdString();
    storage[2] = ui->p3Entry->text().toStdString();
    storage[3] = ui->p4Entry->text().toStdString();
    ((MainWindow*) this->parent())->setNamePlayers(storage);
    this->close();
}

