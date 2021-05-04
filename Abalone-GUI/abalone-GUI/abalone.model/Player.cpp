#include "Player.h"
#include "Color.hpp"

//using namespace abalone::model;

namespace abalone::model{

Player::Player(Color color, PlayerStatus status):
    _color {color},
    _status {status},
    _marblesLoss {0}
{}

Color Player::color() const{
    return _color;
}

PlayerStatus Player::playerStatus() const{
    return _status;
}

int Player::marblesLoss() const{
    return _marblesLoss;
}

void Player::playerStatus(const PlayerStatus & status){
    this->_status = status;
}

void Player::marblesLoss(const int & marblesLoss){
    this->_marblesLoss = marblesLoss;
}

std::string Player::to_string(){
    return "Joueur"
           "\ncouleur : " + abalone::model::to_string(this->_color) +
            "\nstatut : " + abalone::model::to_string(this->_status);
}

}// namespace abalone::model
