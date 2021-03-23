#ifndef POSITION_H
#define POSITION_H

namespace abalone::model{

enum class Direction;

class Position{
private:
    int _x;
    int _y;

public:
    Position(int x, int y);

    Position next(Direction direction);

    int x() const;
    int y() const;

    bool equals(Position otherPosition) const;
    bool operator==(Position otherPosition) const;
};

}// namespace abalone::abalonecore
#endif // POSITION_H
