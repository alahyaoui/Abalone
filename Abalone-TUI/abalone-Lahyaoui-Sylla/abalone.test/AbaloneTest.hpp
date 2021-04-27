#ifndef ABALONETEST_H
#define ABALONETEST_H

#include <iostream>

namespace abalone::test {

class AbaloneTest{
public:
    inline static void assertTrue(bool res, std::string testName);
    /*
    template <typename T>
    void assertEquals(T obj1 , T obj2) const ;
    */
private:
};

inline void AbaloneTest::assertTrue(bool res, std::string testName) {
    if(res == true){
        std::cout << "Test " << testName << " reussi" << std::endl;
    }else{
        std::cout << "Test " << testName << " echoue" << std::endl;
    }
    std::cout << std::endl;
}

/*
void AbaloneTest::assertEquals(T obj1 , T obj2) const{

}
*/
}
#endif // ABALONETEST_H
