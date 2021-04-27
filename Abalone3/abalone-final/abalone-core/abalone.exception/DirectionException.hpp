#ifndef DIRECTIONEXCEPTION_HPP
#define DIRECTIONEXCEPTION_HPP

#include <iostream>
#include "AbaloneException.hpp"

namespace abalone::exception {

/**
 * @brief The virtual DirectionException class, a customized exception class that inherit the methods and attributes of AbaloneException.
 */
class DirectionException: public AbaloneException{
public:

    /**
     * @brief DirectionException a simple constructor of the virtual DirectionException class.
     *
     * @param msg a string.
     * @param fileName a string.
     * @param functionName a string.
     * @param line an integer.
     */
    inline DirectionException(std::string msg, std::string fileName, std::string functionName, int line):AbaloneException(msg, fileName, functionName, line)
    {}

    virtual ~DirectionException() = default;
};

} // namespace abalone::exception

#endif // DIRECTIONEXCEPTION_HPP
