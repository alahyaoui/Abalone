#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abalone.view/View.h"
#include "abalone.model/Model.h"
#include "abalone.observer/Observer.h"


using namespace abalone::model;

namespace abalone::controller{

/**
 * @brief The Controller class, is the class responsible
 * for the game dynamics and the update of sight as you go.
 */
class Controller{
private:
    Model * _game;
    Ui::View * _view;
    //View *_view;

    /**
     * @brief checkLevelStatus method, checks the level status.
     */
    void checkLevelStatus();

    /**
     * @brief tryRegularMove method, tries a move.
     */
    void tryRegularMove(std::vector<Position> move);

    /**
     * @brief tryLateralMove method, tries a lateral move.
     */
    void tryLateralMove(std::vector<Position> lateralMove);

public:

    /**
     * @brief Controller a simple constructor of Controller.
     * @param game a pointer of Model.
     * @param view a pointer of InterfaceView.
     */
    Controller(Model *game, Ui::View *view);

    /**
     * @brief tryMove method, tries a move.
     */
    void tryMove(std::vector<Position> moves);

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
