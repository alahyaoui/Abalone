#include "View.h"
//#include "abalone.model/Board.h"
#include "abalone.model/Position.h"
#include "abalone.model/Model.h"
#include "abalone.model/Game.h"

using namespace abalone::view;
using namespace abalone::model;


void View::displayBoard(){
    std::cout << _board.to_string() << std::endl;
}

Position View::askPosition(){
    char cRow;
    int row;
    int col;

    do{
        std::cout << "Entrez la ligne" << std::endl;
        std::cin >> cRow;
    }while(!(cRow >= 'A' && cRow <= 'I'));

    switch(cRow){
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
    }//Autrement redemander de choisir

    do{
        std::cout << "Entrez la colonne" << std::endl;
        std::cin >> col;
    }while(!(col > 0 && col <= 9));

    return Position(row, col-1);
}

int View::askMoveType(){
    int res = 0;
    std::cout <<"Quel type de mouvement voulez vous executer ?" << std::endl
             <<"1 pour mouvement simple"<< std::endl
            <<"2 pour mouvement latéral"<< std::endl;

    std::cin >> res;
    return res;
}

Position View::askMarblePosition(){
    std::cout << "Quelle bille voulez vous deplacer ?" << std::endl;
    return askPosition();
}

Position View::askPositionMove(){
    std::cout << "A quelle position voulez vous deplacer votre bille ?" << std::endl;
    return askPosition();
}

std::array<Position, 2> View::askMarblePositionLateralMove(){
    std::cout << "Quelles billes voulez vous deplacer ?" << std::endl;

    std::cout << "Bille 1 " << std::endl;
    Position posMarble1 = askPosition();

    std::cout << "Bille 2 " << std::endl;
    Position posMarble2 = askPosition();

    return std::array<Position, 2>{posMarble1, posMarble2};//{posMarble1, posMarble2} // verifier que je renvoie bien un tableau de deux elements differents
}

Position View::askPositionLateralMove(){
    std::cout << "A quelle position voulez vous deplacer vos billes ?" << std::endl;
    return askPosition();
}

void View::displayMessage(std::string message){
    std::cout << message << std::endl;
}

void View::displayError(std::string message){
    std::cout << message << std::endl;
}

void View::update(const nvs::Subject * subject){
    //Model * model = (Game*) subject;
    Game * game = (Game*) subject;
    _board = game->board();
}
/*
View::View(){};
View::~View(){};
*/
