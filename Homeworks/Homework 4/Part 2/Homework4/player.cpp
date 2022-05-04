#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QTime>

#include "player.h"
#include "tile.h"

Player::Player(QColor color, const int x, const int y) {
  this->color_ = color;
  x_ = x;
  y_ = y;
}

QRectF Player::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

// define the actual shape of the object
QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    // update the line for setBrush to be this
    painter->setBrush(QBrush(color_));

    painter->drawEllipse(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}

bool Player::movePlayer(int tile_num, std::vector<std::vector<Tile*>> tiles, bool is_new, QTimer * timer) {
    timer->stop();
    if (is_new) {
        prev_locations_.push_back(curr_tile_);
    }
    int to_move_int = curr_tile_ + tile_num;

    int sign;


    if (curr_tile_ > to_move_int) {
        sign = -1;
    } else {
        sign = 1;
    }

    while (curr_tile_ != to_move_int) {
        curr_tile_+= sign;
        if (curr_tile_ >= 101) {
            break;
        }

        Tile* to_move = nullptr;
        //get coords of tile to move to;
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                if (tiles[y][x]->get_num() == curr_tile_) {
                    to_move = tiles[y][x];
                }
            }
        }
        if (to_move != nullptr) {
            x_ = 0;
            y_ = 0;
            this->setPos(to_move->get_x() + 15,to_move->get_y() + 10);

        }


        update();

        //Acts like sleep to add delay
        //came from https://stackoverflow.com/questions/3752742/how-do-i-create-a-pause-wait-function-using-qt
        QTime dieTime= QTime::currentTime().addMSecs(250);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 1);


        if (to_move_int == curr_tile_) {
            //Chutes
            if (to_move->get_chute() != -1 && to_move->get_chute() < curr_tile_) {
                int chute_to = to_move->get_chute();
                 to_move = nullptr;
                //get coords of tile to move to;
                for (int y = 0; y < 10; y++) {
                    for (int x = 0; x < 10; x++) {
                        if (tiles[y][x]->get_num() == chute_to) {
                            to_move = tiles[y][x];
                        }
                    }
                }
                if (to_move != nullptr) {
                    x_ = 0;
                    y_ = 0;
                    this->setPos(to_move->get_x() + 15,to_move->get_y() + 10);
                    curr_tile_ = chute_to;
                    update();
                    break;
                }
            }
            if (to_move->get_ladder() != -1 && to_move->get_ladder() > curr_tile_) {
                int ladder_to = to_move->get_ladder();
                 to_move = nullptr;
                //get coords of tile to move to;
                for (int y = 0; y < 10; y++) {
                    for (int x = 0; x < 10; x++) {
                        if (tiles[y][x]->get_num() == ladder_to) {
                            to_move = tiles[y][x];
                        }
                    }
                }
                if (to_move != nullptr) {
                    x_ = 0;
                    y_ = 0;
                    this->setPos(to_move->get_x() + 15,to_move->get_y() + 10);
                    curr_tile_ = ladder_to;
                    update();
                    break;
                }
            }
        }

    }
    timer->start(1000);
    return curr_tile_ >= 100;
}

void Player::undo(std::vector<std::vector<Tile*>> tiles, QTimer * timer) {
    undo_remaining_--;
    movePlayer(prev_locations_[prev_locations_.size()-1]-get_current_tile(), tiles, false, timer);
    prev_locations_.pop_back();


}
