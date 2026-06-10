//
// Created by Karan Nandkar on 03-06-2026.
//

/**
 * Given:
 * grid =
 * [
 *   ['1','1','0','0'],
 *   ['1','0','0','1'],
 *   ['0','0','1','1']
 * ]
 *
 * Return number of islands
 *
 * An island is connected land '1' horizontally or vertically
 */


#include <vector>

using namespace std;

void DFS(vector<vector<char>>& grid, int r, int c)
{
    const int rows = static_cast<int>(grid.size());
    const int cols = static_cast<int>(grid[0].size());

    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    if (grid[r][c] != '1')
        return;

    grid[r][c] = '0';

    DFS(grid, r + 1, c);
    DFS(grid, r - 1, c);
    DFS(grid, r, c + 1);
    DFS(grid, r, c - 1);
}

int NumIslands(vector<vector<char>>& grid)
{
    if (grid.empty() || grid[0].empty())
        return 0;

    const int rows = static_cast<int>(grid.size());
    const int cols = static_cast<int>(grid[0].size());

    int islandCount = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == '1')
            {
                islandCount++;
                DFS(grid, r, c);
            }
        }
    }

    return islandCount;
}
