//
// Created by Karan Nandkar on 10/06/26.
//

#include <vector>

using namespace std;

void DFS(vector<vector<int>>& image, int r, int c, int originalColor, int newColor)
{
    const int rows = static_cast<int>(image.size());
    const int cols = static_cast<int>(image[0].size());

    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    if (image[r][c] != originalColor)
        return;

    image[r][c] = newColor;

    DFS(image, r - 1, c, originalColor, newColor);
    DFS(image, r + 1, c, originalColor, newColor);
    DFS(image, r, c - 1, originalColor, newColor);
    DFS(image, r, c + 1, originalColor, newColor);
}

vector<vector<int>> FloodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    if (image.empty() || image[0].empty())
        return image;

    const int rows = static_cast<int>(image.size());
    const int cols = static_cast<int>(image[0].size());

    if (sr < 0 || sr >= rows || sc < 0 || sc >= cols)
        return {};

    const int originalColor = image[sr][sc];
    if (originalColor == newColor)
        return image;

    DFS(image, sr, sc, originalColor, newColor);

    return image;
}
