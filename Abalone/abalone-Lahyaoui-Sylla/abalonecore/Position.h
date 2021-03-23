#ifndef POSITION_H
#define POSITION_H

#include "Direction.h"

namespace abalone::abalonecore{

enum class Direction;

class Position{
private:
    int _x;
    int _y;

public:
    inline Position(int x, int y);

    inline Position next(Direction direction);

    inline int x();
    inline int y();

    inline bool equals(Position otherPosition) const;
    inline bool operator==(Position otherPosition) const;
};

//Définition des méthodes inline.
Position::Position(int x, int y):
    _x {x},
    _y {y}
{}

Position Position::next(Direction direction){
    Position dir = toPosition(direction);
    return Position(this->_x + dir._x, this->_y + dir._y);
}

int Position::x(){
    return _x;
}

int Position::y(){
    return _x;
}

bool Position::equals(Position otherPosition) const{
    return this->_x == otherPosition._x && this->_y == otherPosition._y;
}

bool Position::operator==(Position otherPosition) const{
    return this->equals(otherPosition);
}

}// namespace abalone::abalonecore
#endif // POSITION_H
