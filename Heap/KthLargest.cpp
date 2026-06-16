//
// Created by Karan Nandkar on 03-06-2026.
//


#include <queue>
#include <vector>

int FindKthLargest(const std::vector<int>& nums, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (int num : nums)
    {
        minHeap.push(num);
        if (minHeap.size() > k)
            minHeap.pop();
    }

    return minHeap.top();
}
