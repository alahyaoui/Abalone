#include "board.h"
#include "Position.h"
#include "Hexagon.h"
#include <stdexcept>

using namespace abalone::abalonecore;
using namespace std;

Board::Board():
    Board(std::array<std::array<Hexagon, 9>, 9> {{
{ Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false) },
{ Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST, false),Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false) },
{ Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
{ Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
{ Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
{ Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID)},
{ Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
{ Hexagon(HexagonType::EXIST, false),Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID) },
{ Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
          }})

{}

Board::Board(std::array<std::array<Hexagon, 9>, 9> hexagons):
    _hexagons {hexagons}
{}

std::array<std::array<Hexagon, 9>, 9> Board::hexagons() const{
    return _hexagons;
}

int Board::getNbRow() const{
    return _hexagons.length;
}

int Board::getNbColumn() const{
    return _hexagons[0].length;
}

bool Board::isInside(Position position) const{
    int row = position.x();
    int column = position.y();
    if (row < 0 || row >= getNbRow() || column < 0 || column >= getNbColumn()
            || _hexagons[row][column].type() != HexagonType::VOID || _hexagons[row][column] == nullptr) {
        return false;
    }
    return true;
}

void Board::updateHexagonState(Position position){
    int row = position.x();
    int column = position.y();
    _hexagons[row][column].isFree(!_hexagons[row][column].isFree());
}

std::string Board::to_string() const{
    string board = "";
    std::array<char, 9> Ycoord = {'I','H','G','F','E','D','C','B','A'};
    std::array<char, 9> Xcoord = {'1','2','3','4','5','6','9','8','7'};
    int offset = 1;

    for(int i = 0; i < getNbRow(); i++){
        board += Ycoord[i] + " ";
        if(i > 4){
            for(int i = 0; i < offset; i++){
                board += " ";
            }
            offset++;
        }
        for(int j = 0; j < getNbColumn(); j++){
            board += this->_hexagons[i][j].to_string();
        }
        if(i >= 6 || i <= 8){
            board += "   " + Xcoord[i];
        }
        board += "\n";
    }
    board += "        ";
    for(int i = 0; i <= 6; i++){
        board += Xcoord[i] + " ";
    }
    return board;
}
