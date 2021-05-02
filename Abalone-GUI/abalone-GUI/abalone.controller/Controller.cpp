#include "Controller.h"
//#include <exception>
#include "abalone.model/Player.h"
#include "abalone.model/Color.hpp"
#include "abalone.model/Position.h"
#include "abalone.exception/InvalidGameStatusException.hpp"
#include "abalone.exception/DirectionException.hpp"
#include "abalone.exception/MarbleException.hpp"

#include <iostream>
#include <exception>

//using namespace nvs;
//using namespace abalone::controller;
//using namespace abalone::model;

namespace abalone::controller{

Controller::Controller(Model *game, View *view):
    _game {game},
    _view {view}
{}

void Controller::startGame(){
    _game->startGame();
}

void Controller::tryMove(std::vector<Position> moves){
    auto move = moves;
    if(_game->gameStatus() == GameStatus::IN_PROGRESS){
        if(move.size() == 2){
            tryRegularMove(move);
        }else if(move.size() == 3){
            tryLateralMove(move);
        }
    }else{
        checkLevelStatus();
    }
}

void Controller::tryRegularMove(std::vector<Position> move){

    auto marbleToMove = move.at(0);
    auto positionToGo = move.at(1);

    try{
        _game->move(marbleToMove, positionToGo);
        _game->incRound();//Si ça fonctionne incremente le compteur de round
    }catch(abalone::exception::MarbleException marbleException){
        //_view->displayError(marbleException.to_string());
        _view->displayError(marbleException.msg());
    }catch(abalone::exception::DirectionException directionException){
        //_view->displayError(directionException.to_string());
        _view->displayError(directionException.msg());
    }catch(abalone::exception::InvalidGameStatusException statusException){
        //_view->displayError(statusException.to_string());
        _view->displayError(statusException.msg());
    }
}

void Controller::tryLateralMove(std::vector<Position> lateralMove){

    auto marbletoMove1 = lateralMove.at(0);
    auto marbletoMove2 = lateralMove.at(1);
    auto positionToGo = lateralMove.at(2);

    try{
        _game->move(marbletoMove1, marbletoMove2, positionToGo);
        _game->incRound();
    }catch(abalone::exception::MarbleException marbleException){
        //_view->displayError(marbleException.to_string());
        _view->displayError(marbleException.msg());
    }catch(abalone::exception::DirectionException directionException){
        //_view->displayError(directionException.to_string());
        _view->displayError(directionException.msg());
    }catch(abalone::exception::InvalidGameStatusException statusException){
        //_view->displayError(statusException.to_string());
        _view->displayError(statusException.msg());
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

