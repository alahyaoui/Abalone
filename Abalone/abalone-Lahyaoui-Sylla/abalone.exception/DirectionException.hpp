#ifndef DIRECTIONEXCEPTION_HPP
#define DIRECTIONEXCEPTION_HPP

#include <iostream>
#include "AbaloneException.hpp"

namespace abalone::exception {

class DirectionException: public AbaloneException{
public:
    inline DirectionException(std::string msg, std::string fileName, std::string functionName, int line):AbaloneException(msg, fileName, functionName, line)
    {}
};

} // namespace abalone::exception

#endif // DIRECTIONEXCEPTION_HPP
