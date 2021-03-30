#ifndef PLAYERNOTFOUNDEXCEPTION_HPP
#define PLAYERNOTFOUNDEXCEPTION_HPP

#include <iostream>
#include "AbaloneException.hpp"

namespace abalone::exception {

class PlayerNotFoundException: public AbaloneException{
public:
    inline PlayerNotFoundException(std::string msg, std::string fileName, std::string functionName, int line):AbaloneException(msg, fileName, functionName, line)
    {}
};

} // namespace abalone::exception

#endif // PLAYERNOTFOUNDEXCEPTION_HPP
