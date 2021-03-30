#ifndef INTERFACEVIEW_H
#define INTERFACEVIEW_H

#include <iostream>
#include <array>

#include "abalone.model/Observer.h"
#include "abalone.model/Position.h"

//using namespace nvs;
using namespace abalone::model;

namespace abalone::view{

class InterfaceView: public nvs::Observer{
private:

    /**
     * @brief askPosition method, asks the player a position.
     * @return a position.
     */
    virtual Position askPosition() const = 0;

public:

    virtual ~InterfaceView() = default;

    /**
     * @brief askPosition method, asks the player a position.
     * @return a position.
     */
    virtual std::array<Position, 2> askMove() const = 0;

    /**
     * @brief displayGame method, displays the game.
     */
    virtual void displayGame() const = 0 ;

    /**
     * @brief displayTurn method, displays the turn.
     */
    virtual void displayTurn() const = 0;

    /**
     * @brief displayBoard method, displays the board of the game.
     */
    virtual void displayBoard() const = 0;

    /**
     * @brief askMoveType method, asks the player what types of moves does the player want to execute.
     * @return the response an int.
     */
    virtual int askMoveType() const = 0;

    /**
     * @brief askMarblePosition method, asks the player the position of the marble to make move.
     * @return a Position.
     */
    virtual Position askMarblePosition() const = 0;

    /**
     * @brief askPositionMove method, asks the player the position to make the move.
     * @return a Position.
     */
    virtual Position askPositionMove() const = 0;

    /**
     * @brief askMarblePositionLateralMove method, asks the player the positions of the marbles to make the move.
     * @return an array of Position.
     */
    virtual std::array<Position, 2> askMarblePositionLateralMove() const = 0;

    /**
     * @brief askMarblePositionLateralMove method, asks the player the positions of the marbles to make the move.
     * @return an array of Position.
     */
    virtual std::array<Position, 3> askLateralMove() const = 0;

    /**
     * @brief askPositionLateralMove method, asks the player the position to make the lateral move.
     * @return a Position.
     */
    virtual Position askPositionLateralMove() const = 0;

    /**
     * @brief displayMessage method, displays the message given in parameter.
     * @param message a string.
     */
    virtual void displayMessage(std::string message) const = 0;

    /**
     * @brief displayError method, displays the error message given in parameter
     * @param message a string
     */
    virtual void displayError(std::string message) const = 0;

};
}
#endif // INTERFACEVIEW_H
