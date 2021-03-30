#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abalone.model/Model.h"
#include "abalone.view/InterfaceView.h"
//#include "abalone.view/View.h"
#include "abalone.model/Observer.h"


using namespace abalone::model;
using namespace abalone::view;

namespace abalone::controller{

class Controller{
private:
    Model *_game;
    InterfaceView *_view;
    //View *_view;

    /**
     * @brief checkLevelStatus method, checks the level status.
     */
    void checkLevelStatus();

    /**
     * @brief tryMove method, tries a move.
     */
    void tryMove();

    /**
     * @brief tryMoveLateral method, tries a lateral move.
     */
    void tryMoveLateral();

public:

    /**
     * @brief Controller a simple constructor of Controller.
     * @param game a pointer of Model.
     * @param view a pointer of InterfaceView.
     */
    Controller(Model *game, InterfaceView *view);

    //Controller(Model *game, View *view);

    /**
     * @brief startGame method, starts the game.
     */
    void startGame();

    /**
     * @brief addModelObserver method, adds an observer to the model.
     * @param observer a pointer of observer.
     */
    void addModelObserver(Observer * observer);
};

}

#endif
