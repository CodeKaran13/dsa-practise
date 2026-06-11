//  Copyright (c) 2026 CodeKaranGames. All rights reserved.
//  This file contains original source code owned by CodeKaranGames.
//  Unauthorized copying, modification, distribution, or use is
//  prohibited unless explicitly permitted.
//


/**
 * Given a sorted array:
 * nums = [1,3,5,6]
 * target = 2
 *
 * Return 1
 */

#include <vector>


int SearchInsertPosition(const std::vector<int>& nums, int target)
{
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right)
    {
        const int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}
