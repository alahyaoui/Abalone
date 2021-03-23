#include "Board.h"
#include "Position.h"
#include <stdexcept>

using namespace abalone::model;
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
    return _hexagons.size();
}

int Board::getNbColumn() const{
    return _hexagons[0].size();
}

bool Board::isInside(Position position) const{
    int row = position.x();
    int column = position.y();
    if (row < 0 || row >= getNbRow() || column < 0 || column >= getNbColumn()
            || _hexagons[row][column].type() != HexagonType::VOID) {
        return false;
    }
    return true;
}

bool Board::isHexagonFree(Position position) const{
    int row = position.x();
    int column = position.y();
    return this->_hexagons[row][column].isFree();
}

void Board::updateHexagonState(Position position){
    int row = position.x();
    int column = position.y();
    _hexagons[row][column].isFree(!_hexagons[row][column].isFree());
}

std::string Board::to_string() const{
    string board = "";
    std::array<string, 9> Ycoord = {"I", "H", "G", "F", "E", "D", "C", "B", "A"};
    std::array<string, 9> Xcoord = {"1", "2", "3", "4", "5", "6", "9", "8", "7"};
    string yAxis = "";
    int offset = 4;

    for(int i = 0; i < getNbRow(); i++){
        yAxis = Ycoord[i] + "  ";
        if(i < 4){
            for(int i = 0; i < offset; i++){
                board += " ";
            }
            board += yAxis;
            offset--;
        }else if(i > 4){
            offset++;
            for(int i = 0; i < offset; i++){
                board += " ";
            }
            board += yAxis;
            //offset++;
        }else{
            board += yAxis;
        }

        for(int j = 0; j < getNbColumn(); j++){
            board += this->_hexagons[i][j].to_string();
        }

        if(i >= 6 && i <= 8){
            board += "   " + Xcoord[i];
        }

        board += "\n";
    }
    board += "                   6\n";
    board += "         ";
    for(int i = 0; i < 5; i++){
        board += Xcoord[i] + " ";
    }
    //board += "\n";
    return board;
}
