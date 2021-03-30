#include "View.h"

#include "abalone.model/Position.h"
#include "abalone.model/Game.h"
#include "abalone.exception/ImpossibleMovementException.hpp"

#include <algorithm>



//using namespace abalone::view;
//using namespace abalone::model;

namespace abalone::view{

void View::displayGame() {
    displayTurn();
    displayMarblesLoss();
    displayMarbles();
    displayBoard();
}

void View::displayTurn() const {
    std::cout << "Tour numero : " << _turn << std::endl;
    if(_turn % 2 == 0){
        std::cout << "Tour du Player 1 (Black)" << std::endl;
    }else{
        std::cout << "Tour du Player 2 (White)"<< std::endl;
    }
}

void View::displayMarblesLoss() const {
    std::cout << "Billes perdues : " << this->_playerMarblesLoss << std::endl << std::endl;
}

void View::displayBoard() const {
    std::cout << this->_strBoard/*_board.to_string()*/ << std::endl << std::endl;
}


void View::displayMarbles() {
    std::string strBoard = _board.to_string();
    //this->_strBoard = _board.to_string();
    std::string strMarbles = "";

    for(int i = 0; i < _board.getNbRow(); i++){
        for(int j = 0; j < _board.getNbColumn(); j++){
            if(!_board.hexagons().at(i).at(j).isFree()){//ATTENTION A NE PAS AFFICHER LES CASES PERDUES
                for(auto marble : _marbles){
                    if(marble.positionOnBoard() == Position(i, j)){
                        strMarbles += marble.to_string();;
                    }
                }
            }
        }
    }

    int j = 0;
    for(size_t i = 0; i < strBoard.size(); i++){
        if(strBoard.at(i) == '*'){
            strBoard.at(i) = strMarbles.at(j);
            j++;
        }
    }
    this->_strBoard = strBoard;
}

int convertCharRowToInt(char cRow){
    switch(std::toupper(cRow)){
    case 'I':
        return 0;
    case 'H':
        return 1;
    case 'G':
        return 2;
    case 'F':
        return 3;
    case 'E':
        return 4;
    case 'D':
        return 5;
    case 'C':
        return 6;
    case 'B':
        return 7;
    case 'A':
        return 8;
    default:
        throw "vous avez entrez une mauvaise coordonnee de ligne";
    }
}

bool checkAlphabet(char c){
    return (c >= 'A' && c <= 'I') || (c >= 'a' && c <= 'i');
}

bool checkDigit(int nb){
    return nb > 0 && nb <= 9;
}

std::vector<Position> View::askMove() const{

    std::string pos;
    do{
        std::cout <<"Entrez le mouvement : ";
        std::cin >> pos;

        if(pos.size() == 4){
            if(checkAlphabet(pos.at(0)) && checkDigit(pos.at(1) - 48) &&
                    checkAlphabet(pos.at(2)) && checkDigit(pos.at(3) - 48)){

                return askRegularMove(pos);
            }else{
                continue;
            }
        }else if(pos.size() == 6){
            if(checkAlphabet(pos.at(0)) && checkDigit(pos.at(1) - 48) &&
                    checkAlphabet(pos.at(2)) && checkDigit(pos.at(3) - 48)  &&
                    checkAlphabet(pos.at(4)) && checkDigit(pos.at(5) - 48) ){

                return askLateralMove(pos);
            }else{
                continue;
            }
        }

    }while(pos.size() == 4 || pos.size() == 6);

    throw abalone::exception::ImpossibleMovementException("Mouvement impossible, vous avez mal enregistré le mouvement !",
                                                       __FILE__, __FUNCTION__, __LINE__);
}

std::vector<Position> View::askRegularMove(std::string pos) const{
    Position posToMove;
    Position posToGo;

    char cRow1;
    int rowPos1;
    int colPos1;

    char cRow2;
    int rowPos2;
    int colPos2;


    cRow1 = pos.at(0);
    colPos1 = pos.at(1) - 48;

    cRow2 = pos.at(2);
    colPos2 = pos.at(3) - 48;

    rowPos1 = convertCharRowToInt(cRow1);
    rowPos2 = convertCharRowToInt(cRow2);

    posToMove = Position(rowPos1, colPos1 - 1);
    posToGo = Position(rowPos2, colPos2 - 1);

    return std::vector<Position>{posToMove, posToGo};
}

std::vector<Position> View::askLateralMove(std::string pos) const{
    Position posMarble1;
    Position posMarble2;
    Position posToGo;

    char cRow1;
    int rowPos1;
    int colPos1;

    char cRow2;
    int rowPos2;
    int colPos2;

    char cRow3;
    int rowPos3;
    int colPos3;


    cRow1 = pos.at(0);
    colPos1 = pos.at(1) - 48;

    cRow2 = pos.at(2);
    colPos2 = pos.at(3) - 48;

    cRow3 = pos.at(4);
    colPos3 = pos.at(5) - 48;


    rowPos1 = convertCharRowToInt(cRow1);
    rowPos2 = convertCharRowToInt(cRow2);
    rowPos3 = convertCharRowToInt(cRow3);

    posMarble1 = Position(rowPos1, colPos1 - 1);
    posMarble2 = Position(rowPos2, colPos2 - 1);
    posToGo = Position(rowPos3, colPos3 - 1);

    return std::vector<Position>{posMarble1, posMarble2, posToGo};
}

void View::displayMessage(std::string message) const{
    std::cout << message << std::endl;
}

void View::displayError(std::string message) const{
    std::cout << message << std::endl;
}

void View::update(const nvs::Subject * subject){
    Game * game = (Game*) subject;

    _board = game->board();

    _turn = game->currentRound();

    for(size_t i = 0; i < _marbles.size(); i++){
        _marbles.at(i) = *game->marbles().at(i);
    }

    //_marbles = game->marbles();

    _playerMarblesLoss = game->currentPlayerMarblesLoss();
}

}// namespace abalone::view;



