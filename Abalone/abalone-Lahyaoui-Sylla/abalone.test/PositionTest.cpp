#include "PositionTest.h"
#include "abalone.model/Position.h"
#include "abalone.model/Direction.hpp"

using namespace abalone::model;

namespace abalone::test {

void PositionTest::nextLeftTest(){
    Direction direction = Direction::LEFT;
    Position originalPos = Position(2, 4);

    Position expNextPos = Position (2, 3);

    Position resNextPos = originalPos.next(direction);

    assertTrue(expNextPos == resNextPos, __FUNCTION__);
}

void PositionTest::nextRigthTest(){
    Direction direction = Direction::RIGHT;
    Position originalPos = Position(2, 6);

    Position expNextPos = Position (2, 7);

    Position resNextPos = originalPos.next(direction);

    assertTrue(expNextPos == resNextPos, __FUNCTION__);
}

void PositionTest::nextUpTest(){
    Direction direction = Direction::UP;
    Position originalPos = Position(6, 4);

    Position expNextPos = Position (5, 4);

    Position resNextPos = originalPos.next(direction);

    assertTrue(expNextPos == resNextPos, __FUNCTION__);
}

void PositionTest::nextDownTest(){
    Direction direction = Direction::DOWN;
    Position originalPos = Position(2, 5);

    Position expNextPos = Position (3, 5);

    Position resNextPos = originalPos.next(direction);

    assertTrue(expNextPos == resNextPos, __FUNCTION__);
}

void PositionTest::nextUpRigthTest(){
    Direction direction = Direction::UP_RIGHT;
    Position originalPos = Position(6, 4);

    Position expNextPos = Position (5, 5);

    Position resNextPos = originalPos.next(direction);

    assertTrue(expNextPos == resNextPos, __FUNCTION__);

}

/*
void PositionTest::nextUpLeftTest(){
    Direction direction = Direction::UP_LEFT;
    Position originalPos = Position(6, 4);

    Position expNextPos = Position (5, 3);

    Position resNextPos = originalPos.next(direction);

    assertTrue(expNextPos == resNextPos, __FUNCTION__);
}*/

/*
void PositionTest::nextDownRigthTest(){
    Direction direction = Direction::DOWN_RIGHT;
    Position originalPos = Position(2, 5);

    Position expNextPos = Position (3, 6);

    Position resNextPos = originalPos.next(direction);

    assertTrue(expNextPos == resNextPos, __FUNCTION__);
}*/

void PositionTest::nextDownLeftTest(){
    Direction direction = Direction::DOWN_LEFT;
    Position originalPos = Position(2, 5);

    Position expNextPos = Position (3, 4);

    Position resNextPos = originalPos.next(direction);

    assertTrue(expNextPos == resNextPos, __FUNCTION__);
}

void PositionTest::equalsTrueTest(){
    Position pos1 = Position(4,3);
    Position pos2 = Position(4,3);

    bool exp = true;

    //bool res = pos1.equals(pos2);
    bool res = pos1 == pos2;

    assertTrue(exp == res, __FUNCTION__);
}

void PositionTest::equalsFalseTest(){
    Position pos1 = Position(4,3);
    Position pos2 = Position(0,0);

    bool exp = false;

    //bool res = pos1.equals(pos2);
    bool res = pos1 == pos2;

    assertTrue(exp == res, __FUNCTION__);
}

}// namespace abalone::test


/*
using namespace abalone::test;
int main(){
    PositionTest::nextLeftTest();
    PositionTest::nextRigthTest();
    PositionTest::nextUpTest();
    PositionTest::nextDownTest();
    PositionTest::nextUpRigthTest();
    //PositionTest::nextUpLeftTest();

    //PositionTest::nextDownRigthTest();
    PositionTest::nextDownLeftTest();

    PositionTest::equalsTrueTest();
    PositionTest::equalsFalseTest();

    return 0;
}*/
