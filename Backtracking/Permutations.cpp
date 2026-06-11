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

using namespace std;

void DFS(const vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result)
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
        DFS(nums, used, current, result);

        // Backtrack
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> Permutations(const vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);

    DFS(nums, used, current, result);

    return result;
}
