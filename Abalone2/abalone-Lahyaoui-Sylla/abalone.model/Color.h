#ifndef COLOR_H
#define COLOR_H

#include <iostream>

namespace abalone::model{

enum class Color{
    BLACK, WHITE, NONE
};

//inline std::string to_string(Color color);
inline std::string to_string(Color color){
    std::string strColor = "";
    if(color == Color::BLACK){
        strColor = "Black";
    }else if(color == Color::WHITE){
        strColor = "White";
    }else{
        strColor = "None";
    }
    return strColor;
}
}
#endif // COLOR_H
