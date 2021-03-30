#include "BoardTest.h"

#include "abalone.model/Board.h"
#include "abalone.model/Position.h"

using namespace abalone::model;

namespace abalone::test {

void BoardTest::isInsideTrueTest(){
    std::cout << "Test de la methode isInside ou la reponse attendue est true" << std::endl;

    Board board;
    Position pos = Position(0,4);
    bool exp = true;

    bool res = board.isInside(pos);

    assertTrue(exp == res, __FUNCTION__);
}

void BoardTest::isInsideFalseTest(){
    std::cout << "Test de la methode isInside ou la reponse attendue est false" << std::endl;

    Board board;
    Position pos = Position(0,1);
    bool exp = false;

    bool res = board.isInside(pos);

    assertTrue(exp == res, __FUNCTION__);
}

void BoardTest::isHexagonFreeTrueTest(){
    std::cout << "Test de la methode isHexagonFree ou la reponse attendue est true" << std::endl;

    Board board;
    Position pos = Position(3,2);
    bool exp = true;

    bool res = board.isHexagonFree(pos);

    assertTrue(exp == res, __FUNCTION__);
}

void BoardTest::isHexagonFreeFalseTest(){
    std::cout << "Test de la methode isHexagonFree ou la reponse attendue est true" << std::endl;

    Board board;
    Position pos = Position(0,5);
    bool exp = false;

    bool res = board.isHexagonFree(pos);

    assertTrue(exp == res, __FUNCTION__);
}

void BoardTest::updateHexagonStateTest(){
    std::cout << "Test de la methode updateHexagonState" << std::endl;

    Board board;
    Position pos = Position(0,4);
    bool expHexagonState = board.isHexagonFree(pos);

    board.updateHexagonState(pos);
    bool resHexagonState = board.isHexagonFree(pos);

    assertTrue(expHexagonState != resHexagonState, __FUNCTION__);
}

}// namespace abalone::test

/*
using namespace abalone::test;
int main(){
    BoardTest::isInsideTrueTest();
    BoardTest::isInsideFalseTest();
    BoardTest::isHexagonFreeTrueTest();
    BoardTest::isHexagonFreeFalseTest();
    BoardTest::updateHexagonStateTest();

    return 0;
}*/
