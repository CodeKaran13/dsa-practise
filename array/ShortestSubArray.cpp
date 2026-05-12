//
// Created by Karan Nandkar on 09/05/26.
//


/*
 * Problem:
 * Given:
 * nums = [2,3,1,2,4,3]
 * target = 7
 * Find the MINIMUM LENGTH subarray whose sum is >= target.
 * Answer:
 * 2
 */


#include <vector>

int shortestSubArray(const std::vector<int> &nums, int target)
{
	int left = 0;
	int sum = 0;
	int minLength = INT_MAX;

	for (int right = 0; right < nums.size(); right++)
	{
		sum += nums[right];
		while (sum >= target)
		{
			minLength = std::min(minLength, right - left + 1);
			sum -= nums[left];
			left++;
		}
	}

	return minLength == INT_MAX ? 0 : minLength;
}
