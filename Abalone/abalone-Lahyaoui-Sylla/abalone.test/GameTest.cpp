#include "GameTest.h"

#include "abalone.model/Game.h"
#include "abalone.model/Color.hpp"
#include "abalone.model/Position.h"

using namespace abalone::model;

namespace abalone::test {

void GameTest::moveTest(){
    std::cout << "Test de la methode moveTest" << std::endl;

    Game game = Game();
    game.startGame();

    Position expMarblePosition = Position(3, 5);

    game.move(Position(0, 5), Position(1, 5));

    Position resMarblePosition;

    bool res = false;

    for(auto marble : game.marbles()){
        resMarblePosition = marble->positionOnBoard();

        if(resMarblePosition == expMarblePosition){
            res = true;
        }
    }

    assertTrue(res, __FUNCTION__);
}

void GameTest::moveLateral2MarbleTest(){
    std::cout << "Test de la methode moveLateral2MarbleTest" << std::endl;

    Game game = Game();
    game.startGame();

    Position expMarble1Position = Position(3, 4);
    Position expMarble2Position = Position(3, 5);

    game.move(Position(2, 4), Position(2, 5), Position(3, 4));

    Position resMarble1Position;
    Position resMarble2Position;

    bool res = false;

    for(auto marble : game.marbles()){
        if(marble->positionOnBoard() == expMarble1Position){
            resMarble1Position = marble->positionOnBoard();
        }else if(marble->positionOnBoard() == expMarble2Position){
            resMarble2Position = marble->positionOnBoard();
        }
    }

    res = (resMarble1Position == expMarble1Position) && resMarble2Position == expMarble2Position;

    assertTrue(res, __FUNCTION__);
}

void GameTest::moveLateral3MarbleTest(){
    std::cout << "Test de la methode moveLateral3MarbleTest" << std::endl;

    Game game = Game();
    game.startGame();

    Position expMarble1Position = Position(3, 4);
    Position expMarble2Position = Position(3, 5);
    Position expMarble3Position = Position(3, 6);

    game.move(Position(2, 4), Position(2, 6), Position(3, 4));

    Position resMarble1Position;
    Position resMarble2Position;
    Position resMarble3Position;

    bool res = false;

    for(auto marble : game.marbles()){

        if(marble->positionOnBoard() == expMarble1Position){
            resMarble1Position = marble->positionOnBoard();
        }else if(marble->positionOnBoard() == expMarble2Position){
            resMarble2Position = marble->positionOnBoard();
        }else if(marble->positionOnBoard() == expMarble3Position)
            resMarble3Position = marble->positionOnBoard();
    }

    res = (resMarble1Position == expMarble1Position) &&
            (resMarble2Position == expMarble2Position) &&
            (resMarble3Position == expMarble3Position);

    assertTrue(res, __FUNCTION__);
}

}

/*
using namespace abalone::test;
int main(){

    GameTest::moveTest();

    GameTest::moveLateral2MarbleTest();

    GameTest::moveLateral3MarbleTest();
}
*/
