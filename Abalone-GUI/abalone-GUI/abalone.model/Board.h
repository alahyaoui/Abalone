#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include <array>
#include "Hexagon.h"

namespace abalone::model{

class Position;
//class Hexagon;

/**
 * @brief The Board class, is the board of the game.
 * Board is made of hexagons,
 * the hexagons attribute of the board is an array of hexagons.
 */
class Board{

private:
    std::array<std::array<Hexagon, 9>, 9>  _hexagons;

public:

    /**
     * @brief Board an empty constructor of Board.
     */
    Board();

    /**
     * @brief Board a simple constructor of Board.
     * @param hexagons an array of Hexagons
     */
    Board(std::array<std::array<Hexagon, 9>, 9> hexagons);

    /**
     * @brief hexagons a simple getter of _hexagons.
     * @return _hexagons an array of Hexagons.
     */
    std::array<std::array<Hexagon, 9>, 9> hexagons() const;

    /**
     * @brief getNbRow method, gets the number of row of _hexagons.
     * @return the number of row of _hexagons an integer.
     */
    int getNbRow() const;

    /**
     * @brief getNbColumn method, gets the number of column of _hexagons.
     * @return the number of column of _hexagons an integer.
     */
    int getNbColumn() const;

    /**
     * @brief isInside method, indicates whether a given position is on the game board or not.
     * @param position a Position.
     * @return a boolean.
     */
    bool isInside(Position position) const;

    /**
     * @brief isHexagonFree method, gets the _isFree attribute of hexagon at the given position.
     * @param position a Position.
     * @return a boolean.
     */
    bool isHexagonFree(Position position) const;

    /**
     * @brief updateHexagonState method, changes the _isFree attribute of the hexagon
     * in the given postion in parameter.
     *
     * @param position a Position.
     */
    void updateHexagonState(Position position);

    /**
     * @brief to_string method, converts the Board into a string.
     * @return a string materialization of the Board.
     */
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
