#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include <array>
#include "Hexagon.h"

namespace abalone::model{

class Position;
//class Hexagon;

class Board{

private:
    std::array<std::array<Hexagon, 9>, 9>  _hexagons;

public:
    Board();
    Board(std::array<std::array<Hexagon, 9>, 9> hexagons);

    std::array<std::array<Hexagon, 9>, 9> hexagons() const;
    int getNbRow() const;
    int getNbColumn() const;

    bool isInside(Position position) const;
    bool isHexagonFree(Position position) const;
    void updateHexagonState(Position position);

    std::string to_string() const;
};

}// namespace abalone::abalonecore

#endif // BOARD_H


/*void Board::initBoard(){
    this->_hexagons = std::array<std::array<Hexagon, 9>, 9>{{
            { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false) },
            { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST, false),Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false) },
            { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
            { Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
            { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
            { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID)},
            { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
            { Hexagon(HexagonType::EXIST, false),Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID) },
            { Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                                                            }} ;
}*/

/*void Board::initBoard(){
    Hexagon hExistFree = Hexagon(HexagonType::EXIST);
    Hexagon hExistNotFree = Hexagon(HexagonType::EXIST, false);
    Hexagon hVoid = Hexagon(HexagonType::VOID);

    this->_hexagons = std::array<std::array<Hexagon, 9>, 9>{{
    { hVoid, hVoid, hVoid, hVoid,hExistNotFree, hExistNotFree, hExistNotFree, hExistNotFree, hExistNotFree },
    { hVoid, hVoid, hVoid, hExistNotFree, hExistNotFree, hExistNotFree, hExistNotFree, hExistNotFree, hExistNotFree },
    { hVoid, hVoid, hExistFree, hExistFree, hExistNotFree, hExistNotFree, hExistNotFree, hExistFree, hExistFree },
    { hVoid, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree },
    { hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree },
    { hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hExistFree, hVoid },
    { hExistFree, hExistFree, hExistNotFree, hExistNotFree, hExistNotFree, hExistFree, hExistFree, hVoid, hVoid },
    { hExistNotFree, hExistNotFree, hExistNotFree, hExistNotFree, hExistNotFree, hExistNotFree, hVoid, hVoid, hVoid },
    { hExistNotFree, hExistNotFree, hExistNotFree, hExistNotFree, hExistNotFree, hVoid, hVoid, hVoid, hVoid },
    }} ;
}*/
