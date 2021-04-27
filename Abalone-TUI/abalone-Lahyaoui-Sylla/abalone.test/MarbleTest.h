#ifndef MARBLETEST_H
#define MARBLETEST_H

#include "AbaloneTest.hpp"

namespace abalone::test {

class MarbleTest: public AbaloneTest{
public:


    static void moveFreeTest();

    static void moveAndPushTest();

    static void moveAndPushInVoidTest();

    static void moveGeneral_Free_Test();

    static void moveGeneral_NotFree_Test();

    static void moveGeneral_NotFree_FailPush_Test();

    static void moveGeneral_NotFree_SucessPush_Test();

    static void moveGeneral_NotFree_FailPush_InVoid_Test();

    static void moveGeneral_NotFree_SucessPush_InVoid_Test();

    //static void moveTest();
private:
};

}// namespace abalone::test

#endif // MARBLETEST_H
