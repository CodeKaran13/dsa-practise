//
// Created by Karan Nandkar on 03-06-2026.
//

#include <queue>
#include <unordered_map>
#include <vector>


std::vector<int> TopKFrequent(const std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> freq;
    for (int num : nums)
        freq[num]++;

    using Pair = std::pair<int, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> minHeap;

    for (const auto& pair : freq)
    {
        int num = pair.first;
        int count = pair.second;

        // emplace is optimized. push makes copy
        minHeap.push({count, num});

        if (minHeap.size() > k)
            minHeap.pop();
    }

    std::vector<int> result;
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}
