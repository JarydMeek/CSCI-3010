#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColor>
#include <vector>

#include"player.h"
#include"tile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


struct LeaderboardPlayer {
    LeaderboardPlayer(std::string name, int wins, int losses, double win_percent) {
        this->name = name;
        this->wins = wins;
        this->losses = losses;
        this->win_percentage = win_percent;
    }
    std::string name;
    int wins;
    int losses;
    double win_percentage;

    bool operator<(const LeaderboardPlayer &o) const {return win_percentage < o.win_percentage;}
    bool operator>(const LeaderboardPlayer &o) const {return win_percentage > o.win_percentage;}

};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setup_players();
    void change_turn();
    void setNumPlayers(int numPlayers) { num_players_ = numPlayers; }
    void setNamePlayers(std::string names[]);
    Tile* get_tile(int to_find);
    void loadLeaderboard(std::string filename);
    void addToLeaderboard(std::string username, bool win);
    void saveLeaderboard(std::string filename);
    void disableMenu();
    void enableMenu();

private slots:
    void on_RollButton_clicked();
    void on_moveButton_clicked();
    void on_quitGameButton_clicked();
    void on_newGameButton_clicked();
    void on_startGameButton_clicked();
    void on_endGameButton_clicked();
    void on_undoButton_clicked();
    void on_reRollButton_clicked();
    void on_showLeaderboard_clicked();
    void updateTimer();


private:
    //UI Stuff
    Ui::MainWindow *ui;
    QGraphicsScene *main_scene_;
    QGraphicsScene *home_scene_;
    QGraphicsScene *current_turn_scene_;
    QGraphicsView * main_view_;
    QGraphicsView * home_view_;
    QGraphicsView * current_turn_view_;
    QColor color_choices_[4] = {QColor(255,0,0), QColor(0,255,0), QColor(0,0,255), QColor(255,255,0)};
    std::vector<QGraphicsLineItem*> lines_;

    //Logic stuff
    std::vector<Player*> still_playing_players_;
    std::vector<Player*> still_playing_players_current_turn_;
    std::vector<std::vector<Tile*>> tiles_;
    std::vector<LeaderboardPlayer*> leaderboard_storage_;
    int current_turn_;
    int roll_;
    int current_timer_;
    int num_players_;
    QTimer * timer_;

};
#endif // MAINWINDOW_H



