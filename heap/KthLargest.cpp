//
// Created by Karan Nandkar on 03-06-2026.
//


#include <queue>
#include <vector>

using namespace std;

int findKthLargest(const vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums)
    {
        minHeap.push(num);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    return minHeap.top();
}
