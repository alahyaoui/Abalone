#ifndef MARBLEEXCEPTION_HPP
#define MARBLEEXCEPTION_HPP

#include <iostream>
#include "AbaloneException.hpp"

namespace abalone::exception {
/**
 * @brief The virtual MarbleException class, a customized exception class that inherit the methods and attributes of AbaloneException.
 */
class MarbleException: public AbaloneException {
public:
    /**
     * @brief MarbleException a simple constructor of the virtual MarbleException class.
     * @param msg
     *
     * @param msg a string.
     * @param fileName a string.
     * @param functionName a string.
     * @param line an integer.
     */
    inline MarbleException(std::string msg, std::string fileName, std::string functionName, int line):AbaloneException(msg, fileName, functionName, line)

    {}

    virtual ~MarbleException() = default;
};

} // namespace abalone::exception
#endif // MARBLEEXCEPTION_HPP
