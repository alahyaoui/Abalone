#ifndef MODEL_H
#define MODEL_H

#include "Subject.h"
#include <array>

using namespace nvs;

namespace abalone::model{

enum class GameStatus{
    NOT_STARTED, IN_PROGRESS, OVER
};

class Position;
class Board;
class Player;

class Model: public Subject{
public:
    virtual ~Model() = default;

    virtual void incRound() = 0;
    virtual void move(Position positionOfMarble, Position positionToGo) = 0;
    virtual void move(Position positionOfMarble1,Position positionOfMarble2, Position positionToGo) = 0;

    virtual void startGame() = 0;

    virtual GameStatus gameStatus() const = 0;
    virtual Board board() const = 0;
    virtual std::array<Player, 2> players() const = 0;
};
}
#endif // MODEL_H
