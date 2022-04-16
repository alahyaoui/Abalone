#include "Hexagon.h"

//using namespace abalone::model;

namespace abalone::model{

Hexagon::Hexagon(HexagonType type, bool isFree):
    _type {type},
    _isFree {isFree}

{}

HexagonType Hexagon::type() const {
    return _type;
}

bool Hexagon::isFree() const{
    return _isFree;
}

void Hexagon::type(const HexagonType & type) {
    this->_type = type;
}

void Hexagon::isFree(const bool & isFree) {
    this->_isFree = isFree;
}

std::string Hexagon::to_string() const{
    if(this->_type == HexagonType::VOID){
        return "";
    }else if (!this->_isFree){
        return "* ";
    }
    return ". ";
}

}//namespace abalone::model
