#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "point.h"

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();

// @Observe: Day 1 Task 4 here.
// A "slots" section and a slot will be added here for the click event on the randomButton after you complete Task 4.

private slots:
    void on_randomButton_clicked();
    void SlotTest();

    void on_addButton_clicked();
    void PointSelectedSlot(int x, int y);

private:
    Ui::PlotWindow *ui;
// @TODO: create a QGraphicsScene * that will get added to the graphicsview on the UI.
    QGraphicsScene *scene;
};

#endif // PLOTWINDOW_H
