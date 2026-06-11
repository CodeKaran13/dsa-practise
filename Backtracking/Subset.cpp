//
// Created by Karan Nandkar on 18/05/26.
//

/**
 * Problem: Generate all Subsets
 *
 * Given: [1,2,3]
 *
 * Return All subsets:
 * []
 * [1]
 * [2]
 * [3]
 * [1,2]
 * [1,3]
 * [2,3]
 * [1,2,3]
 */


#include <vector>

void DFS(int index, const std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result)
{
    if (index == nums.size())
    {
        result.push_back(current);
        return;
    }

    // Include nums[index]
    current.push_back(nums[index]);
    DFS(index + 1, nums, current, result);

    // Backtrack: undo include
    current.pop_back();

    // Exclude nums[index]
    DFS(index + 1, nums, current, result);
}

std::vector<std::vector<int>> Subsets(const std::vector<int>& nums)
{
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    DFS(0, nums, current, result);

    return result;
}
