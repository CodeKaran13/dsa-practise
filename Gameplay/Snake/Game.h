//
// Created by Karan Nandkar on 07/06/26.
//

#ifndef DSA_PRATISE_GAME_H
#define DSA_PRATISE_GAME_H

#include "Board.h"
#include "Food.h"
#include "Snake.h"

namespace Snake
{
    class Game
    {
    private:
        Board board;
        Snake snake;
        Food food;

        int score;
        bool gameOver;

    public:
        Game(int width, int height);

        void Run();

    private:
        void HandleInput(char input);
        void Update();
        void Render();
    };
} // Snake

#endif //DSA_PRATISE_GAME_H
