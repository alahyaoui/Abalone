#include "DirectionTest.h"
#include "abalone.model/Direction.hpp"
#include <iostream>

using namespace abalone::model;

namespace abalone::test {

void DirectionTest::toPositionTest(){
    std::cout << "Test de la methode toPosition" << std::endl;

    Direction direction = Direction::LEFT;
    Position exp = Position(0, -1);
    Position res = toPosition(direction);

    assertTrue(exp == res, __FUNCTION__);
}

void DirectionTest::toDirectionTest(){
    std::cout << "Test de la methode toDirection" << std::endl;

    Direction exp = Direction::LEFT;
    Direction res = toDirection(Position(0, -1));

    assertTrue(exp == res, __FUNCTION__);
}

void DirectionTest::computeDirectionTest(){
    std::cout << "Test de la methode computeDirection" << std::endl;

    Direction exp = Direction::DOWN;
    Direction res = computeDirection(Position(0, 4), Position(3, 4));

    assertTrue(exp == res, __FUNCTION__);
}

}// namespace abalone::test


/*
using namespace abalone::test;
int main(){
    DirectionTest::toPositionTest();
    DirectionTest::toDirectionTest();
    DirectionTest::computeDirectionTest();

    return 0;
}*/
