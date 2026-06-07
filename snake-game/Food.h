//
// Created by Karan Nandkar on 07/06/26.
//

#ifndef DSA_PRATISE_FOOD_H
#define DSA_PRATISE_FOOD_H

#include "Board.h"
#include "Position.h"
#include "Snake.h"

namespace Snake
{
    class Food
    {
    private:
        Position position;

    public:
        const Position& GetPosition() const;

        void Spawn(const Board& board, const Snake& snake);
    };
} // Snake

#endif //DSA_PRATISE_FOOD_H
