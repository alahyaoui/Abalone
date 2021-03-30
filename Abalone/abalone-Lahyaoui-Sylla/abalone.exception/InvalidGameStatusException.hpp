#ifndef INVALIDGAMESTATUSEXCEPTION_H
#define INVALIDGAMESTATUSEXCEPTION_H

#include <iostream>
#include "AbaloneException.hpp"

namespace abalone::exception {

class InvalidGameStatusException: public AbaloneException {
public:
    inline InvalidGameStatusException(std::string msg, std::string fileName, std::string functionName, int line):AbaloneException(msg, fileName, functionName, line)
    {}
};

}// namespace abalone::exception

#endif // INVALIDGAMESTATUSEXCEPTION_H
