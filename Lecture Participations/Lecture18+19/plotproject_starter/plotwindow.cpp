#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QTime>

#include "plotwindow.h"
#include "ui_plotwindow.h"
#include "point.h"

// Name:
// Jaryd Meek
//

PlotWindow::PlotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotWindow)
{
    // we need to set up the ui before we draw on our scene
    ui->setupUi(this);

    // @TODO: Create a QGraphicsView * that points to the graphicsview widget on the UI
    // the QGraphicsView is the UI element that contains the
    // scene that we will actually get to draw on.
    QGraphicsView * view = ui->plotGraphicsView;

    // @TODO: Initialise the scene you created in the header for this class.
    // scene is a QGraphicsScene pointer field of this class.
    // this makes our lives easier by letting us easily access it
    // from other functions in this class.
    scene = new QGraphicsScene();

    // @TODO: Assign the scene object to the view object using setScene().
    view->setScene(scene);
    // @TODO: Make the scene the same size as the view containing it using setSceneRect()
    scene->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());

    // we'll want to generate random numbers later so we're
    // going to seed our random number generator once
    srand(static_cast<unsigned>(QTime::currentTime().msec()));


    // @TODO: Add a print statement that would write to the console instead of the application.
    // use qDebug()
    qDebug() << "This is a test debug statement";


    // @TODO: Complete Day 1, Task 2, number 1 here.
    // Draw the x and y axes on the QGraphicsScene you initialized earlier.
    int xMid = view->frameSize().width()/2;
    int yMid = view->frameSize().height()/2;

    //x-axis
    scene -> addLine(0, yMid, view->frameSize().width(), yMid);

    //y-axis
    scene -> addLine(xMid, 0,  xMid,view->frameSize().height());

    // @TODO: Day 1, Task 5, number 2 here.
    // Connect the signal of &QAbsractButton::pressed to the slot that you made for number 1
    connect(ui->randomButton, &QAbstractButton::pressed, this, &PlotWindow::SlotTest);


    int x = 0;
    int y = 0;
    int x_adj = x + (ui->plotGraphicsView->frameSize().width() / 2) - Point::get_width()/2;
    int y_adj = (-1 * y + (ui->plotGraphicsView->frameSize().height() / 2)) - Point::get_width()/2;

    QColor color(100,100,255);
    Point *p = new Point(color, x_adj, y_adj);
    scene->addItem(p);

    connect(p, &Point::PointSelected, this, &PlotWindow::PointSelectedSlot);
}

// @TODO: Day 1, Task 4, number 2 here.
// Implement the slot method that was created for the randomButton click event
void PlotWindow::on_randomButton_clicked()
{
    qDebug() << "The Random Button Has Been Clicked! *gasp*";
}

// @TODO: Day 1, Task 5, number 1 here.
// Add a slot "void SlotTest()". Make sure to add this to the header file in the "slots" section.
void PlotWindow::SlotTest()
{
    qDebug() << "This is a QDebug in the SlotTest Method";
}

PlotWindow::~PlotWindow()
{
    delete ui;
}





void PlotWindow::on_addButton_clicked()
{
    qDebug() << "The Add Button Has Been Clicked! *gasp*";
    // &safe is the address of a boolean value that will be set to True if the
    // method successfully converted the text to an int and False otherwise
    bool safe = false;
    int x = ui->xCoord->text().toInt(&safe);
    if (!safe) {
    return;
    }
    // do the same thing for the y coordinate
    int y = ui->yCoord->text().toInt(&safe);
    if (!safe) {
    return;
    }


    int x_adj = x + (ui->plotGraphicsView->frameSize().width() / 2) - Point::get_width()/2;
    int y_adj = (-1 * y + (ui->plotGraphicsView->frameSize().height() / 2)) - Point::get_width()/2;

    QColor color(100,100,255);
    Point *p = new Point(color, x_adj, y_adj);
    scene->addItem(p);

    connect(p, &Point::PointSelected, this, &PlotWindow::PointSelectedSlot);
}

void PlotWindow::PointSelectedSlot(int x, int y) {
    qDebug() << "X: " << x << "Y: " << y;
}
