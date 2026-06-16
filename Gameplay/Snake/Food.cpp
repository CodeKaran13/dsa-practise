//
// Created by Karan Nandkar on 07/06/26.
//

#include "Food.h"
#include <cstdlib>

namespace Snake
{
    const Position& Food::GetPosition() const
    {
        return position;
    }

    void Food::Spawn(const Board& board, const Snake& snake)
    {
        do
        {
            position.x = std::rand() % board.GetWidth();
            position.y = std::rand() % board.GetHeight();
        }
        while (snake.Contains(position));
    }
} // Snake
