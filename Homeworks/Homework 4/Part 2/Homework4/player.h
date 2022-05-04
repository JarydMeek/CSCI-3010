#ifndef PLAYER_H
#define PLAYER_H

#include <QColor>
#include <QGraphicsItem>
#include <vector>

#include "tile.h"

class Tile;

class Player : public QObject, public QGraphicsItem {

    // this makes it so that we can emit signals
    Q_OBJECT
public:
    Player(QColor color, const int x, const int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    bool movePlayer(int tile_num, std::vector<std::vector<Tile*>> tiles, bool is_new, QTimer * timer);
    void set_current_tile(int new_tile) {curr_tile_ = new_tile;};
    int get_current_tile() const {return curr_tile_;};
    int get_undo() const {return undo_remaining_;};
    int get_reroll() const {return reroll_remaining_;};
    void set_reroll(int new_val) {reroll_remaining_ = new_val;};
    int get_num_moves() const {return prev_locations_.size();};
    void set_name(std::string new_name) {name_ = new_name;};
    std::string get_name() {return name_;};
    void undo(std::vector<std::vector<Tile*>> tiles, QTimer * timer);

signals:
    void MovePlayer(Player *p);

private:
    int x_;
    int y_;
    QColor color_;
    int curr_tile_ = -1;
    int reroll_remaining_ = 5;
    int undo_remaining_= 3;

    std::string name_ = "Default Player Name";
    static const int width_ = 20;
    std::vector<int> prev_locations_;
};

#endif // PLAYER_H
