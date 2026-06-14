//
// Copyright (c) 2026 CodeKaranGames.
// This source code is the property of CodeKaranGames.
// Unauthorized copying, modification, distribution, or use is prohibited.
//

#include <vector>
#include <algorithm>

std::vector<std::vector<int>> ThreeSum(std::vector<int>& nums)
{
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    int n = static_cast<int>(nums.size()) - 1;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0)
            {
                left++;
            }
            else if (sum > 0)
            {
                right--;
            }
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
        }
    }

    return result;
}
