#ifndef POSITIONTEST_H
#define POSITIONTEST_H

#include "AbaloneTest.hpp"

namespace abalone::test {

class PositionTest: public AbaloneTest{
private:
public:

    static void nextLeftTest();
    static void nextRigthTest();

    static void nextUpTest();
    static void nextDownTest();

    static void nextUpRigthTest();
    //static void nextUpLeftTest();

    //static void nextDownRigthTest();
    static void nextDownLeftTest();

    static void equalsTrueTest();
    static void equalsFalseTest();

};

}// namespace abalone::test
#endif // POSITIONTEST_H
