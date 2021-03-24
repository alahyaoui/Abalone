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
    Model *_game;//Pointeur ??
    InterfaceView *_view;//Pointeur ??
    //View *_view;

    //Game _game;//Pointeur ??
    //View _view;//Pointeur ??
    void checkLevelStatus();
    void tryMove();
    void tryMoveLateral();
public:
    Controller(Model *game, InterfaceView *view);
    //Controller(Model *game, View *view);
    void startGame();
    void addModelObserver(Observer * observer);
};

}

#endif
