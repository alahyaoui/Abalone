#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include <array>

namespace abalone::abalonecore{

class Position;
class Hexagon;

class Board{

private:
    std::array<std::array<Hexagon, 9>, 9>  _hexagons;

public:
    inline Board(std::array<std::array<Hexagon, 9>, 9> hexagons);
    inline Board();

    inline std::array<std::array<Hexagon, 9>, 9> hexagons() const;

    inline bool isInside(Position position) const;
    inline void updateHexagonState(Position position);

    inline std::string to_string() const;
};
}// namespace abalone::abalonecore

#endif // BOARD_H
