#ifndef NAMEPLAYERS_H
#define NAMEPLAYERS_H

#include <QDialog>

namespace Ui {
class NamePlayers;
}

class NamePlayers : public QDialog
{
    Q_OBJECT

public:
    explicit NamePlayers(QWidget *parent = nullptr, int num_players = 2);
    ~NamePlayers();

private slots:
    void on_startGameButton_clicked();

private:
    Ui::NamePlayers *ui;
};

#endif // NAMEPLAYERS_H
