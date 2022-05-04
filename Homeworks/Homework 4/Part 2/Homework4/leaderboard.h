#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Leaderboard;
}

class Leaderboard : public QDialog
{
    Q_OBJECT

public:
    explicit Leaderboard(QWidget *parent = nullptr, std::vector<LeaderboardPlayer*> leaderboard = std::vector<LeaderboardPlayer*>());
    ~Leaderboard();

private slots:
    void on_closeButton_clicked();

private:
    Ui::Leaderboard *ui;
};

#endif // LEADERBOARD_H
