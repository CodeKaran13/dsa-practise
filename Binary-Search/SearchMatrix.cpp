//
// Copyright (c) 2026 CodeKaranGames.
// This source code is the property of CodeKaranGames.
// Unauthorized copying, modification, distribution, or use is prohibited.
//

#include <vector>


bool SearchMatrix(std::vector<std::vector<int>>& matrix, int target)
{
    int rows = static_cast<int>(matrix.size());
    int cols = static_cast<int>(matrix[0].size());

    int left = 0;
    int right = rows * cols - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        int row = mid / cols;
        int col = mid % cols;

        if (matrix[row][col] == target)
            return true;

        if (matrix[row][col] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}
