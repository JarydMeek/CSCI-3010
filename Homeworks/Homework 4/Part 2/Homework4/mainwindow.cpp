/**
Jaryd Meek
HW 4
This program creates and runs chutes and ladders game
*/


#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QRandomGenerator>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <vector>
#include <QDialog>
#include <QPropertyAnimation>
#include <fstream>
#include <sstream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include "tile.h"
#include "numplayers.h"
#include "nameplayers.h"
#include "leaderboard.h"

/*
  Function: default constructor, sets up UI
  Input: parent widget (in this case, nullptr)
  Returns: none
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup main_view and main_scene_
    main_view_ = ui->mainView;
    main_scene_ = new QGraphicsScene;
    main_view_->setScene(main_scene_);
    main_view_->setSceneRect(0,0,main_view_->frameSize().width(),main_view_->frameSize().height());
    main_view_->setFrameStyle(0);

    //Setup home_view and home_scene_
    home_view_ = ui->homeView;
    home_scene_ = new QGraphicsScene;
    home_view_->setScene(home_scene_);
    home_view_->setSceneRect(0,0,home_view_->frameSize().width(),home_view_->frameSize().height());
    home_view_->setFrameStyle(0);

    //Setup current_turn_view and current_turn_scene_
    current_turn_view_ = ui->currentTurnView;
    current_turn_scene_ = new QGraphicsScene;
    current_turn_view_->setScene(current_turn_scene_);
    current_turn_view_->setSceneRect(0,0,current_turn_view_->frameSize().width(),current_turn_view_->frameSize().height());
    current_turn_view_->setFrameStyle(0);

    //random number seed
    srand(static_cast<unsigned>(QTime::currentTime().msec()));

    num_players_ = 2;





    //create board
    int curr_count = 100;
    for (int y = 0; y < 10; y++) {
        std::vector<Tile*> curr_row;

        if (y%2 == 0 && y != 0) {
            curr_count-=2;
        }
        for (int x = 0; x < 10; x++) {
            Tile* newTile = new Tile(curr_count, x*(main_view_->frameSize().width()/10), y*(main_view_->frameSize().height()/10), main_view_->frameSize().width()/10, main_view_->frameSize().height()/10);
            curr_row.push_back(newTile);
            if (y % 2 != 0) {
                curr_count++;
            } else {
                curr_count--;
            }

        }
        curr_count-= 9;
        tiles_.push_back(curr_row);
    }

    for (std::vector<Tile *> curr_row : tiles_) {
        for (Tile* curr : curr_row) {
            main_scene_->addItem(curr);
        }
    }

    //disable all buttons except new game
    ui->RollButton->setEnabled(false);
    ui->startGameButton->setEnabled(false);
    ui->endGameButton->setEnabled(false);
    ui->quitGameButton->setEnabled(false);
    ui->undoButton->setEnabled(false);
    ui->reRollButton->setEnabled(false);
    ui->RollButton->setEnabled(false);
    ui->moveButton->setEnabled(false);



    //Ok, we've drawn the basics, lets start to get some logic.

    loadLeaderboard("../../../../Leaderboard.txt");
}

/*
  Function: deconstructor, saves leaderboard
  Input: none
  Returns: none
*/
MainWindow::~MainWindow()
{
    saveLeaderboard("../../../../Leaderboard.txt");
    delete ui;
}

/*
  Function: sets up player arrays, and adds players to screen
  Input: none
  Returns: none
*/
void MainWindow::setup_players() {
    //create players and store in home.
    int curr_x = 15;
    int curr_y = 10;
    for (int x = 0; x < num_players_; x++) {

        Player * p = new Player(color_choices_[x], curr_x, curr_y);
        Player * p2 = new Player(color_choices_[x], 15, 10);
        if (x == 1) {
            curr_y += (home_view_->frameSize().height()/2);
            curr_x = 15;
        } else {
            curr_x += (home_view_->frameSize().width()/3)+5;
        }
        still_playing_players_.push_back(p);
        still_playing_players_current_turn_.push_back(p2);
    }
    // add it to the scene
    for (Player* curr : still_playing_players_) {
        home_scene_->addItem(curr);
    }
}

