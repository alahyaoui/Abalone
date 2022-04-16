#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <iostream>

inline char rowToChar(int row){
    switch(std::toupper(row)){
    case 0:
        return 'I';
    case 1:
        return 'H';
    case 2:
        return 'G';
    case 3:
        return 'F';
    case 4:
        return 'E';
    case 5:
        return 'D';
    case 6:
        return 'C';
    case 7:
        return 'B';
    case 8:
        return 'A';
    default:
        throw "vous avez entrez une mauvaise coordonnee de ligne";
    }
}

inline std::string coordToString(int row, int col){
    std::string text = "(";
    text += rowToChar(row);
    text +=',' + std::to_string(col + 1) + ')';
    return text;
}

#endif // STRINGUTILS_HPP
