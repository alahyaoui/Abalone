#include <iostream>
#include "../abalone-Lahyaoui-Sylla/abalone.model/Board.h"
//#include "../abalonecore/board.h"

using namespace std;
using namespace abalone::abalonecore;

int main(){
    Board board = Board();
    cout << board.to_string()<< endl;
}

