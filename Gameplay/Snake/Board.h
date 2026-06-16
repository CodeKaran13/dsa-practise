//
// Created by Karan Nandkar on 07/06/26.
//

#ifndef DSA_PRATISE_BOARD_H
#define DSA_PRATISE_BOARD_H
#include "Position.h"

namespace Snake
{
    class Board
    {
    private:
        int width;
        int height;

    public:
        Board(int width, int height);

        bool IsInside(const Position& pos) const;

        int GetWidth() const;
        int GetHeight() const;
    };
} // Snake

#endif //DSA_PRATISE_BOARD_H
