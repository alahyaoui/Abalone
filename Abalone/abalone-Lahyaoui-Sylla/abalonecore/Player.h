#ifndef PLAYER_H
#define PLAYER_H

namespace abalone::abalonecore{

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
    inline Player(Color color, PlayerStatus status = PlayerStatus::PROGRESS);

    inline Color color() const;
    inline PlayerStatus playerStatus() const;
    inline int marblesLoss() const;

    inline void playerStatus(PlayerStatus status);
    inline void marblesLoss(int marblesLoss);
};

}

#endif // PLAYER_H
