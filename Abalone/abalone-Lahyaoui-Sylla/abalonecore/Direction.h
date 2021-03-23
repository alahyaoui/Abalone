#ifndef DIRECTION_H
#define DIRECTION_H

#include <array>

#include "Position.h"
namespace abalone::abalonecore{

enum class Direction{

    LEFT,

    RIGHT,

    UP_LEFT,

    UP_RIGHT,

    DOWN_LEFT,

    DOWN_RIGHT,

};

Position toPosition(Direction direction){
    switch (direction){
    case Direction::LEFT:
        //return {0, -1};
        return Position(0, -1);
    case Direction::RIGHT:
        //return {0, 1};
        return Position(0, 1);
    case Direction::UP_LEFT:
        //return {-1, -1};
        return Position(-1, -1);
    case Direction::UP_RIGHT:
        //return {-1, 1};
        return Position(-1, 1);
    case Direction::DOWN_LEFT:
        //return {1, -1};
        return Position(1, -1);
    case Direction::DOWN_RIGHT:
        //return {1, 1};
        return Position(1, 1);
    }
}

}// namespace abalone::abalonecore
#endif // DIRECTION_H

//Old version of toPosition
/*
   std::array<int,2> toPosition(Direction direction){
    switch (direction){
    case Direction::LEFT:
       return {0, -1};
    case Direction::RIGHT:
        return {0, 1};
    case Direction::UP_LEFT:
        return {-1, -1};
    case Direction::UP_RIGHT:
        return {-1, 1};
    case Direction::DOWN_LEFT:
        return {1, -1};
    case Direction::DOWN_RIGHT:
        return {1, 1};
    }
}
*/
