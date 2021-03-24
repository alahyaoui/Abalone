#ifndef DIRECTION_H
#define DIRECTION_H

#include <array>
#include "Position.h"

namespace abalone::model{

enum class Direction{

    LEFT,

    RIGHT,

    UP,//Rajouter

    DOWN,//Rajouter

    UP_LEFT,

    UP_RIGHT,

    DOWN_LEFT,

    DOWN_RIGHT,

};

inline Position toPosition(Direction direction){
    switch (direction){
    case Direction::LEFT:
        return Position(0, -1);
    case Direction::RIGHT:
        return Position(0, 1);
    case Direction::UP:
        return Position(-1, 0);
    case Direction::DOWN:
        return Position(1, 0);
    case Direction::UP_LEFT:
        return Position(-1, -1);
    case Direction::UP_RIGHT:
        return Position(-1, 1);
    case Direction::DOWN_LEFT:
        return Position(1, -1);
    case Direction::DOWN_RIGHT:
        return Position(1, 1);
    }
    return Position(0, 0);
}

inline Direction toDirection(Position position){
    Direction direction;
    if(position.x() == 0 && position.y() == -1){
        direction = Direction::LEFT;
    }else if(position.x() == 0 && position.y() == 1){
        direction = Direction::RIGHT;
    }else if(position.x() == -1 && position.y() == 0){
        direction = Direction::UP;
    }else if(position.x() == 1 && position.y() == 0){
        direction = Direction::DOWN;
    }else if(position.x() == -1 && position.y() == -1){
        direction = Direction::UP_LEFT;
    }else if(position.x() == -1 && position.y() == 1){
        direction = Direction::UP_RIGHT;
    }else if(position.x() == 1 && position.y() == -1){
        direction = Direction::DOWN_LEFT;
    }else /*if(position.x() == 1 && position.y() == 1)*/{
        direction = Direction::DOWN_RIGHT;
    }
    return direction;
}

inline Direction computeDirection(Position currentPosition, Position positionToGo){
    int row = 0;
    int col = 0;
    if(positionToGo.x() - currentPosition.x() > 0){
        row = 1;
    }else if(positionToGo.x() - currentPosition.x() < 0){
        row = -1;
    }else if(positionToGo.x() - currentPosition.x() == 0){
        row = 0;
    }

    if(positionToGo.y() - currentPosition.y() > 0){
        col = 1;
    }else if(positionToGo.y() - currentPosition.y() < 0){
        col = -1;
    }else if(positionToGo.y() - currentPosition.y() == 0){
        col = 0;
    }
    return toDirection(Position(row, col));
}

}// namespace abalone::abalonecore
#endif // DIRECTION_H