/*
  Function: handles changing turns, updating ui
  Input: none
  Returns: none
*/
void MainWindow::change_turn() {
    current_timer_ = 10;
    ui->timeChange->setText(QString::fromStdString(std::to_string(current_timer_) + " s"));
    current_turn_scene_->removeItem(still_playing_players_current_turn_[current_turn_]);
    ui->rollChange->setText("");
    current_turn_++;
    roll_ = -1;
    if (current_turn_ >= (int)still_playing_players_current_turn_.size()) {
        current_turn_ = 0;
    }
    current_turn_scene_->addItem(still_playing_players_current_turn_[current_turn_]);

    if (still_playing_players_[current_turn_]->get_undo() == 0 || still_playing_players_[current_turn_]->get_current_tile() == -1 || still_playing_players_[current_turn_]->get_num_moves() < 2) {
        ui->undoButton->setEnabled(false);
    } else {
        ui->undoButton->setEnabled(true);
    }
    ui->reRollButton->setEnabled(false);
    ui->RollButton->setEnabled(true);
    ui->moveButton->setEnabled(false);


}

/*
  Function: saves player names from ui input
  Input: string of names for each player to save
  Returns: none
*/
void MainWindow::setNamePlayers(std::string names[]) {
    for (int x = 0; x < num_players_; x++) {
        still_playing_players_[x]->set_name(names[x]);
    }
}

/*
  Function: finds and returns pointer to tile on board matching tile number passed to function
  Input: integer of tile number to find
  Returns: pointer to tile matching number
*/
Tile * MainWindow::get_tile(int to_find) {
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            if (tiles_[y][x]->get_num() == to_find) {
                return tiles_[y][x];
            }
        }
    }
    return NULL;
}

/*
  Function: loads leaderboard from csv
  Input: csv filename
  Returns: none
*/
void MainWindow::loadLeaderboard(std::string filename) {

    std::ifstream leaderboard;
    leaderboard.open(filename);
    std::vector<std::string> storage;
    std::string currentLine;

    while (getline(leaderboard, currentLine)) {
        std::string curr;
        std::istringstream split(currentLine);
        while (getline(split,curr, ',')) {
            storage.push_back(curr);
        }
        LeaderboardPlayer * new_player = new LeaderboardPlayer(storage[0],std::stoi(storage[1]),std::stoi(storage[2]),std::stod(storage[3]));
        leaderboard_storage_.push_back(new_player);
        storage.clear();
    }
    leaderboard.close();
}

/*
  Function: boolean compare of structs for sorting algorithm
  Input: two Leaderboard Players
  Returns: bool if a > b
*/
bool sortAlgo(LeaderboardPlayer* a, LeaderboardPlayer* b) { return a->win_percentage > b->win_percentage; }

/*
  Function: sorts leaderboard based on win percentage
  Input: pointer to vector of leaderboard storage
  Returns: none
*/
void sortLeaderboard(std::vector<LeaderboardPlayer*> * leaderboard) {
    std::sort(leaderboard->begin(), leaderboard->end(), sortAlgo);
}

/*
  Function: adds user to leaderboard, or updates user if already in leaderboard
  Input: username to add/update, boolean on if that user won or not
  Returns: none
*/
void MainWindow::addToLeaderboard(std::string username, bool win) {
    for (LeaderboardPlayer *curr : leaderboard_storage_) {
        if (curr->name == username) {
            if (win) {
                curr->wins++;
            } else {
                curr->losses++;
            }
            curr->win_percentage = ((double)curr->wins)/(curr->wins+curr->losses);
            return;
        }
    }
    LeaderboardPlayer * new_player = new LeaderboardPlayer(username,0,0,0);
    if (win) {
        new_player->wins++;
    } else {
        new_player->losses++;
    }
    new_player->win_percentage = ((double)new_player->wins)/(new_player->wins+new_player->losses);
    leaderboard_storage_.push_back(new_player);
    return;
}

