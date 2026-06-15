//
// Created by Karan Nandkar on 10/06/26.
//

/**
 * Given:
 * nums1 = [1,2,2,1]
 * nums2 = [2,2]
 *
 * Return:
 * [2]
 *
 * Example:
 * nums1 = [4,9,5]
 * nums2 = [9,4,9,8,4]
 *
 * Output:
 * [9,4]
 */

#include <unordered_set>
#include <unordered_map>
#include <vector>

std::vector<int> Intersection(const std::vector<int>& nums1, const std::vector<int>& nums2)
{
    std::unordered_set<int> set(nums1.begin(), nums1.end());
    std::unordered_set<int> resultSet;

    for (int num : nums2)
        if (set.count(num))
            resultSet.insert(num);

    return {resultSet.begin(), resultSet.end()};
}

// If duplicates must be preserved
std::vector<int> IntersectionPreserveDuplicates(const std::vector<int>& nums1, const std::vector<int>& nums2)
{
    std::unordered_map<int, int> freq;
    for (int num : nums1)
        freq[num]++;

    std::vector<int> result;
    for (int num : nums2)
    {
        if (freq[num] > 0)
        {
            result.push_back(num);
            freq[num]--;
        }
    }

    return result;
}
