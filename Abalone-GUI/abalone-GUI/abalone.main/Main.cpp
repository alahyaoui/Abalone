#include <iostream>

#include "abalone.model/Game.h"
#include "abalone.controller/Controller.h"
#include "abalone.view/View.h"

#include <QApplication>

//using namespace std;
using namespace abalone::controller;
using namespace abalone::model;
using namespace abalone::view;
//using namespace Ui;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Game * game = new Game();
    View * view = new View();

    Controller * controller = new Controller(game, view);
    controller->addModelObserver(view);
    controller->startGame();

    view->controller(controller);

    view->show();

    return a.exec();
}

