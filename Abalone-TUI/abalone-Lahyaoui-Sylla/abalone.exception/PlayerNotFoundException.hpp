#ifndef PLAYERNOTFOUNDEXCEPTION_HPP
#define PLAYERNOTFOUNDEXCEPTION_HPP

#include <iostream>
#include "AbaloneException.hpp"

namespace Ui::exception {

/**
 * @brief The PlayerNotFoundException class, a customized exception class that inherit the methods and attributes of AbaloneException.
 */
class PlayerNotFoundException: public AbaloneException{
public:

    /**
     * @brief PlayerNotFoundException a simple constructor of the PlayerNotFoundException class.
     *
     * @param msg a string.
     * @param fileName a string.
     * @param functionName a string.
     * @param line an integer.
     */
    inline PlayerNotFoundException(std::string msg, std::string fileName, std::string functionName, int line):AbaloneException(msg, fileName, functionName, line)
    {}
};

} // namespace abalone::exception

#endif // PLAYERNOTFOUNDEXCEPTION_HPP
