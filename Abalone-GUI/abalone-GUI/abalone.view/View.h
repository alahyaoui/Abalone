#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

#include "ghexacell.h"

#include "abalone.observer/Observer.h"
#include "abalone.model/Board.h"
#include "abalone.model/Marble.h"
#include "abalone.controller/Controller.h"


namespace Ui{
class View;
}

class View : public nvs::Observer, public QMainWindow{
    Q_OBJECT

private slots:
  void on_ghexacell_clicked(std::string value);

private:
    Ui::View *ui;
    std::vector<GHexaCell *> _gHexaCells;

    abalone::controller::Controller * _controller;

    abalone::model::Board _board;
    std::array<abalone::model::Marble, 28> _marbles;

    std::vector<abalone::model::Position> _positions;

    int _playerMarblesLoss;
    int _turn;

    void initGHexacells();

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

    void displayMessage(std::string msg);

    void displayError(std::string msg);

    void controller(abalone::controller::Controller * controller);

    void update(const nvs::Subject * subject) override;
};



#endif // VIEW_H
