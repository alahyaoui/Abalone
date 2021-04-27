#ifndef MARBLENOTFOUNDEXCEPTION_HPP
#define MARBLENOTFOUNDEXCEPTION_HPP

#include <iostream>
#include "MarbleException.hpp"

namespace Ui::exception {

/**
 * @brief The MarbleNotFoundException class, a customized exception class that inherit the methods and attributes of MarbleException.
 */
class MarbleNotFoundException: public MarbleException{
public:

    /**
     * @brief MarbleNotFoundException a simple constructor of the MarbleNotFoundException class.
     *
     * @param msg a string.
     * @param fileName a string.
     * @param functionName a string.
     * @param line an integer.
     */
    inline MarbleNotFoundException(std::string msg, std::string fileName, std::string functionName, int line):MarbleException(msg, fileName, functionName, line)
    {}
};

} // namespace abalone::exception

#endif // MARBLENOTFOUNDEXCEPTION_HPP
