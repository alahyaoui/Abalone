#include "Controller.h"
//#include <exception>
#include "abalone.model/Player.h"
#include "abalone.model/Color.h"

using namespace nvs;
using namespace abalone::controller;
using namespace abalone::model;


Controller::Controller(Model *game, InterfaceView *view):
    _game {game},
    _view {view}
{}

void Controller::startGame(){
    _game->startGame();
    while (_game->gameStatus() == GameStatus::IN_PROGRESS) {
        _view->displayBoard();
        if(_view->askMoveType() == 1){
            tryMove();
        }else{
            tryMoveLateral();
        }
    }
    checkLevelStatus();
}
void Controller::tryMove(){
    try{
        _game->move(_view->askMarblePosition(), _view->askPositionMove());//Verfier si on me donne une position valide
        _game->incRound();//Si ça fonctionne incremente le compteur de round
    }catch(std::exception e){//Traiter le mouvement impossible
        _view->displayError("Mouvement impossible");
    }
}

void Controller::tryMoveLateral(){
    try{
        _game->move(_view->askMarblePosition(), _view->askMarblePosition(), _view->askPositionMove());
        _game->incRound();
    }catch(std::exception e){//Traiter le mouvement impossible
        _view->displayError("Mouvement impossible");
    }
}

void Controller::checkLevelStatus() {
    switch (_game->gameStatus()) {
    case GameStatus::IN_PROGRESS:
        _view->displayMessage("La partie est en cours");
        break;
    case GameStatus::OVER:
        _view->displayMessage("La partie est terminée !");
        for(Player p : _game->players()){
            _view->displayMessage(p.to_string()+"\n");
        }
        break;
    case GameStatus::NOT_STARTED:
        _view->displayMessage("La partie n'a pas commencé");
        break;
    default:
        _view->displayError("Erreur dans le statut du niveau");
    }
}

void Controller::addModelObserver(Observer *observer){
    _game->registerObserver(observer);
}

