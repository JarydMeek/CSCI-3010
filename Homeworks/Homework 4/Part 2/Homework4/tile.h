#ifndef TILE_H
#define TILE_H

#include <QColor>
#include <QGraphicsItem>
#include <vector>

#include "player.h"

class Tile : public QObject, public QGraphicsItem {

    // this makes it so that we can emit signals
    Q_OBJECT
public:
    Tile(const int num_, const int x, const int y, const int width, const int height);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    int get_num() const {return num_;};
    int get_x() const {return x_;};
    int get_y() const {return y_;};
    void set_chute(int chute) {chute_ = chute;}
    int get_chute() const {return chute_;};
    void set_ladder(int ladder) {ladder_ = ladder;}
    int get_ladder() const {return ladder_;};

private:
    int num_;
    int x_;
    int y_;
    int width_ = 20;
    int height_ = 20;
    int chute_ = -1;
    int ladder_ = -1;
};
#endif // TILE_H
