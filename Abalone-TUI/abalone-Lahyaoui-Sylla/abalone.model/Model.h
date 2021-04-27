#ifndef MODEL_H
#define MODEL_H

//#include "Subject.h"
#include "abalone.observer/Subject.h"
#include <array>

using namespace nvs;

namespace abalone::model{

/**
 * @brief The GameStatus enum represents the different states of the Game.
 */
enum class GameStatus{
    NOT_STARTED, IN_PROGRESS, OVER
};

class Position;
class Board;
class Player;

/**
 * @brief The abstract Model class is the Interface model of the MVC structure.
 */
class Model: public Subject{
public:
    virtual ~Model() = default;

    /**
     * @brief incRound method, increments _currentRound the round counter.
     */
    virtual void incRound() = 0;

    /**
     * @brief move method, moves the marble located at the first postion given in
     * parameter to the second position given in parameter.
     *
     * @param positionOfMarble a Position.
     * @param positionToGo a Position.
     */
    virtual void move(Position positionOfMarble, Position positionToGo) = 0;

    /**
     * @brief move method, moves the all the marbles located between the first two position,
     * including the first two positions to the third one.
     *
     * @param positionOfMarble1
     * @param positionOfMarble2
     * @param positionToGo
     */
    virtual void move(Position positionOfMarble1,Position positionOfMarble2, Position positionToGo) = 0;

    /**
     * @brief startGame method, starts the game by initializing all the game attributes.
     */
    virtual void startGame() = 0;

    /**
     * @brief currentRound method a simple getter of _currentRound.
     * @return _currentRound an integer.
     */
    virtual int currentRound() const = 0;

    /**
     * @brief gameStatus method a simple getter of _status.
     * @return _status a GameStatus.
     */
    virtual GameStatus gameStatus() const = 0;

    /**
     * @brief board method a simple getter of _board.
     * @return _board a Board.
     */
    virtual Board board() const = 0;

    /**
     * @brief players method a simple getter of _players.
     * @return _players an array of 2 Players.
     */
    virtual std::array<Player, 2> players() const = 0;
};
}
#endif // MODEL_H
