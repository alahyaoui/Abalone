#ifndef HEXAGON_H
#define HEXAGON_H

#include <ostream>

namespace abalone::model{

/**
 * @brief The HexagonType enum, represents the type the hexagon can take.
 */
enum class HexagonType{
    VOID, EXIST
};

/**
 * @brief The Hexagon class, represents a case of the board.
 */
class Hexagon{

private:
    HexagonType _type;
    bool _isFree;

public:

    /**
     * @brief Hexagon a simple constructor of the Hexagon class.
     * @param type an HexagonType.
     * @param isFree a boolean (optional).
     */
    Hexagon(HexagonType type, bool isFree = true);

    /**
     * @brief type method a simple getter of _type.
     * @return _type an HexagonType.
     */
    HexagonType type() const;

    /**
     * @brief isFree method a simple getter of _isFree.
     * @return _isFree a boolean.
     */
    bool isFree() const;

    /**
     * @brief type method a simple setter of _type.
     * @param type an HexagonType.
     */
    void type(const HexagonType &type);

    /**
     * @brief isFree method a simple setter of _isFree.
     * @param isFree a boolean.
     */
    void isFree(const bool & isFree);

    /**
     * @brief to_string method, converts an Hexagon into a string.
     * @return the string materialization of an Hexagon.
     */
    std::string to_string() const;
};

}// namespace abalone::abalonecore

#endif // HEXAGON_H
