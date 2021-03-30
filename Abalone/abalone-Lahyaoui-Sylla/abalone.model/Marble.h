#ifndef MARBLE_H
#define MARBLE_H

#include <array>
#include "Position.h"
#include "Color.hpp"

namespace abalone::model{

class Board;
//enum class Direction;
//enum class Color;

/**
 * @brief The Marble class, represents a marble on the board,
 * it has a position on the board and a color.
 */
class Marble {
private:
    Position _positionOnBoard;
    Color _color;
public:

    /**
     * @brief Marble a simple constructor of Marble class.
     * @param positionOnBoard a Position.
     * @param color a Color.
     */
    Marble(Position positionOnBoard, Color color);
    Marble();

    //virtual ~Marble() = default;

    //void incCountMarble(Board board, Position & nextPosition, Direction direction , int & countNbMarble);

    /**
     * @brief move method, moves the marble if it's possible.
     * @param board a Board.
     * @param positionToGo a Position.
     * @param marbles an array of Marbles.
     */
    void move(Board & board, Position positionToGo, std::array<Marble*, 28> & marbles);//Rajouter mouvement latéral

    /**
     * @brief moveFree method, changes the isFree attribute of the hexagons
     * where the marble was located and where the marble will move
     * and finally moves the marble.
     *
     * @param board a Board.
     * @param positionToGo a Position.
     */
    void moveFree(Board & board, Position positionToGo);

    /**
     * @brief moveAndPush method, changes the isFree attribute of the hexagons
     * where the marbles were located and where the marbles will move
     * and finally moves the marble and push the opposing one.
     *
     * @param board a Board
     * @param positionToGo the position where the marble will move.
     * @param nextPosition the position of the next opposing marble.
     * @param nextEnemyPosition the position where the next oppos marble will be pushed.
     * @param marbles an array of marbles.
     */
    void moveAndPush(Board & board, Position positionToGo, Position nextPosition, Position nextEnemyPosition, std::array<Marble*, 28> & marbles);

    /**
     * @brief moveAndPushInVoid method, changes the isFree attribute of the hexagons
     * where the marbles were located and where the marbles will move
     * and finally moves the marble and push the opposing one in the void.
     *
     * @param board a Board
     * @param positionToGo the position where the marble will move.
     * @param nextPosition the position of the next opposing marble.
     * @param nextEnemyPosition the position where the next oppos marble will be pushed.
     * @param marbles an array of marbles.
     */
    void moveAndPushInVoid(Board & board, Position positionToGo, Position nextPosition, std::array<Marble*, 28> & marbles);

    /**
     * @brief positionOnBoard method a simple getter of _positionOnBoard.
     * @return _positionOnBoard a Position.
     */
    Position positionOnBoard() const;

    /**
     * @brief color method a simple getter of _color.
     * @return _color a Color.
     */
    Color color() const;

    /**
     * @brief color method a simple setter of _color.
     * @param color a Color.
     */
    void color(Color color);

    /**
     * @brief positionOnBoard method a simple setter of _positionOnBoard.
     * @param position a Position.
     */
    void positionOnBoard(Position position);
};


/**
 * @brief getMarble function, gets the marble from the array marble at the position given in parameter.
 * Don't use this function outside of this class, because throws an exception if the marble is not found.
 *
 * @param marbles an array of Marble.
 * @param position a Position.
 * @return the marble located at the given position.
 */
Marble* getMarble(std::array<Marble*, 28> & marbles, Position position);

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
