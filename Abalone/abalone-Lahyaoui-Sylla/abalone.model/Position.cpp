#include "Position.h"
#include "Direction.hpp"

//using namespace abalone::model;

namespace abalone::model{

Position::Position(int x, int y):
    _x {x},
    _y {y}
{}

Position::Position():Position(0, 0)
{}

Position Position::next(Direction direction){
    Position dir = toPosition(direction);
    return Position(this->_x + dir._x, this->_y + dir._y);
}

int Position::x() const{
    return _x;
}

int Position::y() const{
    return _y;
}

bool Position::equals(Position otherPosition) const{
    return this->_x == otherPosition._x && this->_y == otherPosition._y;
}

bool Position::operator==(Position otherPosition) const{
    return this->equals(otherPosition);
}

std::string Position::to_string() const{
    return "(" + std::to_string(_x) + "," + std::to_string(_y) + ")";
}

}// namespace abalone::model