/*
  Function: saves leaderboard to csv
  Input: filename for csv to save to
  Returns: none
*/
void MainWindow::saveLeaderboard(std::string filename) {
    std::ofstream ofs(filename.c_str(), std::ios_base::out);

    for (LeaderboardPlayer *curr : leaderboard_storage_) {
        ofs << curr->name << "," << curr->wins << "," << curr->losses << "," << curr->win_percentage << "\n";
    }

    ofs.close();

}

/*
  Function: disables all menu buttons
  Input: none
  Returns: none
*/
void MainWindow::disableMenu() {
    ui->newGameButton->setEnabled(false);
    ui->startGameButton->setEnabled(false);
    ui->endGameButton->setEnabled(false);
    ui->quitGameButton->setEnabled(false);
    ui->undoButton->setEnabled(false);
    ui->reRollButton->setEnabled(false);
    ui->RollButton->setEnabled(false);
    ui->moveButton->setEnabled(false);
    ui->showLeaderboard->setEnabled(false);
}

/*
  Function: enables all menu buttons
  Input: none
  Returns: none
*/
void MainWindow::enableMenu() {
    ui->newGameButton->setEnabled(true);
    ui->startGameButton->setEnabled(true);
    ui->endGameButton->setEnabled(true);
    ui->quitGameButton->setEnabled(true);
    ui->undoButton->setEnabled(true);
    ui->reRollButton->setEnabled(true);
    ui->RollButton->setEnabled(true);
    ui->moveButton->setEnabled(true);
    ui->showLeaderboard->setEnabled(true);
}

/*
  Function: handle roll button being clicked
  Input: none
  Returns: none
*/
void MainWindow::on_RollButton_clicked()
{
    roll_ = (QRandomGenerator::global()->generate() % 11)+2;
    ui->rollChange->setText(std::to_string(roll_).c_str());
    ui->RollButton->setEnabled(false);
    ui->moveButton->setEnabled(true);
    if (still_playing_players_[current_turn_]->get_reroll() > 0) {
        ui->reRollButton->setEnabled(true);
    }
}

/*
  Function: handle move button being clicked
  Input: none
  Returns: none
*/
void MainWindow::on_moveButton_clicked()
{
    bool game_over = false;
    if (still_playing_players_[current_turn_]->get_current_tile() == -1 && roll_ == 6) {
        home_scene_->removeItem(still_playing_players_[current_turn_]);
        main_scene_->addItem(still_playing_players_[current_turn_]);
        still_playing_players_[current_turn_]->set_current_tile(0);
        still_playing_players_[current_turn_]->movePlayer(1,tiles_, true, timer_);
    } else if (roll_ != -1 && still_playing_players_[current_turn_]->get_current_tile() != -1) {
        disableMenu();
        game_over = still_playing_players_[current_turn_]->movePlayer(roll_,tiles_,true, timer_);\
        enableMenu();
    }
    if (game_over) {
        on_endGameButton_clicked();
    } else {
        change_turn();
    }
}

/*
  Function: handle quit game button being clicked
  Input: none
  Returns: none
*/
void MainWindow::on_quitGameButton_clicked()
{
    main_scene_->removeItem(still_playing_players_[current_turn_]);
    home_scene_->removeItem(still_playing_players_[current_turn_]);
    current_turn_scene_->removeItem(still_playing_players_current_turn_[current_turn_]);
    addToLeaderboard(still_playing_players_[current_turn_]->get_name(), false);
    still_playing_players_.erase(std::remove(still_playing_players_.begin(), still_playing_players_.end(), still_playing_players_[current_turn_]), still_playing_players_.end());
    still_playing_players_current_turn_.erase(std::remove(still_playing_players_current_turn_.begin(), still_playing_players_current_turn_.end(), still_playing_players_current_turn_[current_turn_]), still_playing_players_current_turn_.end());

    if (current_turn_ >= (int)still_playing_players_current_turn_.size()) {
        current_turn_ = 0;
    }
    current_turn_scene_->addItem(still_playing_players_current_turn_[current_turn_]);



    if (still_playing_players_.size() < 2) {
        on_endGameButton_clicked();
    }
}

