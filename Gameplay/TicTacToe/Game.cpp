//
// Created by Karan Nandkar on 01/06/26.
//

#include "Game.h"
#include <iostream>
#include "Cell.h"


Game::Game()
    : player1("Player 1", Cell::X),
      player2("Player 2", Cell::O),
      currentPlayer(&player1),
      isGameOver(false)
{}

void Game::Start()
{
    board.Reset();
    currentPlayer = &player1;
    isGameOver = false;

    std::cout << "Game started\n";
    board.Print();
}

bool Game::PlayTurn(int row, int col)
{
    if (isGameOver)
    {
        std::cout << "Game is already over\n";
        return false;
    }

    bool moveSuccess = board.MakeMove(row, col, currentPlayer->GetSymbol());
    if (!moveSuccess)
    {
        std::cout << "Invalid move\n";
        return false;
    }

    board.Print();
    CheckGameState();

    if (!isGameOver)
    {
        SwitchTurn();
    }

    return true;
}

void Game::SwitchTurn()
{
    if (currentPlayer == &player1)
    {
        currentPlayer = &player2;
    }
    else
    {
        currentPlayer = &player1;
    }
}

void Game::CheckGameState()
{
    Cell winner = board.CheckWinner();

    if (winner != Cell::Empty)
    {
        std::cout << currentPlayer->GetName() << " wins\n";
        isGameOver = true;
        return;
    }

    if (board.IsFull())
    {
        std::cout << "Game draw\n";
        isGameOver = true;
    }
}
