#ifndef MARBLE_H
#define MARBLE_H

#include "Position.h"
namespace abalone::abalonecore{

class Board;
//class Position;
enum class Color;

class Marble {
private:
    Position _positionOnBoard;
    Color _color;
public:
    inline Marble(Position positionOnBoard, Color color);

    inline void move(Board board, Position positionToGo, Marble marbles...);

    inline Position positionOnBoard() const;
    inline Color color() const;

    inline void positionOnBoard(Position position);
};

}// namespace abalone::abalonecore
#endif // MARBLE_H
