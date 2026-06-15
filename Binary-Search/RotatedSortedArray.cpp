//
// Created by Karan Nandkar on 17-05-2026.
//

/**
 * Problem: Search in Rotated Sorted Array
 *
 * Given: [4,5,6,7,0,1,2]
 *
 * Target: 0
 *
 */


#include <vector>

int SearchInRotatedSortedArray(const std::vector<int>& nums, int target)
{
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right)
    {
        const int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half sorted
        if (nums[left] <= nums[mid])
        {
            // Check if target lies between left and mid
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else // Right half sorted
        {
            // Check if target lies between mid and right
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}
