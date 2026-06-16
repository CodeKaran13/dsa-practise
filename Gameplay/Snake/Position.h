//
// Created by Karan Nandkar on 07/06/26.
//

#ifndef DSA_PRATISE_POSITION_H
#define DSA_PRATISE_POSITION_H

#include <functional>

namespace Snake
{
    struct Position
    {
        int x, y;

        bool operator==(const Position& other) const
        {
            return x == other.x && y == other.y;
        }
    };

    struct PositionHash
    {
        size_t operator()(const Position& pos) const
        {
            return std::hash<int>()(pos.x) ^ (std::hash<int>()(pos.y) << 1);
        }
    };
} // Snake

#endif //DSA_PRATISE_POSITION_H
