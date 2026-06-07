//
// Created by Karan Nandkar on 07/06/26.
//

#ifndef DSA_PRATISE_SNAKE_H
#define DSA_PRATISE_SNAKE_H

#include <deque>
#include <unordered_set>

#include "Direction.h"
#include "Position.h"

namespace Snake
{
    class Snake
    {
    private:
        std::deque<Position> body;
        std::unordered_set<Position, PositionHash> occupied;
        Direction direction;

    public:
        Snake(Position startPosition);

        void SetDirection(Direction newDirection);

        Position GetNextHeadPosition() const;

        void Move(bool grow);

        bool Contains(const Position& pos) const;

        bool WillCollideWithSelf(const Position& nextHead, bool grow) const;

        const std::deque<Position>& GetBody() const;
        const Position& GetHead() const;

    private:
        bool IsOppositeDirection(Direction newDirection) const;
    };
} // Snake

#endif //DSA_PRATISE_SNAKE_H
