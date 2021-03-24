#include "Controller.h"
//#include <exception>
#include "abalone.model/Player.h"
#include "abalone.model/Color.h"
#include "abalone.model/Position.h"
#include "abalone.exception/InvalidGameStatusException.h"
#include "abalone.exception/ImpossibleMovementException.h"

#include <iostream>
#include <exception>

//using namespace nvs;
//using namespace abalone::controller;
//using namespace abalone::model;

namespace abalone::controller{

Controller::Controller(Model *game, InterfaceView *view):
    _game {game},
    _view {view}
{}
/*
Controller::Controller(Model *game, View *view):
    _game {game},
    _view {view}
{}
*/

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
    auto marbleToMove  = _view->askMarblePosition();
    auto positionToGo = _view->askPositionMove();
    try{
        _game->move(marbleToMove, positionToGo);//Verfier si on me donne une position valide
        _game->incRound();//Si ça fonctionne incremente le compteur de round
    }catch(abalone::exception::ImpossibleMovementException moveException){//Traiter le mouvement impossible
        _view->displayError(moveException.msg());
        tryMove();
    }catch(abalone::exception::InvalidGameStatusException statusException){
        _view->displayError("Erreur dans le statut de la partie" + statusException.msg());
    }
}

void Controller::tryMoveLateral(){
    try{
        _game->move(_view->askMarblePosition(), _view->askMarblePosition(), _view->askPositionMove());
        _game->incRound();
    }catch(abalone::exception::ImpossibleMovementException moveException){//Traiter le mouvement impossible
        _view->displayError(moveException.msg());
        tryMove();
    }catch(abalone::exception::InvalidGameStatusException statusException){
        _view->displayError("Erreur dans le statut de la partie" + statusException.msg());
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

}// namespace abalone::controller

