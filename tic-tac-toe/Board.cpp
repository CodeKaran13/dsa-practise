//
// Created by Karan Nandkar on 01/06/26.
//

#include "Board.h"

#include <algorithm>
#include <iostream>

#include "Cell.h"

Board::Board()
{
    Reset();
}

bool Board::MakeMove(int row, int col, Cell symbol)
{
    if (!IsValidPosition(row, col))
        return false;

    if (cells[row][col] != Cell::Empty)
        return false;

    cells[row][col] = symbol;
}

bool Board::IsFull() const
{
    for (int row = 0; row < Size; row++)
    {
        for (int col = 0; col < Size; col++)
        {
            if (cells[row][col] == Cell::Empty)
                return false;
        }
    }

    return true;
}

Cell Board::CheckWinner() const
{
    // check all rows
    for (int r = 0; r < 3; r++)
    {
        if (cells[r][0] != Cell::Empty &&
            cells[r][0] == cells[r][1] &&
            cells[r][1] == cells[r][2])
        {
            return cells[r][0];
        }
    }

    // check all cols
    for (int c = 0; c < 3; c++)
    {
        if (cells[0][c] != Cell::Empty &&
            cells[0][c] == cells[1][c] &&
            cells[1][c] == cells[2][c])
        {
            return cells[0][c];
        }
    }

    // check both diagonals
    if (cells[0][0] != Cell::Empty &&
        cells[0][0] == cells[1][1] &&
        cells[1][1] == cells[2][2])
    {
        return cells[0][0];
    }

    if (cells[0][2] != Cell::Empty &&
        cells[0][2] == cells[1][1] &&
        cells[1][1] == cells[2][0])
    {
        return cells[0][2];
    }

    return Cell::Empty;
}

void Board::Reset()
{
    for (int r = 0; r < Size; r++)
    {
        for (int c = 0; c < Size; c++)
        {
            cells[r][c] = Cell::Empty;
        }
    }
}

void Board::Print() const
{
    for (int row = 0; row < Size; row++)
    {
        for (int col = 0; col < Size; col++)
        {
            char symbol = '.';
            if (cells[row][col] == Cell::X)
                symbol = 'X';
            else if (cells[row][col] == Cell::O)
                symbol = 'O';

            std::cout << symbol << " ";
        }
        std::cout << "\n";
    }
}

bool Board::IsValidPosition(int r, int c) const
{
    return r >= 0 && r < Size && c >= 0 && c < Size;
}
