//
// Created by Karan Nandkar on 20/05/26.
//

/**
 * Problem: Permutations
 *
 * Given: [1,2,3]
 *
 * Return all permutations:
 * [1,2,3]
 * [1,3,2]
 * [2,1,3]
 * [2,3,1]
 * [3,1,2]
 * [3,2,1]
 */

#include <vector>

void dfs(const std::vector<int>& nums, std::vector<bool>& used, std::vector<int>& current, std::vector<std::vector<int>>& result)
{
    // Complete permutation formed
    if (current.size() == nums.size())
    {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        // Skip already used elements
        if (used[i])
        {
            continue;
        }

        // Choose
        used[i] = true;
        current.push_back(nums[i]);

        // Explore
        dfs(nums, used, current, result);

        // Backtrack
        current.pop_back();
        used[i] = false;
    }
}

std::vector<std::vector<int>> permutations(const std::vector<int>& nums)
{
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    std::vector<bool> used(nums.size(), false);

    dfs(nums, used, current, result);

    return result;
}
