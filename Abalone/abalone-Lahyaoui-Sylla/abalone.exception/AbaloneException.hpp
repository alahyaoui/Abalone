#ifndef ABALONEEXCEPTION_H
#define ABALONEEXCEPTION_H

#include <iostream>
#include <exception>

namespace abalone::exception {

/**
 * @brief The virtual AbaloneException class, serves as the body for exceptions that inherit from it.
 */
class AbaloneException: public std::exception{
protected:
    std::string _msg;
    std::string _fileName;
    std::string _functionName;
    int _line;

public:

    /**
     * @brief AbaloneException a simple constructor of the virtual AbaloneException class.
     *
     * @param msg a string.
     * @param fileName a string.
     * @param functionName a string.
     * @param line an integer.
     */
    AbaloneException(std::string msg, std::string fileName, std::string functionName, int line):
        _msg {msg},
        _fileName {fileName},
        _functionName {functionName},
        _line {line}
    {}

    virtual ~AbaloneException() = default;

    /**
     * @brief to_string method, converts the exception into a string.
     *
     * @return a string materialization of the exception.
     */
    inline std::string to_string(){
        std::string str = "";
        str += this->_msg + "\n";
        str += "On File : " + this->_fileName + "\n";
        str += "On Function : " + this->_functionName + "\n";
        str += "On Line : " +  std::to_string(this->_line) + "\n";
        return str;
    }

    /**
     * @brief msg method a simple getter of _msg.
     *
     * @return _msg a string.
     */
    inline std::string msg(){
        return this->_msg;
    }

    /**
     * @brief fileName method a simple getter of _fileName.
     *
     * @return _fileName a string.
     */
    inline std::string fileName(){
        return this->_fileName;
    }

    /**
     * @brief functionName method a simple getter of _functionName.
     *
     * @return _functionName a string.
     */
    inline std::string functionName(){
        return this->_functionName;
    }

    /**
     * @brief line method a simple getter of _line.
     *
     * @return _lines an int.
     */
    inline int line(){
        return this->_line;
    }
};

}// namespace abalone::exception
#endif // ABALONEEXCEPTION_H
