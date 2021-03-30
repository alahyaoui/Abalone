#include <iostream>

#include "abalone.model/Game.h"
#include "abalone.controller/Controller.h"
#include "abalone.view/View.h"

using namespace std;
using namespace abalone::controller;
using namespace abalone::model;
using namespace abalone::view;

int main(){
    Game * game = new Game();
    View * view = new View();
    Controller controller = Controller(game, view);
    controller.addModelObserver(view);//Pourquoi premier tour n'affiche pas avec l'affichage final.
    controller.startGame();
}

