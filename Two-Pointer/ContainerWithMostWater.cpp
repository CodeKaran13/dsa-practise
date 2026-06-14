//
// Copyright (c) 2026 CodeKaranGames.
// This source code is the property of CodeKaranGames.
// Unauthorized copying, modification, distribution, or use is prohibited.
//


#include <vector>

int maxArea(std::vector<int>& heights)
{
    int left = 0;
    int right = static_cast<int>(heights.size()) - 1;
    int maxArea = 0;
    while (left < right)
    {
        int width = right - left;
        int height = std::min(heights[left], heights[right]);
        int area = height * width;

        maxArea = std::max(maxArea, area);

        if (heights[left] < heights[right])
            left++;
        else
            right--;
    }
    return maxArea;
}
