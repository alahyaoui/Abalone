#ifndef VIEW_H
#define VIEW_H

#include "InterfaceView.h"
#include "abalone.model/Board.h"

namespace abalone::view{

class View: public InterfaceView{
private:
    abalone::model::Board _board;

    abalone::model::Position askPosition() override;
public:
    //View();
    //~View();

    void displayBoard() override;
    int askMoveType() override;
    abalone::model::Position askMarblePosition() override;
    abalone::model::Position askPositionMove() override;
    std::array<abalone::model::Position, 2> askMarblePositionLateralMove() override;
    abalone::model::Position askPositionLateralMove() override;
    void displayMessage(std::string message) override;
    void displayError(std::string message) override;

    void update(const nvs::Subject * subject) override;
};

}// namespace abalone::view

#endif // VIEW_H
