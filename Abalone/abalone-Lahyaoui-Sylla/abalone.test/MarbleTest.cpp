#include "MarbleTest.h"
#include "abalone.model/Marble.h"
#include "abalone.model/Board.h"

#include "abalone.exception/ImpossibleMovementException.hpp"
#include "abalone.exception/MarbleNotFoundException.hpp"

using namespace abalone::model;

namespace abalone::test {

Board boardMaker(){
    return Board (std::array<std::array<Hexagon, 9>, 9>
                  {{
                       { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                       { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                       { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                       { Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                       { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                       { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID)},
                       { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                       { Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID) },
                       { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                   }});
}

void MarbleTest::moveFreeTest(){
    std::cout << "Test de la methode moveFreeTest" << std::endl;
    std::cout << "la bille à la position (4,4) va se deplacer à la position (4,5)" << std::endl;

    Board board = boardMaker();
    Marble marbleToMove = Marble(Position(4,4), Color::BLACK);

    Position expPosition = Position(4,5);

    marbleToMove.moveFree(board, Position(4,5));

    Position resPosition = marbleToMove.positionOnBoard();

    assertTrue(expPosition == resPosition, __FUNCTION__);
}

void MarbleTest::moveAndPushTest(){
    std::cout << "Test de la methode moveAndPushTest" << std::endl;
    std::cout << "la bille Blanche à la position (3,4) va se deplacer à la position (1,4) "
                 "et pousser la bille Noir s'y trouvant déjà" << std::endl;

    Board board = boardMaker();

    Marble * marbleBlack1 = new Marble(Position(1,4), Color::BLACK);
    Marble * marbleWhite1 = new Marble(Position(2, 4), Color::WHITE);
    Marble * marbleWhite2 = new Marble(Position(3, 4), Color::WHITE);
    std::array<Marble*, 28> marbles = { marbleBlack1, marbleWhite1, marbleWhite2};

    auto expNextPosition = Position(1, 4);
    auto expNextEnemyPosition = Position(0, 4);

    Position positionToGo = marbleBlack1->positionOnBoard();
    Position nextEnemyPosition = Position(0, 4);
    marbleWhite2->moveAndPush(board, positionToGo, nextEnemyPosition, marbles);

    auto resNextPosition = marbleWhite2->positionOnBoard();
    auto resNextEnemyPosition = marbleBlack1->positionOnBoard();

    bool res = (expNextPosition == resNextPosition) && (expNextEnemyPosition == resNextEnemyPosition);

    assertTrue(res, __FUNCTION__);
}

void MarbleTest::moveAndPushInVoidTest(){
    std::cout << "Test de la methode moveAndPushTest" << std::endl;
    std::cout << "la bille Blanche à la position (3,4) va se deplacer à la position (1,4) "
                 "et pousser la bille Noir s'y trouvant déjà" << std::endl;

    Board board = boardMaker();

    Marble * marbleBlack1 = new Marble(Position(0,5), Color::BLACK);
    Marble * marbleWhite1 = new Marble(Position(1, 5), Color::WHITE);
    Marble * marbleWhite2 = new Marble(Position(2, 5), Color::WHITE);
    std::array<Marble*, 28> marbles = { marbleBlack1, marbleWhite1, marbleWhite2};

    auto expNextPosition = Position(0, 5);
    auto expNextEnemyPosition = Position(-1, -1);

    Position positionToGo = marbleBlack1->positionOnBoard();
    marbleWhite2->moveAndPushInVoid(board, positionToGo, marbles);

    auto resNextPosition = marbleWhite2->positionOnBoard();
    auto resNextEnemyPosition = marbleBlack1->positionOnBoard();

    bool res = (expNextPosition == resNextPosition) && (expNextEnemyPosition == resNextEnemyPosition);

    assertTrue(res, __FUNCTION__);
}

void MarbleTest::moveGeneral_Free_Test(){
    std::cout << "Test de la methode moveGeneral_Free_Test" << std::endl;
    std::cout << "La bille en position (0, 4) va se deplacer avec succes à la position (0, 5)" << std::endl;

    Board board = Board (std::array<std::array<Hexagon, 9>, 9>
                         {{
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                          }});

    Marble * marbleToMove = new Marble(Position(0,4), Color::BLACK);
    std::array<Marble*, 28> marbles = {marbleToMove};

    Position expPosition = Position(0,5);// bille choisie a bougé.

    marbleToMove->move(board, Position(0,5), marbles);

    Position resPosition = marbleToMove->positionOnBoard();

    assertTrue(expPosition == resPosition, __FUNCTION__);

}

void MarbleTest::moveGeneral_NotFree_Test(){
    std::cout << "Test de la methode moveGeneral_NotFree_Test" << std::endl;
    std::cout << "La bille va essayer de se deplacer sans succes" << std::endl;

    Board board = Board (std::array<std::array<Hexagon, 9>, 9>
                         {{
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                          }});

    Marble * marbleToMove = new Marble(Position(0,4), Color::BLACK);
    Marble * blockingMarble = new Marble(Position(0,5), Color::WHITE);
    std::array<Marble*, 28> marbles = {marbleToMove, blockingMarble};

    Position expPosition = Position(0,4);// bille choisie n'a pas bougé.

    bool expIsExceptionThrown = true;
    bool isExceptionThrown = false;

    try{
        marbleToMove->move(board, Position(0,5), marbles);
    }catch(abalone::exception::ImpossibleMovementException impossibleMovement){
        isExceptionThrown = true;
    }

    Position resPosition = marbleToMove->positionOnBoard();

    bool resException = expIsExceptionThrown == isExceptionThrown;
    bool resBoolPosition = expPosition == resPosition;
    bool res = resBoolPosition && resException;

    assertTrue(res , __FUNCTION__);
}

void MarbleTest::moveGeneral_NotFree_SucessPush_Test(){
    std::cout << "Test de la methode moveGeneral_NotFree_SucessPush_Test" << std::endl;
    std::cout << "La bille va essayer de se deplacer et de pousser les billes adverses avec succes" << std::endl;

    Board board = Board (std::array<std::array<Hexagon, 9>, 9>
                         {{
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                          }});

    Marble * marbleBlack1 = new Marble(Position(0,4), Color::BLACK);
    Marble * marbleBlack2 = new Marble(Position(1,4), Color::BLACK);
    Marble * marbleWhite1 = new Marble(Position(2, 4), Color::WHITE);
    std::array<Marble*, 28> marbles = { marbleBlack1, marbleBlack2, marbleWhite1};

    Position expPosition = Position(2,4);// bille choisie a bougé.
    Position expEnemyPosition = Position(3,4);// bille ennemie a été deplacé.

    bool expIsExceptionThrown = false;
    bool isExceptionThrown = false;

    try{
        marbleBlack1->move(board, Position(1, 4), marbles);
    }catch(abalone::exception::ImpossibleMovementException * impossibleMovement){
        isExceptionThrown = true;
    }

    Position resPosition = marbleBlack1->positionOnBoard();
    Position resEnemyPosition = marbleWhite1->positionOnBoard();

    bool resException = expIsExceptionThrown == isExceptionThrown;
    bool resBoolPosition = (expPosition == resPosition) && (expEnemyPosition == resEnemyPosition);
    bool res = resBoolPosition && resException;

    assertTrue(res , __FUNCTION__);
}

void MarbleTest::moveGeneral_NotFree_FailPush_Test(){
    std::cout << "Test de la methode moveGeneral_NotFree_FailPush_Test" << std::endl;
    std::cout << "La bille va essayer de se deplacer et de pousser les billes adverses sans succes" << std::endl;

    Board board = Board (std::array<std::array<Hexagon, 9>, 9>
                         {{
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                          }});

    Marble * marbleBlack1 = new Marble(Position(0,4), Color::BLACK);
    Marble * marbleBlack2 = new Marble(Position(1,4), Color::BLACK);
    Marble * marbleWhite1 = new Marble(Position(2, 4), Color::WHITE);
    Marble * marbleWhite2 = new Marble(Position(3, 4), Color::WHITE);
    std::array<Marble*, 28> marbles = { marbleBlack1, marbleBlack2, marbleWhite1, marbleWhite2 };

    Position expPosition = Position(0,4);// bille choisie n'a pas bougé.
    Position expEnemyPosition = Position(2,4);// bille ennemie n'a pas été déplacé.

    bool expIsExceptionThrown = true;
    bool isExceptionThrown = false;

    try{
        marbleBlack1->move(board, Position(1, 4), marbles);
    }catch(abalone::exception::ImpossibleMovementException impossibleMovement){
        isExceptionThrown = true;
    }

    Position resPosition = marbleBlack1->positionOnBoard();
    Position resEnemyPosition = marbleWhite1->positionOnBoard();

    bool resException = expIsExceptionThrown == isExceptionThrown;
    bool resBoolPosition = (expPosition == resPosition) && (expEnemyPosition == resEnemyPosition);
    bool res = resBoolPosition && resException;

    assertTrue(res , __FUNCTION__);
}

void MarbleTest::moveGeneral_NotFree_SucessPush_InVoid_Test(){
    std::cout << "Test de la methode moveGeneral_NotFree_SucessPush_InVoid_Test" << std::endl;
    std::cout << "La bille va essayer de se deplacer et de pousser les billes adverses dans le vide avec succes" << std::endl;

    Board board = Board (std::array<std::array<Hexagon, 9>, 9>
                         {{
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                          }});

    Marble * marbleBlack1 = new Marble(Position(0,4), Color::BLACK);
    Marble * marbleBlack2 = new Marble(Position(1,4), Color::BLACK);
    Marble * marbleWhite1 = new Marble(Position(2, 4), Color::WHITE);
    Marble * marbleWhite2 = new Marble(Position(3, 4), Color::WHITE);
    Marble * marbleWhite3 = new Marble(Position(4, 4), Color::WHITE);
    std::array<Marble*, 28> marbles = { marbleBlack1, marbleBlack2, marbleWhite1, marbleWhite2, marbleWhite3};

    Position expPosition = Position(1,4);// bille choisie a bougé.
    Position expEnemyPosition = Position(-1, -1);// bille ennemie a été deplacé.

    bool expIsExceptionThrown = false;
    bool isExceptionThrown = false;

    try{
        marbleWhite3->move(board, Position(3, 4), marbles);
    }catch(abalone::exception::ImpossibleMovementException impossibleMovement){
        isExceptionThrown = true;
    }

    Position resPosition = marbleWhite3->positionOnBoard();
    Position resEnemyPosition = marbleBlack2->positionOnBoard();

    bool resException = expIsExceptionThrown == isExceptionThrown;
    bool resBoolPosition = (expPosition == resPosition) && (expEnemyPosition == resEnemyPosition);
    bool res = resBoolPosition && resException;

    assertTrue(res , __FUNCTION__);
}

void MarbleTest::moveGeneral_NotFree_FailPush_InVoid_Test(){
    std::cout << "Test de la methode moveGeneral_NotFree_FailPush_InVoid_Test" << std::endl;
    std::cout << "La bille va essayer de se deplacer et de pousser les billes adverses dans le vide sans succes" << std::endl;

    Board board = Board (std::array<std::array<Hexagon, 9>, 9>
                         {{
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::VOID), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST, false), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                              { Hexagon(HexagonType::EXIST),Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID) },
                              { Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::EXIST), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID), Hexagon(HexagonType::VOID)},
                          }});

    Marble * marbleBlack1 = new Marble(Position(0,4), Color::BLACK);
    Marble * marbleBlack2 = new Marble(Position(1,4), Color::BLACK);
    Marble * marbleWhite1 = new Marble(Position(2, 4), Color::WHITE);
    Marble * marbleWhite2 = new Marble(Position(3, 4), Color::WHITE);
    std::array<Marble*, 28> marbles = { marbleBlack1, marbleBlack2, marbleWhite1, marbleWhite2};

    Position expPosition = Position(3,4);// bille choisie n'a pas bougé.
    Position expEnemyPosition = Position(1, 4);// bille ennemie n'a pas été déplacé.

    bool expIsExceptionThrown = true;// exeption a été lancée
    bool isExceptionThrown = false;

    try{
        marbleWhite2->move(board, Position(2, 4), marbles);
    }catch(abalone::exception::ImpossibleMovementException impossibleMovement){
        isExceptionThrown = true;
    }

    Position resPosition = marbleWhite2->positionOnBoard();
    Position resEnemyPosition = marbleBlack2->positionOnBoard();

    bool resException = expIsExceptionThrown == isExceptionThrown;
    bool resBoolPosition = (expPosition == resPosition) && (expEnemyPosition == resEnemyPosition);
    bool res = resBoolPosition && resException;

    assertTrue(res , __FUNCTION__);
}


}// namespace abalone::test

/*
using namespace abalone::test;
int main(){
    MarbleTest::moveFreeTest();
    MarbleTest::moveAndPushTest();
    MarbleTest::moveAndPushInVoidTest();

    MarbleTest::moveGeneral_Free_Test();
    MarbleTest::moveGeneral_NotFree_Test();

    MarbleTest::moveGeneral_NotFree_SucessPush_Test();
    MarbleTest::moveGeneral_NotFree_FailPush_Test();

    MarbleTest::moveGeneral_NotFree_SucessPush_InVoid_Test();
    MarbleTest::moveGeneral_NotFree_FailPush_InVoid_Test();

    //MarbleTest::moveTest();
}*/
