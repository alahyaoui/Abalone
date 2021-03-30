#ifndef MARBLEEXCEPTION_HPP
#define MARBLEEXCEPTION_HPP

#include <iostream>
#include "AbaloneException.hpp"

namespace abalone::exception {

class MarbleException: public AbaloneException {
public:
    inline MarbleException(std::string msg, std::string fileName, std::string functionName, int line):AbaloneException(msg, fileName, functionName, line)

    {}
    virtual ~MarbleException() = default;
};

} // namespace abalone::exception
#endif // MARBLEEXCEPTION_HPP
