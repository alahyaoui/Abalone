#include "Marble.h"
#include "Board.h"
#include "Direction.hpp"
#include "abalone.exception/ImpossibleMovementException.hpp"
#include "abalone.exception/MarbleNotFoundException.hpp"

//using namespace abalone::model;
//using namespace std;

namespace abalone::model{

Marble::Marble(Position positionOnBoard, Color color)://THIS N EST PAS UNE REFERENCE ???????!!!!!!!
    _positionOnBoard {positionOnBoard},
    _color {color}
{}

Marble::Marble():Marble(Position(0,0), Color::NONE){}//Peut etre necessaire pour l'initialisation d'une liste de marble


void Marble::move(Board & board, Position positionToGo, std::array<Marble*, 28> & marbles){
    Position nextPosition;
    Position nextEnemyPosition;

    Direction direction = computeDirection(this->_positionOnBoard, positionToGo);
    nextPosition = this->_positionOnBoard.next(direction);
    nextEnemyPosition = this->_positionOnBoard.next(direction);

    int countSameColor = 1;
    int countOtherColor = 0;

    if(nextPosition == positionToGo){
        if(board.isInside(positionToGo)){
            if(!board.isHexagonFree(nextPosition)){
                while(!board.isHexagonFree(nextPosition) && getMarble(marbles, nextPosition)->_color == this->_color){
                    countSameColor++;
                    nextPosition = nextPosition.next(direction);
                }
                if(countSameColor <= 3){
                    if(board.isHexagonFree(nextPosition)){
                        moveFree(board, nextPosition);//CHECKER SI FONCTIONNE COMME SOUHAITER
                    }else{
                        nextEnemyPosition = nextPosition;//Faire attention peut ne pas fonctionner comme souhaité
                        while(!board.isHexagonFree(nextEnemyPosition) && getMarble(marbles, nextEnemyPosition)->_color != this->_color){//avance le nextPositioEnemy tant qu'il y a un ennemi
                            countOtherColor++;
                            nextEnemyPosition = nextEnemyPosition.next(direction);
                        }
                        if(countOtherColor < countSameColor){
                            if(board.isInside(nextEnemyPosition)){
                                if(board.isHexagonFree(nextEnemyPosition)){
                                    moveAndPush(board, nextPosition, nextEnemyPosition, marbles);
                                }else{
                                    throw abalone::exception::ImpossibleMovementException("mouvement impossible, bille allié qui bloque la poussée des billes ennemies.", __FILE__, __FUNCTION__, __LINE__);
                                }
                            }else{
                                moveAndPushInVoid(board, nextPosition, marbles);
                            }
                        }else{
                            throw abalone::exception::ImpossibleMovementException("mouvement impossible, pas assez de billes alliés pour pousser les billes ennemies.", __FILE__, __FUNCTION__, __LINE__);
                        }
                    }
                }else{
                    throw abalone::exception::ImpossibleMovementException("mouvement impossible, trop de billes alliés sur le chemin OU position inaccessible (position trop loin pour faire le déplacement).", __FILE__, __FUNCTION__, __LINE__);
                }
            }else{
                moveFree(board, positionToGo);
            }
        }else{
            throw abalone::exception::ImpossibleMovementException("mouvement impossible, la position de déplacement est en dehors du board.", __FILE__, __FUNCTION__, __LINE__);
        }
    }else{
        throw abalone::exception::ImpossibleMovementException("mouvement impossible, la case étant trop éloigné pour effectuer le mouvement.", __FILE__, __FUNCTION__, __LINE__);
    }
}

void Marble::lateralMove(Board & board, Position positionToGo){

    Position nextPosition;
    Position nextEnemyPosition;

    Direction direction = computeDirection(this->_positionOnBoard, positionToGo);
    nextPosition = this->_positionOnBoard.next(direction);
    nextEnemyPosition = this->_positionOnBoard.next(direction);

    if(nextPosition == positionToGo){
        if(board.isInside(positionToGo)){
            if(board.isHexagonFree(positionToGo)){
                moveFree(board, positionToGo);
            }else{
                throw abalone::exception::ImpossibleMovementException("mouvement impossible, bille sur le chemin du mouvement.", __FILE__, __FUNCTION__, __LINE__);
            }
        }else{
            throw abalone::exception::ImpossibleMovementException("mouvement impossible, la position de déplacement est en dehors du board.", __FILE__, __FUNCTION__, __LINE__);
        }
    }else{
        throw abalone::exception::ImpossibleMovementException("mouvement impossible, la case étant trop éloigné pour effectuer le mouvement.", __FILE__, __FUNCTION__, __LINE__);
    }
}

void Marble::moveFree(Board & board, Position positionToGo){
    board.updateHexagonState(this->_positionOnBoard);//Je met ton ancienne position a free
    this->_positionOnBoard = positionToGo;
    board.updateHexagonState(this->_positionOnBoard);//Je met ta nouvelle position a not free
}

void Marble::moveAndPush(Board & board, Position positionToGo, Position nextEnemyPosition, std::array<Marble*, 28> & marbles){
    getMarble(marbles, positionToGo)->_positionOnBoard = nextEnemyPosition;//Deplace l'ennemie en face de nos billes tout derrière
    board.updateHexagonState(nextEnemyPosition);//update l'attribut free de la case ou la bille enemie a été poussée
    board.updateHexagonState(this->_positionOnBoard);//update l'attribut free de la case ou se trouvait cette bille avant son déplacement
    this->_positionOnBoard = positionToGo;
}

void Marble::moveAndPushInVoid(Board & board, Position positionToGo, std::array<Marble*, 28> & marbles){
    getMarble(marbles, positionToGo)->_positionOnBoard = Position(-1, -1);//J'aurais pu faire un move dans le vide a verifier
    board.updateHexagonState(this->_positionOnBoard);//Je met ton ancienne position a free
    this->_positionOnBoard = positionToGo;
}


/*
void Marble::incCountMarble(Board board, Position & nextPosition, Direction direction , int & countNbMarble){
    while(!board.isHexagonFree(nextPosition) && getMarble(marbles, nextPosition)._color == this->_color){
            countNbMarble++;
            nextPosition = nextPosition.next(direction);
    }
}
*/

Marble* getMarble(std::array<Marble*, 28> & marbles, Position position){
    for(size_t i = 0; i < marbles.size(); i++){
        if(marbles.at(i)->positionOnBoard() == position){
            return marbles.at(i);
        }
    }
    throw abalone::exception::MarbleNotFoundException("Aucune bille ne correspondant trouvé dans le tableau de marble.", __FILE__, __FUNCTION__, __LINE__);//NE PAS UTILISER !!!!!!!!!! JE NE VEUX PAS ENVOYER UNE ERREUR SI IL N Y A PAS DE BILLE
    //return Marble(Position(0, 0), Color::NONE);//Sensé ne jamais arrivé étant donné que j'ai verifier si la case etait occupé avant d'appeler cette fonction
}

Position Marble::positionOnBoard() const{
    return this->_positionOnBoard;
}

Color Marble::color() const{
    return this->_color;
}

void Marble::positionOnBoard(Position position){
    this->_positionOnBoard = position;
}

void Marble::color(Color color){
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
