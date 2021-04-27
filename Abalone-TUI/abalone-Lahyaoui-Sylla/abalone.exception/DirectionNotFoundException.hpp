#ifndef NOTFOUNDDIRECTIONEXCEPTION_H
#define NOTFOUNDDIRECTIONEXCEPTION_H

#include <iostream>
#include "DirectionException.hpp"

namespace Ui::exception {

/**
 * @brief The DirectionNotFoundException class, a customized exception class that inherit the methods and attributes of DirectionException.
 */
class DirectionNotFoundException: public DirectionException{
public:

    /**
     * @brief DirectionNotFoundException a simple constructor of the DirectionNotFoundException class.
     *
     * @param msg a string.
     * @param fileName a string.
     * @param functionName a string.
     * @param line an integer.
     */
    inline DirectionNotFoundException(std::string msg, std::string fileName, std::string functionName, int line):DirectionException(msg, fileName, functionName, line)
    {}
};

}// namespace abalone::exception


#endif // NOTFOUNDDIRECTIONEXCEPTION_H
