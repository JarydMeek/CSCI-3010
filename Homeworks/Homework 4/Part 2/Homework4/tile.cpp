#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

#include "tile.h"

Tile::Tile(const int num, const int x, const int y, const int width, const int height) {
  num_ = num;
  x_ = x;
  y_ = y;
  width_ = width;
  height_ = height;
}


QRectF Tile::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

// define the actual shape of the object
QPainterPath Tile::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, height_);
    return path;
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);
    painter->drawText(this->x_+2, this->y_+12, QString(QString::fromStdString(std::to_string(this->num_))));
    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->height_));
}

