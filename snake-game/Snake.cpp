//
// Created by Karan Nandkar on 07/06/26.
//

#include "Snake.h"

namespace Snake
{
    Snake::Snake(Position startPosition)
        : direction(Direction::Right)
    {
        body.push_front(startPosition);
        occupied.insert(startPosition);
    }

    void Snake::SetDirection(Direction newDirection)
    {
        if (IsOppositeDirection(newDirection))
            return;

        direction = newDirection;
    }

    Position Snake::GetNextHeadPosition() const
    {
        Position head = body.front();
        switch (direction)
        {
        case Direction::Up:
            head.y--;
            break;
        case Direction::Down:
            head.y++;
            break;
        case Direction::Left:
            head.x--;
            break;
        case Direction::Right:
            head.x++;
            break;
        }

        return head;
    }

    void Snake::Move(bool grow)
    {
        Position newHead = GetNextHeadPosition();

        body.push_front(newHead);
        occupied.insert(newHead);

        if (!grow)
        {
            Position tail = body.back();
            body.pop_back();
            occupied.erase(tail);
        }
    }

    bool Snake::Contains(const Position& pos) const
    {
        return occupied.count(pos) > 0;
    }

    bool Snake::WillCollideWithSelf(const Position& nextHead, bool grow) const
    {
        if (!Contains(nextHead))
            return false;

        if (!grow && nextHead == body.back())
            return false;

        return true;
    }

    const std::deque<Position>& Snake::GetBody() const
    {
        return body;
    }

    const Position& Snake::GetHead() const
    {
        return body.front();
    }

    bool Snake::IsOppositeDirection(Direction newDirection) const
    {
        return (direction == Direction::Up && newDirection == Direction::Down) ||
            (direction == Direction::Down && newDirection == Direction::Up) ||
            (direction == Direction::Left && newDirection == Direction::Right) ||
            (direction == Direction::Right && newDirection == Direction::Left);
    }
} // Snake
