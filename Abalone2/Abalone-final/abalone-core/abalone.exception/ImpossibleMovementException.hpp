#ifndef IMPOSSIBLEMOVEMENTEXCEPTION_H
#define IMPOSSIBLEMOVEMENTEXCEPTION_H

#include <iostream>
#include "MarbleException.hpp"

namespace abalone::exception {

/**
 * @brief The ImpossibleMovementException class, a customized exception class that inherit the methods and attributes of MarbleException.
 */
class ImpossibleMovementException: public MarbleException {
public:

    /**
     * @brief ImpossibleMovementException a simple constructor of the ImpossibleMovementException class.
     *
     * @param msg a string.
     * @param fileName a string.
     * @param functionName a string.
     * @param line an integer.
     */
    inline ImpossibleMovementException(std::string msg, std::string fileName, std::string functionName, int line):MarbleException(msg, fileName, functionName, line)
    {}
};

} // namespace abalone::exception

#endif // IMPOSSIBLEMOVEMENTEXCEPTION_H
