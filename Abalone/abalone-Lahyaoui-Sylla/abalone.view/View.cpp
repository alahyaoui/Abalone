#include "View.h"
#include "abalone.model/Position.h"
#include "abalone.model/Game.h"

//using namespace abalone::view;
//using namespace abalone::model;

namespace abalone::view{

void View::displayGame() const {
    displayTurn();
    displayBoard();
}

void View::displayTurn() const {
    std::cout << "Tour numero : " << _turn << std::endl;
    if(_turn % 2 == 0){
        std::cout << "Tour du Player 1 (Black)" << std::endl << std::endl;
    }else{
        std::cout << "Tour du Player 2 (White)"<< std::endl << std::endl;
    }
}
void View::displayBoard() const {
    std::cout << _board.to_string() << std::endl << std::endl;
}

Position View::askPosition() const{
    std::string pos;
    char cRow;
    int row;
    int col;

    do{
        //std::cout << "Entrez la ligne et la colonne" << std::endl;
        std::cin >> pos;
        cRow = pos.at(0);
        col = pos.at(1) - 48;
    }while(!((cRow >= 'A' && cRow <= 'I') || (cRow >= 'a' && cRow <= 'i')) || !(col > 0 && col <= 9));

    switch(std::toupper(cRow)){
    case 'I':
        row = 0;
        break;
    case 'H':
        row = 1;
        break;
    case 'G':
        row = 2;
        break;
    case 'F':
        row = 3;
        break;
    case 'E':
        row = 4;
        break;
    case 'D':
        row = 5;
        break;
    case 'C':
        row = 6;
        break;
    case 'B':
        row = 7;
        break;
    case 'A':
        row = 8;
        break;
    }

    return Position(row, col-1);
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

std::array<Position, 2> View::askMove() const{
    Position posToMove;
    Position posToGo;

    std::string pos;

    char cRow1;
    int rowPos1;
    int colPos1;

    char cRow2;
    int rowPos2;
    int colPos2;

    do{
        std::cout <<"Entrez le mouvement : ";
        std::cin >> pos;
        cRow1 = pos.at(0);
        colPos1 = pos.at(1) - 48;

        cRow2 = pos.at(2);
        colPos2 = pos.at(3) - 48;
    }while(!(checkAlphabet(cRow1)) || !(checkDigit(colPos1)) ||
           !(checkAlphabet(cRow2)) || !(checkDigit(colPos2)));

    rowPos1 = convertCharRowToInt(cRow1);
    rowPos2 = convertCharRowToInt(cRow2);

    posToMove = Position(rowPos1, colPos1 - 1);
    posToGo = Position(rowPos2, colPos2 - 1);

    return std::array<Position, 2>{posToMove, posToGo};
}

int View::askMoveType() const{
    int res = 0;

    std::cout <<"Quel type de mouvement voulez vous executer ?" << std::endl
             <<"1 pour mouvement simple"<< std::endl
            <<"2 pour mouvement lateral"<< std::endl;
    std::cin >> res;

    return res;
}

Position View::askMarblePosition() const{
    std::cout << "Quelle bille voulez vous deplacer ?" << std::endl;
    return askPosition();
}

Position View::askPositionMove() const{
    std::cout << "A quelle position voulez vous deplacer votre bille ?" << std::endl;
    return askPosition();
}

std::array<Position, 2> View::askMarblePositionLateralMove() const{
    std::cout << "Quelles billes voulez vous deplacer ?" << std::endl;

    std::cout << "Bille 1 " << std::endl;
    Position posMarble1 = askPosition();

    std::cout << "Bille 2 " << std::endl;
    Position posMarble2 = askPosition();

    return std::array<Position, 2>{posMarble1, posMarble2};//{posMarble1, posMarble2} // verifier que je renvoie bien un tableau de deux elements differents
}

std::array<Position, 3> View::askLateralMove() const{
    Position posMarble1;
    Position posMarble2;
    Position posToGo;

    std::string pos;

    char cRow1;
    int rowPos1;
    int colPos1;

    char cRow2;
    int rowPos2;
    int colPos2;

    char cRow3;
    int rowPos3;
    int colPos3;

    do{
        std::cout <<"Entrez le mouvement lateral : ";
        std::cin >> pos;
        cRow1 = pos.at(0);
        colPos1 = pos.at(1) - 48;

        cRow2 = pos.at(2);
        colPos2 = pos.at(3) - 48;

        cRow3 = pos.at(4);
        colPos3 = pos.at(5) - 48;
    }while(!(checkAlphabet(cRow1)) || !(checkDigit(colPos1)) ||
           !(checkAlphabet(cRow2)) || !(checkDigit(colPos2))  ||
           !(checkAlphabet(cRow3)) || !(checkDigit(colPos3)));

    rowPos1 = convertCharRowToInt(cRow1);
    rowPos2 = convertCharRowToInt(cRow2);
    rowPos3 = convertCharRowToInt(cRow3);

    posMarble1 = Position(rowPos1, colPos1 - 1);
    posMarble2 = Position(rowPos2, colPos2 - 1);
    posToGo = Position(rowPos3, colPos3 - 1);

    return std::array<Position, 3>{posMarble1, posMarble2, posToGo};
}

Position View::askPositionLateralMove() const{
    std::cout << "A quelle position voulez vous deplacer vos billes ?" << std::endl;
    return askPosition();
}

void View::displayMessage(std::string message) const{
    std::cout << message << std::endl;
}

void View::displayError(std::string message) const{
    std::cout << message << std::endl;
}

void View::update(const nvs::Subject * subject){
    //Model * model = (Game*) subject;
    Game * game = (Game*) subject;
    _board = game->board();
    _turn = game->currentRound();

    //displayMessage("Round du model" + std::to_string(game->currentRound()));
    //displayMessage("Round de la vue" + std::to_string(_turn));

    //displayMessage("Mise à jour du board");//Fonctionne mais le board n'est pas mis a jour pq ?
}

//View::View(){};
//View::~View(){};

}// namespace abalone::view;
/*
       using namespace abalone::view;
       void Observer::update(const nvs::Subject * subject){
           //Model * model = (Game*) subject;
           Game * game = (Game*) subject;
           View view = View();
           _board = game->board();
       }*/




