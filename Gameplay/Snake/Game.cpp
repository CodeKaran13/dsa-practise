//
// Created by Karan Nandkar on 07/06/26.
//

#include "Game.h"

#include <iostream>
#include <cstdlib>

namespace Snake
{
    Game::Game(int width, int height)
        : board(width, height),
          snake(Position{width / 2, height / 2}),
          score(0),
          gameOver(false)
    {}

    void Game::Run()
    {
        while (!gameOver)
        {
            Render();

            char input;
            std::cout << "Move W/A/S/D: ";
            std::cin >> input;

            HandleInput(input);
            Update();
        }
    }

    void Game::HandleInput(char input)
    {
        switch (input)
        {
        case 'w':
        case 'W':
            snake.SetDirection(Direction::Up);
            break;
        case 's':
        case 'S':
            snake.SetDirection(Direction::Down);
            break;
        case 'a':
        case 'A':
            snake.SetDirection(Direction::Left);
            break;
        case 'd':
        case 'D':
            snake.SetDirection(Direction::Right);
            break;
        }
    }

    void Game::Update()
    {
        Position nexHead = snake.GetNextHeadPosition();
        bool willEatFood = nexHead == food.GetPosition();

        if (!board.IsInside(nexHead))
        {
            gameOver = true;
            return;
        }

        if (snake.WillCollideWithSelf(nexHead, willEatFood))
        {
            gameOver = true;
            return;
        }

        snake.Move(willEatFood);

        if (willEatFood)
        {
            score++;
            food.Spawn(board, snake);
        }
    }

    void Game::Render()
    {
        system("clear"); // use "cls" on Windows
        for (int y = 0; y < board.GetHeight(); y++)
        {
            for (int x = 0; x < board.GetWidth(); x++)
            {
                Position current{x, y};

                if (current == snake.GetHead())
                    std::cout << 'O';
                else if (snake.Contains(current))
                    std::cout << 'o';
                else if (current == food.GetPosition())
                    std::cout << 'F';
                else
                    std::cout << '.';
            }
            std::cout << '\n';
        }
        std::cout << "Score: " << score << "\n";
    }
} // Snake
