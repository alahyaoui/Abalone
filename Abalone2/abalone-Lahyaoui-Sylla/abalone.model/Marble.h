#ifndef MARBLE_H
#define MARBLE_H

#include <array>
#include "Position.h"
#include "Color.h"

namespace abalone::model{

class Board;
//enum class Color;

class Marble {
private:
    Position _positionOnBoard;
    Color _color;
public:
    Marble(Position positionOnBoard, Color color);
    Marble();

    //virtual ~Marble() = default;

    void move(Board board, Position positionToGo, std::array<Marble, 28> marbles);//Rajouter mouvement latéral
    void moveFree(Board board, Position positionToGo);
    void moveAndPush(Board board, Position positionToGo, Position nextPosition,Position nextEnemyPosition, std::array<Marble, 28> marbles);
    void moveAndPushInVoid(Board board, Position positionToGo, Position nextPosition, std::array<Marble, 28> marbles);

    Position positionOnBoard() const;
    Color color() const;

    void color(Color color);
    void positionOnBoard(Position position);
};

Marble getMarble(std::array<Marble, 28> marbles, Position position);

/*
inline Marble getMarble(std::array<Marble, 28> marbles, Position position){
    for(size_t i = 0; i < marbles.size(); i++){
        if(marbles.at(i).positionOnBoard() == position)
            return marbles.at(i);
    }
    return Marble(Position(0, 0), Color::NONE);
}*/

}// namespace abalone::abalonecore
#endif // MARBLE_H
