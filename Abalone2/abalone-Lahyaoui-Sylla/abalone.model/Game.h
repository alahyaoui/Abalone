#ifndef GAME_H
#define GAME_H

#include <array>

#include "Model.h"
#include "Subject.h"
#include "Marble.h"
#include "Board.h"
#include "Player.h"


using namespace nvs;

namespace abalone::model{

class Game: public Model{
private:
    int _currentRound;//Compteur de round IMPORTANT !!!! PERMETTRE DE CONNAITRE LE TOUR DU JOUEUR
    std::array<Marble, 28> _marbles;
    //std::vector<Marble> _marbles;//Vector prcq erreur compilation si j'essai de copier un vector dans un tableau
    std::array<Player, 2> _players;
    GameStatus _status = GameStatus::NOT_STARTED;//Erreur default constructor pour les autres arg quand j'utilises le constructeur Game
    Board _board;

    void updateStatus();
    void updateMarbleLoss();
    void updatePlayerStatus();
    void gameStatus(GameStatus gameStatus);
    void initializeMarbles();
    void initializePlayers();
public:
    void incRound();
    Color currentPlayerColor();
    void move(Position positionOfMarble, Position positionToGo);
    void move(Position positionOfMarble1,Position positionOfMarble2, Position positionToGo);
    void startGame();

    GameStatus gameStatus() const;
    Board board() const;
    std::array<Player, 2> players() const;
};

}//namespace abalone::abalonecore{
#endif // GAME_H
