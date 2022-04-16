#include "Marble.h"
#include "Board.h"
#include "Direction.hpp"
#include "abalone.exception/ImpossibleMovementException.hpp"
#include "abalone.exception/MarbleNotFoundException.hpp"

//using namespace abalone::model;
//using namespace std;

using namespace abalone::exception;

namespace abalone::model{

Marble::Marble(Position positionOnBoard, Color color):
    _positionOnBoard {positionOnBoard},
    _color {color}
{}

Marble::Marble():Marble(Position(0,0), Color::NONE){}

void Marble::move(Board & board, const Position & positionToGo, std::array<Marble*, 28> & marbles){
    Position nextPosition;
    Position nextEnemyPosition;

    Direction direction = computeDirection(this->_positionOnBoard, positionToGo);
    nextPosition = this->_positionOnBoard.next(direction);
    nextEnemyPosition = this->_positionOnBoard.next(direction);

    int countSameColor = 1;
    int countOtherColor = 0;

    if(nextPosition != positionToGo){
        throw ImpossibleMovementException("mouvement impossible, "
                                          "la case étant trop éloigné "
                                          "pour effectuer le mouvement.",
                                          __FILE__, __FUNCTION__, __LINE__);
    }else{
        while(!board.isHexagonFree(nextPosition)
              && getMarble(marbles, nextPosition)->_color == this->_color){
            countSameColor++;
            nextPosition = nextPosition.next(direction);
        }
        if(countSameColor > 3){
            throw ImpossibleMovementException("mouvement impossible, "
                                              "trop de billes alliés sur le chemin.",
                                              __FILE__, __FUNCTION__, __LINE__);
        }else{
            if(!board.isInside(nextPosition)){
                throw ImpossibleMovementException("mouvement impossible, "
                                                  "la position du déplacement "
                                                  "est en dehors du board.",
                                                  __FILE__, __FUNCTION__, __LINE__);
            }else{
                if(board.isHexagonFree(nextPosition)){
                    moveFree(board, nextPosition);
                }else{
                    nextEnemyPosition = nextPosition;
                    while(!board.isHexagonFree(nextEnemyPosition)//avance le nextPositioEnemy tant qu'il y a un ennemi
                          && getMarble(marbles, nextEnemyPosition)->_color != this->_color){

                        countOtherColor++;
                        nextEnemyPosition = nextEnemyPosition.next(direction);
                    }

                    if(countOtherColor >= countSameColor){
                        throw ImpossibleMovementException("mouvement impossible, "
                                                          "pas assez de billes alliés "
                                                          "pour pousser les billes ennemies.",
                                                          __FILE__, __FUNCTION__, __LINE__);
                    }else{
                        if(!board.isInside(nextEnemyPosition)){
                            moveAndPushInVoid(board, nextPosition, marbles);
                        }else{
                            if(!board.isHexagonFree(nextEnemyPosition)){
                                throw ImpossibleMovementException("mouvement impossible, "
                                                                  "bille allié qui bloque "
                                                                  "la poussée des billes ennemies.",
                                                                  __FILE__, __FUNCTION__, __LINE__);
                            }else{
                                moveAndPush(board, nextPosition, nextEnemyPosition, marbles);
                            }
                        }
                    }
                }
            }
        }
    }
}

void Marble::lateralMove(Board & board, const Position & positionToGo){

    Position nextPosition;

    Direction direction = computeDirection(this->_positionOnBoard, positionToGo);
    nextPosition = this->_positionOnBoard.next(direction);

    if(nextPosition != positionToGo){
        throw ImpossibleMovementException("mouvement impossible, "
                                          "la case étant trop éloigné pour effectuer le mouvement.",
                                          __FILE__, __FUNCTION__, __LINE__);
    }else{
        if(!board.isInside(positionToGo)){
            throw ImpossibleMovementException("mouvement impossible, "
                                              "la position de déplacement est en dehors du board.",
                                              __FILE__, __FUNCTION__, __LINE__);
        }else{
            if(!board.isHexagonFree(positionToGo)){
                throw ImpossibleMovementException("mouvement impossible, "
                                                  "bille sur le chemin du mouvement.",
                                                  __FILE__, __FUNCTION__, __LINE__);
            }else{
                moveFree(board, positionToGo);
            }
        }
    }
}

void Marble::moveFree(Board & board, const Position & positionToGo){
    board.updateHexagonState(this->_positionOnBoard);//Je met ton ancienne position a free
    this->_positionOnBoard = positionToGo;
    board.updateHexagonState(this->_positionOnBoard);//Je met ta nouvelle position a not free
}

void Marble::moveAndPush(Board & board,
                         const Position & positionToGo,
                         const Position & nextEnemyPosition,
                         std::array<Marble*, 28> & marbles)
{
    getMarble(marbles, positionToGo)->_positionOnBoard = nextEnemyPosition;//Deplace l'ennemie en face de nos billes tout derrière
    board.updateHexagonState(nextEnemyPosition);//update l'attribut free de la case ou la bille enemie a été poussée
    board.updateHexagonState(this->_positionOnBoard);//update l'attribut free de la case ou se trouvait cette bille avant son déplacement
    this->_positionOnBoard = positionToGo;
}

void Marble::moveAndPushInVoid(Board & board,
                               const Position & positionToGo,
                               std::array<Marble*, 28> & marbles)
{
    getMarble(marbles, positionToGo)->_positionOnBoard = Position(-1, -1);
    board.updateHexagonState(this->_positionOnBoard);//Je met ton ancienne position a free
    this->_positionOnBoard = positionToGo;
}

Marble* getMarble(std::array<Marble*, 28> & marbles, const Position & position){
    for(size_t i = 0; i < marbles.size(); i++){
        if(marbles.at(i)->positionOnBoard() == position){
            return marbles.at(i);
        }
    }
    throw MarbleNotFoundException("Aucune bille ne correspondant "
                                  "trouvé dans le tableau de marble.",
                                  __FILE__, __FUNCTION__, __LINE__);
}

Position Marble::positionOnBoard() const{
    return this->_positionOnBoard;
}

Color Marble::color() const{
    return this->_color;
}

void Marble::positionOnBoard(const Position & position){
    this->_positionOnBoard = position;
}

void Marble::color(const Color & color){
    this->_color = color;
}

std::string Marble::to_string(){
    if(this->_color ==  Color::BLACK){
        return "X";
    }else if(this->_color ==  Color::WHITE){
        return "O";
    }else{
        return  "";
    }
}

}// namespace abalone::model
