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
    virtual Position askPosition() = 0;
public:
    virtual ~InterfaceView() = default;

    virtual void displayBoard() = 0;
    virtual int askMoveType() = 0;//Pour mouvement latéral
    virtual Position askMarblePosition() = 0;
    virtual Position askPositionMove() = 0;//Ne pas oublier mouvement latéral
    virtual std::array<Position, 2> askMarblePositionLateralMove() = 0;
    virtual Position askPositionLateralMove() = 0;
    virtual void displayMessage(std::string message) = 0;
    virtual void displayError(std::string message) = 0;

    //virtual void update(const nvs::Subject * subject) = 0;
    //virtual void update(const nvs::Subject * subject) override;
};
}
#endif // INTERFACEVIEW_H
