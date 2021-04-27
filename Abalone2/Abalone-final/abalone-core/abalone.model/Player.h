#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

namespace abalone::model{

enum class Color;

/**
 * @brief The PlayerStatus enumeration represents
 * the different status of a player.
 */
enum class PlayerStatus{
    FAIL,PROGRESS,WIN
};

/**
 * @brief The Player class, represents a player in the game,
 * he has a color, a counter of marbles loss and a player status.
 */
class Player {
private:
    Color _color;
    PlayerStatus _status;
    int _marblesLoss;
public:

    /**
     * @brief Player a simple constructor of the Player class.
     * @param color a Color.
     * @param status a PlayerStatus.
     */
    Player(Color color, PlayerStatus status = PlayerStatus::PROGRESS);
    Player() = default;

    /**
     * @brief color method a simple getter of _color.
     * @return _color a Color.
     */
    Color color() const;

    /**
     * @brief playerStatus method a simple getter of _playerStatus.
     * @return _status a PlayerStatus.
     */
    PlayerStatus playerStatus() const;

    /**
     * @brief marblesLoss method a simple getter of _marblesLoss.
     * @return _marblesLoss an integer.
     */
    int marblesLoss() const;

    /**
     * @brief playerStatus method a simple setter of _playerStatus.
     * @param status a PlayerStatus.
     */
    void playerStatus(PlayerStatus status);

    /**
     * @brief marblesLoss method a simple setter of _marblesLoss
     * @param marblesLoss an integer.
     */
    void marblesLoss(int marblesLoss);

    /**
     * @brief to_string method, convert a Player into a string.
     * @return a string materialization of the Player.
     */
    std::string to_string();
};

/**
 * @brief to_string function, convert the PlayerStatus
 * given in parameter into a string.
 *
 * @param playerStatus a PlayerStatus
 * @return a string materialization of the PlayerStatus.
 */
std::string to_stringPlayer(PlayerStatus playerStatus){
    std::string strPlayerStatus = "";
    if(playerStatus == PlayerStatus::WIN){
        strPlayerStatus = "Win";
    }else if(playerStatus == PlayerStatus::FAIL){
        strPlayerStatus = "Fail";
    }else{
        strPlayerStatus = "In progress";
    }
    return strPlayerStatus;
}

}

#endif // PLAYER_H
