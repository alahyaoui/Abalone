#ifndef HEXAGON_H
#define HEXAGON_H

#include <ostream>

namespace abalone::model{

enum class HexagonType{
    VOID, EXIST
};

class Hexagon{

private:
    bool _isFree;
    HexagonType _type;

public:
    Hexagon(HexagonType type, bool isFree = true);

    HexagonType type() const;
    bool isFree() const;

    void type(HexagonType type);
    void isFree(bool isFree);

    std::string to_string() const;
};

}// namespace abalone::abalonecore

#endif // HEXAGON_H
