//
// Created by Karan Nandkar on 01/06/26.
//

#ifndef DSA_PRATISE_GAME_H
#define DSA_PRATISE_GAME_H

#include "Board.h"
#include "Player.h"


class Game
{
private:
    Board board;
    Player player1;
    Player player2;
    Player* currentPlayer;
    bool isGameOver;

public:
    Game();

    void Start();
    bool PlayTurn(int row, int col);

private:
    void SwitchTurn();
    void CheckGameState();
};


#endif //DSA_PRATISE_GAME_H
