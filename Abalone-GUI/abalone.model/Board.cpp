#include "Board.h"
#include "Position.h"
#include <stdexcept>

//using namespace abalone::model;
//using namespace std;

namespace abalone::model{

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
    return 9;//_hexagons.size();
}

int Board::getNbColumn() const{
    return 9;//_hexagons[0].size();
}

bool Board::isInside(const Position & position) const{
    int row = position.x();
    int column = position.y();
    if (row < 0 || row >= getNbRow() || column < 0 || column >= getNbColumn()
            || _hexagons[row][column].type() == HexagonType::VOID) {
        return false;
    }
    return true;
}

bool Board::isHexagonFree(const Position & position) const{
    int row = position.x();
    int column = position.y();
    if(this->isInside(position))
        return this->_hexagons[row][column].isFree();
    return true;
}

void Board::updateHexagonState(const Position & position){
    int row = position.x();
    int column = position.y();
    _hexagons[row][column].isFree(!_hexagons[row][column].isFree());
}

std::string Board::to_string() const{
    std::string board = "";
    std::array<std::string, 9> Ycoord = {"I", "H", "G", "F", "E", "D", "C", "B", "A"};
    std::array<std::string, 9> Xcoord = {"1", "2", "3", "4", "5", "6", "9", "8", "7"};
    std::string yAxis = "";
    int offset = 4;

    board += "        ___________ \n";
    for(int i = 0; i < getNbRow(); i++){
        yAxis = Ycoord[i] + "  ";
        if(i < 4){
            for(int i = 0; i < offset; i++){
                board += " ";
            }
            board += yAxis + "/ ";
            offset--;
        }else if(i > 4){
            offset++;
            for(int i = 0; i < offset; i++){
                board += " ";
            }
            board += yAxis + "\\ ";
            //offset++;
        }else{
            board += yAxis + "{ ";
        }

        for(int j = 0; j < getNbColumn(); j++){
            board += this->_hexagons[i][j].to_string();

            if(j == getNbColumn() - 1){
                if(i < 4){
                    board += "\\";
                }else if(i > 4){
                    board += "/";
                }else{
                    board += "}";
                }
            }
        }

        if(i >= 6 && i <= 8){
            board += " " + Xcoord[i];
        }

        board += "\n";
    }
    //board += "        \\---------/";
    board += "                    6\n";
    board += "           ";
    for(int i = 0; i < 5; i++){
        board += Xcoord[i] + " ";
    }
    return board;
}

}
