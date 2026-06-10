//
// Created by Karan Nandkar on 10/06/26.
//

/**
 * Given:
 * nums = [1,1,1]
 * k = 2
 *
 * Return:
 * 2
 *
 * Because:
 * [1,1]  // index 0-1
 * [1,1]  // index 1-2
 *
 * NOTE: Sum should be of contiguous elements.
 */

#include <unordered_map>
#include <vector>

// return subarray
std::vector<int> SubarraySum(const std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> prefixIndexMap;
    prefixIndexMap[0] = -1;

    int prefixSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        int neededPrefix = prefixSum - k;
        if (prefixIndexMap.count(neededPrefix))
        {
            int start = prefixIndexMap[neededPrefix] + 1;
            int end = i;

            return {start, end};
        }

        prefixIndexMap[prefixSum] = i;
    }

    return {};
}

// count all subarrays
int SubarraySumCount(const std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;

    int prefixSum = 0;
    int count = 0;
    for (const int num : nums)
    {
        prefixSum += num;
        int neededPrefix = prefixSum - k;
        if (prefixCount.count(neededPrefix))
        {
            count += prefixCount[neededPrefix];
        }

        prefixCount[prefixSum]++;
    }

    return count;
}
