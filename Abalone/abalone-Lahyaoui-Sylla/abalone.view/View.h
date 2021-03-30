#ifndef VIEW_H
#define VIEW_H

#include "InterfaceView.h"
#include "abalone.model/Board.h"

namespace abalone::view{

class View: public InterfaceView{
private:
    abalone::model::Board _board;
    int _turn;

    /**
     * @brief askPosition method, asks the player a position.
     * @return a position.
     */
    abalone::model::Position askPosition() const override;
public:
    //View();
    //~View();

    /**
     * @brief askPosition method, asks the player a position.
     * @return a position.
     */
    std::array<Position, 2> askMove() const override;

    /**
     * @brief displayGame method, displays the game.
     */
    void displayGame() const override;

    /**
     * @brief displayTurn method, displays the turn.
     */
    void displayTurn() const override;

    /**
     * @brief displayBoard method, displays the board of the game.
     */
    void displayBoard() const override;

    /**
     * @brief askMoveType method, asks the player what types of moves does the player want to execute.
     * @return the response an int.
     */
    int askMoveType() const override;

    /**
     * @brief askMarblePosition method, asks the player the position of the marble to make move.
     * @return a Position.
     */
    abalone::model::Position askMarblePosition() const override;

    /**
     * @brief askPositionMove method, asks the player the position to make the move.
     * @return a Position.
     */
    abalone::model::Position askPositionMove() const override;

    /**
     * @brief askMarblePositionLateralMove method, asks the player the positions of the marbles to make the move.
     * @return an array of Position.
     */
    std::array<abalone::model::Position, 2> askMarblePositionLateralMove() const override;

    /**
     * @brief askMarblePositionLateralMove method, asks the player the positions of the marbles to make the move.
     * @return an array of Position.
     */
    std::array<abalone::model::Position, 3> askLateralMove() const override;


    /**
     * @brief askPositionLateralMove method, asks the player the position to make the lateral move.
     * @return a Position.
     */
    abalone::model::Position askPositionLateralMove() const override;

    /**
     * @brief displayMessage method, displays the message given in parameter.
     * @param message a string.
     */
    void displayMessage(std::string message) const override;

    /**
     * @brief displayError method, displays the error message given in parameter
     * @param message a string
     */
    void displayError(std::string message) const override;

    void update(const nvs::Subject * subject) override;
};

}// namespace abalone::view

#endif // VIEW_H
