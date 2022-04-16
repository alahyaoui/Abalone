#ifndef COLOR_H
#define COLOR_H

#include <iostream>

namespace abalone::model{

/**
 * @brief The Color enumeration represents the color
 * of the 2 set of marbles and the color of the player.
 */
enum class Color{
    BLACK, WHITE, NONE
};

/**
 * @brief to_string function, convert a color into a string.
 * @param color a Color
 * @return a string
 */
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

}// namespace abalone::model

#endif // COLOR_H
