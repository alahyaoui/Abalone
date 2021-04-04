#ifndef VIEW_H
#define VIEW_H

#include "InterfaceView.h"
#include "abalone.model/Board.h"
#include "abalone.model/Marble.h"

namespace abalone::view{

/**
 * @brief The View class, is dedicated to the display of the game board and prepares the user's
 * entries.
 */
class View: public InterfaceView{
private:
    abalone::model::Board _board;
    std::string _strBoard;
    std::array<abalone::model::Marble, 28> _marbles;

    int _playerMarblesLoss;
    int _turn;
    /**
     * @brief askRegularMove method, asks the player a regular move.
     * @return a vector of Position.
     */
    std::vector<Position> askRegularMove(std::string pos) const;

    /**
     * @brief askLateralMove method, asks the player the lateralMove.
     * @return a vector of Position.
     */
    std::vector<Position> askLateralMove(std::string pos) const;

    /**
     * @brief displayTurn method, displays the turn.
     */
    void displayTurn() const;

    /**
     * @brief displayMarblesLoss method, displays the marbles loos of the current player.
     */
    void displayMarblesLoss() const;

    /**
     * @brief displayBoard method, displays the board of the game.
     */
    void displayBoard() const;

    /**
     * @brief displayMarbles method, displays the marbles of the game.
     */
    void displayMarbles();
public:
    //View();
    //~View();

    /**
     * @brief askMove method, asks the player a move
     * @return a vector of Position.
     */
    std::vector<Position> askMove() const override;

    /**
     * @brief displayGame method, displays the game.
     */
    void displayGame() override;

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
