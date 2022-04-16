#ifndef BOARDTEST_H
#define BOARDTEST_H

#include "AbaloneTest.hpp"

namespace abalone::test {

class BoardTest: public AbaloneTest{
private:
public:

    static void isInsideTrueTest();
    static void isInsideFalseTest();
    static void isHexagonFreeTrueTest();
    static void isHexagonFreeFalseTest();
    static void updateHexagonStateTest();

};

}// namespace abalone::test
#endif // BOARDTEST_H
