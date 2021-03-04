#ifndef HEXAGON_H
#define HEXAGON_H

#include <ostream>

namespace abalone::abalonecore{

enum class HexagonType{
    VOID, EXIST
};

class Hexagon{

private:
    bool _isFree;
    HexagonType _type;

public:
    inline Hexagon(HexagonType type, bool isFree = true);

    inline HexagonType type() const;
    inline bool isFree() const;

    inline void type(HexagonType type);
    inline void isFree(bool isFree);

    inline std::string to_string() const;
};

}// namespace abalone::abalonecore

#endif // HEXAGON_H
