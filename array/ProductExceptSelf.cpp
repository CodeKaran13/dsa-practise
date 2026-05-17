//
// Created by Karan Nandkar on 14/05/26.
//


/**
 * Prefix / Suffix Product
 *
 * Given: nums = [1,2,3,4]
 *
 * Return: [24,12,8,6]
 *
 * Explanation:
 * 24 = 2*3*4
 * 12 = 1*3*4
 * 8  = 1*2*4
 * 6  = 1*2*3
 *
 * Prefix Product: []
 */


#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums)
{
    int n = nums.size();

    std::vector<int> result(n, 1);

    // Prefix products
    for (int i = 1; i < n; i++)
    {
        result[i] = result[i - 1] * nums[i - 1];
    }

    // Suffix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}
