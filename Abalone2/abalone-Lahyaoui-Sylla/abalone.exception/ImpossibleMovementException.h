#ifndef IMPOSSIBLEMOVEMENTEXCEPTION_H
#define IMPOSSIBLEMOVEMENTEXCEPTION_H

#include <iostream>
#include <exception>

namespace abalone::exception {

class ImpossibleMovementException: public std::exception{
private:
    std::string _msg;
    std::string _fileName;
    std::string _functionName;
    int _line;
public:
    inline ImpossibleMovementException(std::string msg, std::string fileName, std::string functionName, int line):
        _msg {msg},
        _fileName {fileName},
        _functionName {functionName},
        _line {line}
    {}

    inline std::string msg(){
        return this->_msg;
    }

    inline std::string fileName(){
        return this->_fileName;
    }

    inline std::string functionName(){
        return this->_functionName;
    }

    inline int line(){
        return this->_line;
    }
};

} // namespace abalone::exception

#endif // IMPOSSIBLEMOVEMENTEXCEPTION_H