/*
  Function: handle new game button being clicked
  Input: none
  Returns: none
*/
void MainWindow::on_newGameButton_clicked()
{
    //Clear stuff
    for (QGraphicsLineItem * curr : lines_) {
        main_scene_->removeItem(curr);
    }
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            tiles_[y][x]->set_chute(-1);
            tiles_[y][x]->set_ladder(-1);
        }
    }

    for (Player * curr : still_playing_players_) {
        main_scene_->removeItem(curr);
        home_scene_->removeItem(curr);
    }
    for (Player * curr : still_playing_players_current_turn_) {
        current_turn_scene_->removeItem(curr);
    }

    still_playing_players_.clear();
    still_playing_players_current_turn_.clear();
    current_timer_ = 10;
    current_turn_ = 0;


    NumPlayers * num_players_dialog = new NumPlayers(this);
    num_players_dialog->show();
    num_players_dialog->setModal(true);
    num_players_dialog->exec();

    setup_players();

    NamePlayers * name_players_dialog = new NamePlayers(this, num_players_);
    name_players_dialog->show();
    name_players_dialog->setModal(true);
    name_players_dialog->exec();


    //Reset stuff
    current_turn_scene_->addItem(still_playing_players_current_turn_[current_turn_]);
    //disable all buttons except new game
    ui->RollButton->setEnabled(false);
    ui->startGameButton->setEnabled(true);
    ui->endGameButton->setEnabled(false);
    ui->quitGameButton->setEnabled(false);
    ui->undoButton->setEnabled(false);
    ui->reRollButton->setEnabled(false);
    ui->RollButton->setEnabled(false);
    ui->moveButton->setEnabled(false);

    //Ladders
    QPen ladderPen;
    ladderPen.setColor("tan");
    ladderPen.setStyle(Qt::DashLine);
    ladderPen.setWidth(5);
    for (int x = 0; x < 7; x++) {
        while (true) {
            int random = (QRandomGenerator::global()->generate() % 100) + 1;
            Tile * curr = get_tile(random);
            int random2 = (QRandomGenerator::global()->generate() % 100) + 1;
            Tile * curr2 = get_tile(random2);
            if (curr->get_ladder() == -1 && curr->get_chute() == -1 && curr2->get_ladder() == -1 && curr2->get_chute() == -1 && random != random2) {
                curr->set_ladder(random2);
                curr2->set_ladder(random);
                QGraphicsLineItem* line = main_scene_->addLine(curr->get_x()+25,curr->get_y()+25,curr2->get_x()+25,curr2->get_y()+25, ladderPen);
                lines_.push_back(line);
                break;
            }
        }
    }

    //Chutes
    QPen chutePen;
    chutePen.setColor("red");
    chutePen.setWidth(5);
    for (int x = 0; x < 6; x++) {
        while (true) {
            int random = (QRandomGenerator::global()->generate() % 100) + 1;
            Tile * curr = get_tile(random);
            int random2 = (QRandomGenerator::global()->generate() % 100) + 1;
            Tile * curr2 = get_tile(random2);
            if (curr->get_ladder() == -1 && curr->get_chute() == -1 && curr2->get_ladder() == -1 && curr2->get_chute() == -1 && random != random2 && random != 100 && random2 != 100) {
                curr->set_chute(random2);
                curr2->set_chute(random);
                QGraphicsLineItem* line = main_scene_->addLine(curr->get_x()+25,curr->get_y()+25,curr2->get_x()+25,curr2->get_y()+25, chutePen);
                lines_.push_back(line);
                break;
            }
        }
    }
}

