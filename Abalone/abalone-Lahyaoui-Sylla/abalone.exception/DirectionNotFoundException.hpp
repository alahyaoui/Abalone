#ifndef NOTFOUNDDIRECTIONEXCEPTION_H
#define NOTFOUNDDIRECTIONEXCEPTION_H

#include <iostream>
#include "DirectionException.hpp"

namespace abalone::exception {

class DirectionNotFoundException: public DirectionException{
public:
    inline DirectionNotFoundException(std::string msg, std::string fileName, std::string functionName, int line):DirectionException(msg, fileName, functionName, line)
    {}
};

}// namespace abalone::exception


#endif // NOTFOUNDDIRECTIONEXCEPTION_H
