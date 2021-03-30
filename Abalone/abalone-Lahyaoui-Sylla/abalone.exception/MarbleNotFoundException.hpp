#ifndef MARBLENOTFOUNDEXCEPTION_HPP
#define MARBLENOTFOUNDEXCEPTION_HPP

#include <iostream>
#include "MarbleException.hpp"

namespace abalone::exception {

class MarbleNotFoundException: public MarbleException{
public:
    inline MarbleNotFoundException(std::string msg, std::string fileName, std::string functionName, int line):MarbleException(msg, fileName, functionName, line)
    {}
};

} // namespace abalone::exception

#endif // MARBLENOTFOUNDEXCEPTION_HPP
