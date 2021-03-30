#ifndef POSITION_H
#define POSITION_H

#include <iostream>

namespace abalone::model{

enum class Direction;

//Le nombre de coordonnées est passé de 2 à 3.

/**
 * @brief The Position class, represents a position on the board.
 * A position has two attributes x, y.
 */
class Position{
private:
    int _x;
    int _y;

public:
    /**
     * @brief Position a simple constructor of Position.
     * @param x an integer.
     * @param y an integer.
     */
    Position(int x, int y);

    /**
     * @brief Position the empty constructor of Position.
     */
    Position();

    /**
     * @brief next method, returns the next position
     * in the direction given in parameter.
     *
     * @param direction a Direction.
     * @return a Position.
     */
    Position next(Direction direction);

    /**
     * @brief x method a simple getter of _x.
     * @return _x an integer.
     */
    int x() const;

    /**
     * @brief y method a simple getter of _y.
     * @return _y an integer.
     */
    int y() const;

    /**
     * @brief equals method, checks the equality between two Position.
     * @param otherPosition a Position.
     * @return a boolean.
     */
    bool equals(Position otherPosition) const;

    /**
     * @brief operator == checks the equality between two Position.
     * @param otherPosition a Position.
     * @return a boolean.
     */
    bool operator==(Position otherPosition) const;

    /**
     * @brief to_string method, converts a Position into a string.
     * @return the string materialization of a Position.
     */
    std::string to_string() const;
};

}// namespace abalone::abalonecore
#endif // POSITION_H
