#ifndef INTERFACEVIEW_H
#define INTERFACEVIEW_H

#include <iostream>
#include <array>
#include <vector>

#include "../abalone-core/abalone.observer/Observer.h"
#include "../abalone-core/abalone.model/Position.h"

//using namespace nvs;
using namespace abalone::model;

namespace abalone::view{

/**
 * @brief The virtual InterfaceView class, specifies which methods should be in the view.
 */
class InterfaceView: public nvs::Observer{
private:
public:

    virtual ~InterfaceView() = default;

    /**
     * @brief askMove method, asks the player a move
     * @return a vector of Position.
     */
    virtual std::vector<Position> askMove() const = 0;

    /**
     * @brief displayGame method, displays the game.
     */
    virtual void displayGame() = 0 ;

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
