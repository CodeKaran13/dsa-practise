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

void dfs(vector<vector<char>>& grid, int r, int c)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    if (grid[r][c] != '1')
        return;

    grid[r][c] = '0';

    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}

int numIslands(vector<vector<char>>& grid)
{
    if (grid.empty())
        return 0;

    int rows = grid.size();
    int cols = grid[0].size();

    int islandCount = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == '1')
            {
                islandCount++;
                dfs(grid, r, c);
            }
        }
    }

    return islandCount;
}