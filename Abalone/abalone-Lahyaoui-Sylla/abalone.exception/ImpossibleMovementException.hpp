#ifndef IMPOSSIBLEMOVEMENTEXCEPTION_H
#define IMPOSSIBLEMOVEMENTEXCEPTION_H

#include <iostream>
#include "MarbleException.hpp"

namespace abalone::exception {

class ImpossibleMovementException: public MarbleException {
public:
    inline ImpossibleMovementException(std::string msg, std::string fileName, std::string functionName, int line):MarbleException(msg, fileName, functionName, line)
    {}
};

} // namespace abalone::exception

#endif // IMPOSSIBLEMOVEMENTEXCEPTION_H
