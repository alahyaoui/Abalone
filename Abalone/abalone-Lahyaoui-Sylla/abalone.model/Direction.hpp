#ifndef DIRECTION_H
#define DIRECTION_H

#include <array>
#include "Position.h"
#include "abalone.exception/DirectionNotFoundException.hpp"
#include "abalone.exception/InvalidDirectionException.hpp"

namespace abalone::model{

/**
 * @brief The Direction enum, represents the direction the marble can take,
 * directions are Left, Right, Up (left), Up down, Down left and Down (Right).
 */
enum class Direction{

    LEFT,

    RIGHT,

    UP,//Correspond logiquement a UP_LEFT mais physiquement a UP

    DOWN,//Correspond logiquement a DOWN_RIGHT mais physiquement a DOWN

    //UP_LEFT,

    UP_RIGHT,

    DOWN_LEFT,

    //DOWN_RIGHT

};

/**
 * @brief toPosition function, converts a direction to a Position.
 * @param direction a Direction.
 * @return a Position.
 */
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
        //case Direction::UP_LEFT:
        //    return Position(-1, -1);
    case Direction::UP_RIGHT:
        return Position(-1, 1);
    case Direction::DOWN_LEFT:
        return Position(1, -1);
        //case Direction::DOWN_RIGHT:
        //    return Position(1, 1);
    default:
        throw abalone::exception::InvalidDirectionException("La direction entrée en paramètre est invalide !",
                                                            __FILE__, __FUNCTION__, __LINE__);
    }
    return Position(0, 0);
}

/**
 * @brief toDirection function, converts a position into a direction.
 * @param position a Position.
 * @return a Direction.
 */
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
        //}else if(position.x() == -1 && position.y() == -1){
        //    direction = Direction::UP_LEFT;
    }else if(position.x() == -1 && position.y() == 1){
        direction = Direction::UP_RIGHT;
    }else if(position.x() == 1 && position.y() == -1){
        direction = Direction::DOWN_LEFT;
        //}else if(position.x() == 1 && position.y() == 1){
        //    direction = Direction::DOWN_RIGHT;
    }else{
        //std::cout << "La position : " << position.to_string() << std::endl;
        throw abalone::exception::DirectionNotFoundException("La conversion de position à direction est impossible, "
                                                             "vous avez essayé de faire un mouvement non autorisé !",
                                                             __FILE__, __FUNCTION__, __LINE__);
    }
    return direction;
}

/**
 * @brief computeDirection function, computes the direction
 * given by the substaction of two position.
 *
 * @param currentPosition a Position.
 * @param positionToGo a Position.
 * @return a Direction
 */
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

/**
 * @brief to_string function, converts the direction given  in parameter into a string.
 * @param direction a Direction.
 * @return the string materialization of the direction.
 */
inline std::string to_string(Direction direction){
    std::string strDirection = "";
    switch (direction){
    case Direction::LEFT:
        strDirection = "LEFT";
        break;
    case Direction::RIGHT:
        strDirection = "RIGHT";
        break;
    case Direction::UP:
        strDirection = "UP";
        break;
    case Direction::DOWN:
        strDirection = "DOWN";
        break;
        //case Direction::UP_LEFT:
        //    strDirection = "UP_LEFT";
        //    break;
    case Direction::UP_RIGHT:
        strDirection = "UP_RIGHT";
        break;
    case Direction::DOWN_LEFT:
        strDirection = "DOWN_LEFT";
        break;
        //case Direction::DOWN_RIGHT:
        //    strDirection = "DOWN_RIGHT";
        //    break;
    default:
        throw abalone::exception::DirectionNotFoundException("L'affichage d'une direction "
                                                             "non existante est impossible !",
                                                             __FILE__, __FUNCTION__, __LINE__);
    }
    return strDirection;
}

}// namespace abalone::abalonecore
#endif // DIRECTION_H
