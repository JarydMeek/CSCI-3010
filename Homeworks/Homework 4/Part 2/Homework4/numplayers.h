#ifndef NUMPLAYERS_H
#define NUMPLAYERS_H

#include <QDialog>

namespace Ui {
class NumPlayers;
}

class NumPlayers : public QDialog
{
    Q_OBJECT

public:
    explicit NumPlayers(QWidget *parent = nullptr);
    ~NumPlayers();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NumPlayers *ui;
};

#endif // NUMPLAYERS_H
