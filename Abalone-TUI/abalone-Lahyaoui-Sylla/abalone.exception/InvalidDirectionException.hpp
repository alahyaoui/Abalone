#ifndef INVALIDDIRECTIONEXCEPTION_HPP
#define INVALIDDIRECTIONEXCEPTION_HPP

#include <iostream>
#include "DirectionException.hpp"

namespace Ui::exception {

/**
 * @brief The InvalidDirectionException class, a customized exception class that inherit the methods and attributes of DirectionException.
 */
class InvalidDirectionException: public DirectionException{
public:

    /**
     * @brief InvalidDirectionException a simple constructor of the InvalidDirectionException class.
     *
     * @param msg a string.
     * @param fileName a string.
     * @param functionName a string.
     * @param line an integer.
     */
    inline InvalidDirectionException(std::string msg, std::string fileName, std::string functionName, int line):DirectionException(msg, fileName, functionName, line)
    {}
};

} // namespace abalone::exception

#endif // INVALIDDIRECTIONEXCEPTION_HPP