/*
  Function: handle start game button being clicked
  Input: none
  Returns: none
*/
void MainWindow::on_startGameButton_clicked()
{
    //Set UI
    ui->newGameButton->setEnabled(false);
    ui->startGameButton->setEnabled(false);
    ui->endGameButton->setEnabled(true);
    ui->quitGameButton->setEnabled(true);
    ui->undoButton->setEnabled(false);
    ui->reRollButton->setEnabled(false);
    ui->RollButton->setEnabled(true);
    ui->moveButton->setEnabled(false);
    ui->showLeaderboard->setEnabled(false);

    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &MainWindow::updateTimer);
    current_timer_ = 10;
    timer_->start(1000);
}

/*
  Function: handle end game button being clicked
  Input: none
  Returns: none
*/
void MainWindow::on_endGameButton_clicked()
{
    //Set ui
    timer_->stop();
    ui->newGameButton->setEnabled(true);
    ui->startGameButton->setEnabled(false);
    ui->endGameButton->setEnabled(false);
    ui->quitGameButton->setEnabled(false);
    ui->undoButton->setEnabled(false);
    ui->reRollButton->setEnabled(false);
    ui->RollButton->setEnabled(false);
    ui->moveButton->setEnabled(false);
    ui->showLeaderboard->setEnabled(true);


    //Handle Leaderboard

    for (QGraphicsLineItem * curr : lines_) {
        main_scene_->removeItem(curr);
    }

    for (Player * curr : still_playing_players_) {
        main_scene_->removeItem(curr);
        home_scene_->removeItem(curr);
    }
    for (Player * curr : still_playing_players_current_turn_) {
        current_turn_scene_->removeItem(curr);
    }


    for (Player * curr : still_playing_players_) {
        addToLeaderboard(curr->get_name(), curr->get_current_tile() >= 100);
    }
        on_showLeaderboard_clicked();
}

/*
  Function: handle undo button being clicked
  Input: none
  Returns: none
*/
void MainWindow::on_undoButton_clicked()
{
    if (still_playing_players_[current_turn_]->get_current_tile() != -1) {
        disableMenu();
        still_playing_players_[current_turn_]->undo(tiles_, timer_);
        enableMenu();
    }
    if (still_playing_players_[current_turn_]->get_undo() == 0 || still_playing_players_[current_turn_]->get_num_moves() < 2) {
        ui->undoButton->setEnabled(false);
    }
}

/*
  Function: handle reroll button being clicked
  Input: none
  Returns: none
*/
void MainWindow::on_reRollButton_clicked()
{
    roll_ = (QRandomGenerator::global()->generate() % 11)+2;
    ui->rollChange->setText(std::to_string(roll_).c_str());
    still_playing_players_[current_turn_]->set_reroll(still_playing_players_[current_turn_]->get_reroll()-1);
    if (still_playing_players_[current_turn_]->get_reroll() == 0) {
        ui->reRollButton->setEnabled(false);
    }
}

/*
  Function: handle show leaderboard button being clicked
  Input: none
  Returns: none
*/
void MainWindow::on_showLeaderboard_clicked()
{
    sortLeaderboard(&leaderboard_storage_);
    Leaderboard * leaderboard_dialog = new Leaderboard(this, leaderboard_storage_);
    leaderboard_dialog->show();
    leaderboard_dialog->setModal(true);
    leaderboard_dialog->exec();
}

/*
  Function: update timer on screen when called by qtimer
  Input: none
  Returns: none
*/
void MainWindow::updateTimer()
{
    current_timer_--;
    if (current_timer_ == 0) {
        change_turn();
    }
    ui->timeChange->setText(QString::fromStdString(std::to_string(current_timer_) + " s"));

}




