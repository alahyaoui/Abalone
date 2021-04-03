#ifndef GAME_H
#define GAME_H

#include <array>

#include "Model.h"
#include "Subject.h"
#include "Marble.h"
#include "Board.h"
#include "Player.h"


//using namespace nvs;

namespace abalone::model{

class Game: public Model{
private:
    int _currentRound;//Compteur de round IMPORTANT !!!! PERMETTRE DE CONNAITRE LE TOUR DU JOUEUR
    std::array<Marble*, 28> _marbles;
    //std::vector<Marble> _marbles;//Vector prcq erreur compilation si j'essai de copier un vector dans un tableau
    std::array<Player, 2> _players;
    GameStatus _status = GameStatus::NOT_STARTED;//Erreur default constructor pour les autres arg quand j'utilises le constructeur Game
    Board _board;

    /**
     * @brief updateStatus method, updates the status of the Game.
     */
    void updateStatus();

    /**
     * @brief updateMarbleLoss method, updates the marbles loss counter of the players contained by _players.
     */
    void updateMarblesLoss();

    /**
     * @brief updatePlayerStatus method, updates the status of the players contained by _players.
     */
    void updatePlayerStatus();

    /**
     * @brief gameStatus method, simple setter of _status.
     * @param gameStatus a GameStatus.
     */
    void gameStatus(GameStatus gameStatus);

    /**
     * @brief initializeMarbles method, initializes _marbles an array of marbles.
     */
    void initializeMarbles();

    /**
     * @brief initializePlayers method, initializes _player an array of players.
     */
    void initializePlayers();

    /**
     * @brief currentPlayerColor method, gives the current color of the player
     * by using the current round to compute which player have to play this turn.
     *
     * @return the color of the current player.
     */
    Color currentPlayerColor() const;

public:

    /**
     * @brief incRound method, increments _currentRound the round counter.
     */
    void incRound();

    /**
     * @brief move method, moves the marble located at the first postion given in
     * parameter to the second position given in parameter.
     *
     * @param positionOfMarble a Position.
     * @param positionToGo a Position.
     */
    void move(Position positionOfMarble, Position positionToGo);

    /**
     * @brief move method, moves the all the marbles located between the first two position,
     * including the first two positions to the third one.
     *
     * @param positionOfMarble1
     * @param positionOfMarble2
     * @param positionToGo
     */
    void move(Position positionOfMarble1,Position positionOfMarble2, Position positionToGo);

    /**
     * @brief startGame method, starts the game by initializing all the game attributes.
     */
    void startGame();

    /**
     * @brief currentRound method a simple getter of _currentRound.
     * @return _currentRound an integer.
     */
    int currentRound() const;

    /**
     * @brief currentPlayerMarblesLoss method returns the marbleLoss of the currentPlayer..
     * @return currentPlayerMarblesLoss an integer.
     */
    int currentPlayerMarblesLoss() const;

    /**
     * @brief gameStatus method a simple getter of _status.
     * @return _status a GameStatus.
     */
    GameStatus gameStatus() const;

    /**
     * @brief board method a simple getter of _board.
     * @return _board a Board.
     */
    Board board() const;

    /**
     * @brief marbles method a simple getter of _marbles.
     * @return _marbles an array of Marbles.
     */
    std::array<Marble*, 28> marbles() const;

    /**
     * @brief players method a simple getter of _players.
     * @return _players an array of 2 Players.
     */
    std::array<Player, 2> players() const;
};

}//namespace abalone::abalonecore{
#endif // GAME_H
