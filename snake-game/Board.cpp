//
// Created by Karan Nandkar on 07/06/26.
//

#include "Board.h"

namespace Snake
{
    Board::Board(int width, int height)
        : width(width), height(height)
    {}

    bool Board::IsInside(const Position& pos) const
    {
        return pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height;
    }

    int Board::GetWidth() const
    {
        return width;
    }

    int Board::GetHeight() const
    {
        return height;
    }
} // Snake
