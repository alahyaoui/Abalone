#ifndef DIRECTION_H
#define DIRECTION_H

#include <array>

namespace abalone::abalonecore{

enum class Direction {

    LEFT = (0, -1),

    RIGHT,// = (0, 1),

    UP_LEFT,// = (-1, -1),

    UP_RIGHT,// = (-1, 1),

    DOWN_LEFT,// = (1, -1),

    DOWN_RIGHT,// = (1, 1)


};

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


}// namespace abalone::abalonecore
#endif // DIRECTION_H
