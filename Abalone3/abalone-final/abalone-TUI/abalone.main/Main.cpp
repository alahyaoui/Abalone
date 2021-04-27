#include <iostream>

#include "abalone.view/View.h"
#include "abalone.controller/Controller.h"
#include "../abalone-core/abalone.model/Game.h"

using namespace abalone::controller;
using namespace abalone::model;
using namespace abalone::view;

int main(){
    Game * game = new Game();
    View * view = new View();
    abalone::controller::Controller controller = Controller(game, view);
    controller.addModelObserver(view);
    controller.startGame();
}

