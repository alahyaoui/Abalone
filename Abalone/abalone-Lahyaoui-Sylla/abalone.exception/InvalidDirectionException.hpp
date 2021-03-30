#ifndef INVALIDDIRECTIONEXCEPTION_HPP
#define INVALIDDIRECTIONEXCEPTION_HPP

#include <iostream>
#include "DirectionException.hpp"

namespace abalone::exception {

class InvalidDirectionException: public DirectionException{
public:
    inline InvalidDirectionException(std::string msg, std::string fileName, std::string functionName, int line):DirectionException(msg, fileName, functionName, line)
    {}
};

} // namespace abalone::exception

#endif // INVALIDDIRECTIONEXCEPTION_HPP
