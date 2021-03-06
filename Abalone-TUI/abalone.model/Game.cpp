#include "Game.h"
#include "Position.h"
#include "Color.hpp"
#include "Player.h"
#include "Marble.h"

#include <vector>
#include <algorithm>

#include "abalone.exception/ImpossibleMovementException.hpp"
#include "abalone.exception/InvalidGameStatusException.hpp"
#include "abalone.exception/MarbleNotFoundException.hpp"
#include "abalone.exception/PlayerNotFoundException.hpp"

//using namespace nvs;
//using namespace abalone::model;

namespace abalone::model{

void Game::startGame(){
    this->_status = GameStatus::IN_PROGRESS;
    initializeMarbles();
    this->_board = Board();
    initializePlayers();
    notifyObservers();
}

void Game::updateStatus(){
    for(size_t i = 0; i < this->_players.size(); i++){
        if(this->_players.at(i).playerStatus() != PlayerStatus::PROGRESS)
            this->_status = GameStatus::OVER;
    }
}

void Game::updateMarblesLoss(){
    int countWhiteLoss = 0;
    int countBlackLoss = 0;
    for(auto marble : this->_marbles){
        if(marble->positionOnBoard() == Position(-1, -1)){
            if(marble->color() == Color::BLACK){
                countBlackLoss++;
            }else{
                countWhiteLoss++;
            }
        }
    }

    for(size_t i = 0; i < this->_players.size(); i++){
        if(this->_players.at(i).color() == Color::BLACK){
            this->_players.at(i).marblesLoss(countBlackLoss);
        }else{
            this->_players.at(i).marblesLoss(countWhiteLoss);
        }
    }
}

void Game::updatePlayerStatus(){
    for(size_t i = 0; i < this->_players.size(); i++){
        if(this->_players.at(i).marblesLoss() == 6){
            this->_players.at(i).playerStatus(PlayerStatus::FAIL);
            if(i == 0){
                this->_players.at(i+1).playerStatus(PlayerStatus::WIN);
            }else{
                this->_players.at(i-1).playerStatus(PlayerStatus::WIN);
            }
        }
    }
}

void Game::gameStatus(GameStatus gameStatus){
    this->_status = gameStatus;
}

void Game::initializeMarbles(){
    std::vector<Marble*> marbles;
    std::vector<Marble*> blackMarbles;
    std::vector<Marble*> whiteMarbles;
    int row = 0;
    int col = 4;
    int tmp = col;
    for(int i = 0; i < 11; i++){
        blackMarbles.push_back(new Marble(Position(row, col), Color::BLACK));
        if(col < 8){
            col++;
        }else{
            tmp--;
            col = tmp;
            row++;
        }
    }
    blackMarbles.push_back(new Marble(Position(2, 4),Color::BLACK));
    blackMarbles.push_back(new Marble(Position(2, 5),Color::BLACK));
    blackMarbles.push_back(new Marble(Position(2, 6),Color::BLACK));

    row = 8;
    col = 0;
    int range = 4;
    for(int i = 0; i < 11; i++){
        whiteMarbles.push_back(new Marble(Position(row, col), Color::WHITE));
        if(col < range){
            col++;
        }else{
            range++;
            col = 0;
            row--;
        }
    }
    whiteMarbles.push_back(new Marble(Position(6, 2),Color::WHITE));
    whiteMarbles.push_back(new Marble(Position(6, 3),Color::WHITE));
    whiteMarbles.push_back(new Marble(Position(6, 4),Color::WHITE));

    marbles.insert(marbles.end(), blackMarbles.begin(), blackMarbles.end());
    marbles.insert(marbles.end(), whiteMarbles.begin(), whiteMarbles.end());

    //std::copy(blackMarbles.begin(), blackMarbles.end(), marbles);

    std::copy_n(marbles.begin(), 28, this->_marbles.begin());
}

void Game::initializePlayers(){
    this->_players = {Player(Color::BLACK), Player(Color::WHITE)};
    /*
    this->_players.at(0) = Player(Color::BLACK);
    this->_players.at(1) = Player(Color::WHITE);
    */
}

Color Game::currentPlayerColor() const{
    Color currentPlayerColor;
    if(_currentRound % 2 == 0){
        currentPlayerColor = Color::BLACK;
    }else{
        currentPlayerColor = Color::WHITE;
    }
    return currentPlayerColor;
}

void Game::move(Position positionOfMarble, Position positionToGo){
    Marble * marbleToMove = nullptr;
    if(this->_status != GameStatus::IN_PROGRESS){
        throw abalone::exception::InvalidGameStatusException("The game status isn't in progress",  __FILE__, __FUNCTION__, __LINE__);
    }else{
        for(auto marble : this->_marbles){
            if(marble->positionOnBoard() == positionOfMarble){
                if(marble->color() == currentPlayerColor()){
                    marbleToMove = marble; // verifier constructeur par copie
                }else{
                    throw abalone::exception::ImpossibleMovementException("Vous avez essay?? de deplacer une bille adverse !", __FILE__, __FUNCTION__, __LINE__);
                }
            }
        }
        if(marbleToMove == nullptr){
            throw abalone::exception::MarbleNotFoundException("La bille que vous avez essay?? de deplacer n'existe pas !", __FILE__, __FUNCTION__, __LINE__);
        }else{
            marbleToMove->move(this->_board, positionToGo, this->_marbles);
            updateMarblesLoss();
            updatePlayerStatus();
            updateStatus();
            notifyObservers();
        }
    }
}

void Game::move(Position positionOfMarble1, Position positionOfMarble2, Position positionToGo){
    std::vector<Marble*> marblesToMove {};

    int rowMarble1;
    int rowMarble2;
    int colMarble1;
    int colMarble2;
    int colToMove;

    if(this->_status != GameStatus::IN_PROGRESS){
        throw abalone::exception::InvalidGameStatusException("The game status isn't in progress",  __FILE__, __FUNCTION__, __LINE__);
    }else{
        rowMarble1 = positionOfMarble1.x();
        rowMarble2 = positionOfMarble2.x();
        colMarble1 = positionOfMarble1.y();
        colMarble2 = positionOfMarble2.y();
        if(rowMarble1 == positionToGo.x()){
            throw abalone::exception::ImpossibleMovementException("Mouvement lat??ral impossible, "
                                                                  "vous avez choisis le mauvais type de mouvement !",
                                                                  __FILE__, __FUNCTION__, __LINE__);
        }

        if(rowMarble1 != rowMarble2){
            throw abalone::exception::ImpossibleMovementException("Vous avez essay?? d'effectuer un mouvement lat??ral sur deux billes de ligne diff??rentes !", __FILE__, __FUNCTION__, __LINE__);
        }

        if(colMarble1 - colMarble2 == -1){
            Marble * marbleToMove1 = nullptr;
            Marble * marbleToMove2 = nullptr;

            for(Marble * marble : this->_marbles){

                if(marble->positionOnBoard() == Position(positionToGo.x(), positionToGo.y())//Verifie si deja des billes la ou on veut aller.
                        || marble->positionOnBoard() == Position(positionToGo.x(), positionToGo.y() + 1)){
                    throw abalone::exception::ImpossibleMovementException("Mouvement lat??ral impossible,"
                                                                          " billes sur le chemin!",
                                                                          __FILE__, __FUNCTION__, __LINE__);
                }

                if(marble->positionOnBoard() == positionOfMarble1 || marble->positionOnBoard() == positionOfMarble2){
                    if(marble->color() == currentPlayerColor()){//Verifie que l'user n''a pas essay?? de deplacer des ou une bille(s) adverses
                        if(marble->positionOnBoard() == positionOfMarble1){
                            marbleToMove1 = marble;
                        }else if(marble->positionOnBoard() == positionOfMarble2){
                            marbleToMove2 = marble;
                        }
                    }else{
                        throw abalone::exception::ImpossibleMovementException("Vous avez essay?? de deplacer une bille adverse !", __FILE__, __FUNCTION__, __LINE__);
                    }
                }
            }

            if(marbleToMove1 != nullptr && marbleToMove2 != nullptr){
                marblesToMove.push_back(marbleToMove1);
                marblesToMove.push_back(marbleToMove2);
            }else{
                throw abalone::exception::MarbleNotFoundException("une des billes que vous avez essay?? de deplacer n'existe pas !", __FILE__, __FUNCTION__, __LINE__);
            }

        }else if(colMarble1 - colMarble2 == -2){
            Marble * marbleToMove1 = nullptr;
            Marble * marbleToMove2 = nullptr;
            Marble * marbleToMove3 = nullptr;
            for(auto marble : this->_marbles){

                if(marble->positionOnBoard() == Position(positionToGo.x(), positionToGo.y())//Verifie si deja des billes la ou on veut aller.
                        || marble->positionOnBoard() == Position(positionToGo.x(), positionToGo.y() + 1)
                        || marble->positionOnBoard() == Position(positionToGo.x(), positionToGo.y() + 2)){
                    throw abalone::exception::ImpossibleMovementException("Billes sur le chemin, mouvement lat??ral impossible !", __FILE__, __FUNCTION__, __LINE__);
                }

                if(marble->positionOnBoard() == positionOfMarble1
                        || marble->positionOnBoard() == Position(rowMarble1, colMarble1+1)
                        || marble->positionOnBoard() == positionOfMarble2){//Si egale a position1 position2 ou position entredeux

                    if(marble->color() == currentPlayerColor()){//Verifie que l'user n''a pas essay?? de deplacer des ou une bille(s) adverses
                        if(marble->positionOnBoard() == positionOfMarble1){
                            marbleToMove1 = marble;
                        }else if(marble->positionOnBoard() == Position(rowMarble1, colMarble1+1)){
                            marbleToMove2 = marble;
                        }else if(marble->positionOnBoard() == positionOfMarble2){
                            marbleToMove3 = marble;
                        }
                    }else{
                        throw abalone::exception::ImpossibleMovementException("Vous avez essay?? de deplacer une bille adverse !", __FILE__, __FUNCTION__, __LINE__);
                    }
                }
            }

            if(marbleToMove1 != nullptr && marbleToMove2 != nullptr  && marbleToMove3 != nullptr){
                marblesToMove.push_back(marbleToMove1);
                marblesToMove.push_back(marbleToMove2);
                marblesToMove.push_back(marbleToMove3);
            }else{
                throw abalone::exception::MarbleNotFoundException("une des billes que vous avez essay?? de deplacer n'existe pas !", __FILE__, __FUNCTION__, __LINE__);
            }

        }else{
            throw abalone::exception::ImpossibleMovementException("Vous n'avez pas choisis convenablement les billes a d??placer !", __FILE__, __FUNCTION__, __LINE__);
        }

        colToMove = positionToGo.y();//Servira a incrementer la col de la position de d??placement
        for(auto marble : marblesToMove){//On peut verifier si je deplace les billes dans le bonne ordre mais la fa??on dont les billes sont dans le tableaux ne devraient pas poser de probleme
            if(marble == nullptr || marble->color() == Color::NONE){//Verficiation pas necessaire
                throw abalone::exception::MarbleNotFoundException("une des billes que vous avez essay?? de deplacer n'existe pas !", __FILE__, __FUNCTION__, __LINE__);
            }else{
                marble->lateralMove(this->_board, Position(positionToGo.x(), colToMove));
                colToMove++;
            }
        }

        updateMarblesLoss();
        updatePlayerStatus();
        updateStatus();
        notifyObservers();
    }
}

void Game::incRound(){
    this->_currentRound++;
    notifyObservers();
}

int Game::currentRound() const{
    return this->_currentRound;
}


int Game::currentPlayerMarblesLoss() const{
    for(size_t i = 0; i < this->_players.size(); i++){
        if(this->_players.at(i).color() == currentPlayerColor())
            return this->_players.at(i).marblesLoss();
    }
    throw abalone::exception::PlayerNotFoundException("Aucun joueur ne correspondant n'a ete trouve !",  __FILE__, __FUNCTION__, __LINE__);
}

GameStatus Game::gameStatus() const{
    return _status;
}

Board Game::board() const{
    return _board;
}

std::array<Marble*, 28> Game::marbles() const{
    return this->_marbles;
}

std::array<Player, 2> Game::players() const{
    return this->_players;
}

} //namespace abalone::model

/*//POUR DEBUGER LES POSITIONS DES MARBLES !!!!
for(auto marble : this->_marbles){
                std::cout << marble->positionOnBoard().to_string();
            }
*/
