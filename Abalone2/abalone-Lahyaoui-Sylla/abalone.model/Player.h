#ifndef PLAYER_H
#define PLAYER_H

#include "iostream"

namespace abalone::model{

enum class Color;
enum class PlayerStatus{
    FAIL,PROGRESS,WIN
};

class Player {
private:
    Color _color;
    PlayerStatus _status;
    int _marblesLoss;
public:
    Player(Color color, PlayerStatus status = PlayerStatus::PROGRESS);
    Player() = default;

    Color color() const;
    PlayerStatus playerStatus() const;
    int marblesLoss() const;

    void playerStatus(PlayerStatus status);
    void marblesLoss(int marblesLoss);

    std::string to_string();
};

inline std::string to_string(PlayerStatus playerStatus){
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
