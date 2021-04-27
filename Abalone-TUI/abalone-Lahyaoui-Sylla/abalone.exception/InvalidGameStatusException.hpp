#ifndef INVALIDGAMESTATUSEXCEPTION_H
#define INVALIDGAMESTATUSEXCEPTION_H

#include <iostream>
#include "AbaloneException.hpp"

namespace abalone::exception {

/**
 * @brief The InvalidGameStatusException class, a customized exception class that inherit the methods and attributes of AbaloneException.
 */
class InvalidGameStatusException: public AbaloneException {
public:

    /**
     * @brief InvalidGameStatusException a simple constructor of the InvalidGameStatusException class.
     *
     * @param msg a string.
     * @param fileName a string.
     * @param functionName a string.
     * @param line an integer.
     */
    inline InvalidGameStatusException(std::string msg, std::string fileName, std::string functionName, int line):AbaloneException(msg, fileName, functionName, line)
    {}
};

}// namespace abalone::exception

#endif // INVALIDGAMESTATUSEXCEPTION_H
