#ifndef INVALIDGAMESTATUSEXCEPTION_H
#define INVALIDGAMESTATUSEXCEPTION_H

#include <iostream>
#include <exception>

namespace abalone::exception {

class InvalidGameStatusException: public std::exception{
private:
    std::string _msg;
public:
    inline InvalidGameStatusException(std::string msg = ""):
        _msg {msg}
    {}

    inline std::string msg(){
        return this->_msg;
    }
};

}// namespace abalone::exception

#endif // INVALIDGAMESTATUSEXCEPTION_H
