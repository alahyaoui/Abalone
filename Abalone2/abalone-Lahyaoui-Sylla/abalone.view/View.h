#ifndef VIEW_H
#define VIEW_H

#include "InterfaceView.h"
#include "abalone.model/Board.h"

namespace abalone::view{

class View: public InterfaceView{
private:
    Board _board;

    Position askPosition();
public:
    View() = default;
    virtual ~View() = default;

    void displayBoard();
    int askMoveType();//Pour mouvement latéral
    Position askMarblePosition();
    Position askPositionMove();//Ne pas oublier mouvement latéral
    std::array<Position, 2> askMarblePositionLateralMove();
    Position askPositionLateralMove();
    void displayMessage(std::string message);
    void displayError(std::string message);

    void update(const nvs::Subject * subject);
};

}// namespace abalone::view

#endif // VIEW_H
