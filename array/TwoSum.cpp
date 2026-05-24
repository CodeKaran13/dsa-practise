//
// Created by Karan Nandkar on 09/05/26.
//

/*
 * TWO SUM
* Giver:
* nums = [2,7,11,15]
* target = 9
* Return indices of two numbers adding to the target.
* Answer:
* [0,1]
 */

#include <unordered_map>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> seenNumbers;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        auto it = seenNumbers.find(complement);
        if (it != seenNumbers.end())
        {
            return {it->second, i};
        }
        seenNumbers[nums[i]] = i;
    }
    return {};
}

std::vector<int> twoSumOptimized(const std::vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            return {left, right};
        }

        if (sum > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return {};
}
