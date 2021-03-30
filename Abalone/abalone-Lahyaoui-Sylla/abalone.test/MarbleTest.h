#ifndef MARBLETEST_H
#define MARBLETEST_H

#include "AbaloneTest.hpp"

namespace abalone::test {

class MarbleTest: public AbaloneTest{
public:

    void moveTest();
    void moveFreeTest();
    void moveAndPushTest();
    void moveAndPushInVoidTest();

private:
};

}// namespace abalone::test

#endif // MARBLETEST_H
