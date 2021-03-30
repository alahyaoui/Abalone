#ifndef DIRECTIONTEST_H
#define DIRECTIONTEST_H

#include "AbaloneTest.hpp"

namespace abalone::test {

class DirectionTest: public AbaloneTest{
public:

    static void toPositionTest();
    static void toDirectionTest();
    static void computeDirectionTest();

private:
};

}// namespace abalone::test
#endif // DIRECTIONTEST_H
