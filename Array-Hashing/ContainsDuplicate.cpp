//
// Created by Karan Nandkar on 14/05/26.
//

#include <unordered_set>
#include <vector>

bool ContainsDuplicate(const std::vector<int>& nums)
{
    std::unordered_set<int> seen;
    for (int num : nums)
    {
        if (seen.contains(num))
            return true;

        seen.insert(num);
    }

    return false;
}

/// If array is sorted
bool containsDuplicateSorted(const std::vector<int>& nums)
{
    for (int i = 1; i < nums.size(); i++)
        if (nums[i] == nums[i - 1])
            return true;

    return false;
}
