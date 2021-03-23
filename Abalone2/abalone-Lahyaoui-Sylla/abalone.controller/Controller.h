#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abalone.model/Model.h"
#include "abalone.view/InterfaceView.h"
#include "abalone.model/Observer.h"


using namespace abalone::model;
using namespace abalone::view;

namespace abalone::controller{

class Controller{
private:
    Model *_game;//Pointeur ??
    InterfaceView *_view;//Pointeur ??

    //Game _game;//Pointeur ??
    //View _view;//Pointeur ??
    void checkLevelStatus();
    void tryMove();
    void tryMoveLateral();
public:
    Controller(Model *game, InterfaceView *view);
    void startGame();
    void addModelObserver(Observer * observer);
};

}

#endif
