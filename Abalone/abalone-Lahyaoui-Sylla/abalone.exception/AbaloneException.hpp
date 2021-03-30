#ifndef ABALONEEXCEPTION_H
#define ABALONEEXCEPTION_H

#include <iostream>
#include <exception>

namespace abalone::exception {

class AbaloneException: public std::exception{
protected:
    std::string _msg;
    std::string _fileName;
    std::string _functionName;
    int _line;

public:
    AbaloneException(std::string msg, std::string fileName, std::string functionName, int line):
        _msg {msg},
        _fileName {fileName},
        _functionName {functionName},
        _line {line}
    {}

    virtual ~AbaloneException() = default;

    inline std::string to_string(){
        std::string str = "";
        str += this->_msg + "\n";
        str += "On File : " + this->_fileName + "\n";
        str += "On Function : " + this->_functionName + "\n";
        str += "On Line : " +  std::to_string(this->_line) + "\n";
        return str;
    }

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

}// namespace abalone::exception
#endif // ABALONEEXCEPTION_H
