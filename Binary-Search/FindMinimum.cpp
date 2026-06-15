//
// Created by Karan Nandkar on 18-05-2026.
//


/**
 * Problem: Find Minimum in Rotated Sorted Array
 *
 * Given: [4,5,6,7,0,1,2]
 *
 * Return: 0
 */

#include <vector>

int FindMinimum(const std::vector<int>& nums)
{
    int left = 0;
    int right = static_cast<int>(nums.size());

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }

    return nums[left];
}
