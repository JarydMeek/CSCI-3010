#include "mainwindow.h"
#include "ui_mainwindow.h"

int counter = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("This is Jaryd Meek Completing PE6 Pt 2: Button has not been clicked");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    counter++;
    ui->statusbar->showMessage("This is Jaryd Meek Completing PE6 Pt 2: Button has been clicked " + QString::number(counter) + " times");
    //update();
}

