#include <vector>
#include <QString>
#include "leaderboard.h"
#include "ui_leaderboard.h"
#include "mainwindow.h"

Leaderboard::Leaderboard(QWidget *parent, std::vector<LeaderboardPlayer*> leaderboard) :
    QDialog(parent),
    ui(new Ui::Leaderboard)
{
    ui->setupUi(this);
    std::string to_display = "";

    for (int x = 0; x < (int)leaderboard.size() && x < 10; x++) {
       to_display += std::to_string(x+1) + ": " + leaderboard[x]->name + " - " + std::to_string(leaderboard[x]->wins) + " wins, " + std::to_string(leaderboard[x]->losses) + " losses, " + std::to_string((int)std::round((leaderboard[x]->win_percentage)*100)) + "% win\n";
    }


    ui->leaderboardChange->setText(QString::fromStdString(to_display));
}

Leaderboard::~Leaderboard()
{
    delete ui;
}

void Leaderboard::on_closeButton_clicked()
{
    this->close();
}

