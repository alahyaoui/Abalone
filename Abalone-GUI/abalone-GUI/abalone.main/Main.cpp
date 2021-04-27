#include <iostream>

#include "abalone.model/Game.h"
//#include "abalone.controller/Controller.h"
#include "abalone.view/View.h"

#include <QApplication>

//using namespace std;
//using namespace abalone::controller;
//using namespace abalone::model;
//using namespace Ui;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    //Game * game = new Game();
    //Ui::View * view = new View();
    Ui::View view;

    //Controller controller = Controller(game, view);
    //controller.addModelObserver(view);
    //controller.startGame();


    view.show();
    return a.exec();
}

