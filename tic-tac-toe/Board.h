//
// Created by Karan Nandkar on 01/06/26.
//

#ifndef DSA_PRATISE_BOARD_H
#define DSA_PRATISE_BOARD_H


enum class Cell;

class Board
{
private:
    static constexpr int Size = 3;
    Cell cells[Size][Size];

public:
    Board();

    bool MakeMove(int row, int col, Cell symbol);
    bool IsFull() const;
    Cell CheckWinner() const;
    void Reset();
    void Print() const;

private:
    bool IsValidPosition(int r, int c) const;
};


#endif //DSA_PRATISE_BOARD_H
