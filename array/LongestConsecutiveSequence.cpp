//
// Created by knand on 17-05-2026.
//


/**
 * Problem:
 * Given: [100,4,200,1,3,2]
 * Return: 4
 * Because longest consecutive sequence is: 1,2,3,4
 */


#include <unordered_set>
#include <vector>


int longestConsecutive(const std::vector<int>& nums)
{
    std::unordered_set<int> numSet(nums.begin(), nums.end());

    int longest = 0;

    for (int num : nums)
    {
        if (!numSet.count(num - 1))
        {
            int currentNum = num;
            int currentLength = 1;
            while (numSet.count(currentNum + 1))
            {
                currentNum++;
                currentLength++;
            }

            longest = std::max(longest, currentLength);
        }
    }

    return longest;
}
