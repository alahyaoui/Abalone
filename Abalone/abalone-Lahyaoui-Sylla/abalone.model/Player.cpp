#include "Player.h"
#include "Color.hpp"

//using namespace abalone::model;

namespace abalone::model{

Player::Player(Color color, PlayerStatus status):
    _color {color},
    _status {status}
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

void Player::playerStatus(PlayerStatus status){
    this->_status = status;
}

void Player::marblesLoss(int marblesLoss){
    this->_marblesLoss = marblesLoss;
}

std::string Player::to_string(){
    return "Joueur"
           "\ncouleur : " + abalone::model::to_string(this->_color) +
            "\nstatut : " + abalone::model::to_string(this->_status);
}

}// namespace abalone::model

/*
std::string to_string(PlayerStatus playerStatus){
    std::string strPlayerStatus = "";
    if(playerStatus == PlayerStatus::WIN){
        strPlayerStatus = "Win";
    }else if(playerStatus == PlayerStatus::FAIL){
        strPlayerStatus = "Fail";
    }else{
        strPlayerStatus = "In progress";
    }
    return strPlayerStatus;
}*/
