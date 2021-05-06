#ifndef GAMETEST_H
#define GAMETEST_H

#include "AbaloneTest.hpp"

namespace abalone::test {

class GameTest: public AbaloneTest{

public:

    static void moveTest();

    static void moveLateral2MarbleTest();

    static void moveLateral3MarbleTest();

};

}//namespace abalone::test

#endif // GAMETEST_H
