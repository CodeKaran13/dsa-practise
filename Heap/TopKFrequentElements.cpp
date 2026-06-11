//
// Created by Karan Nandkar on 03-06-2026.
//

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> TopKFrequent(const vector<int>& nums, int k)
{
    unordered_map<int, int> freq;
    for (int num : nums)
        freq[num]++;

    using Pair = pair<int, int>;
    priority_queue<Pair, vector<Pair>, greater<Pair>> minHeap;

    for (const auto& pair : freq)
    {
        int num = pair.first;
        int count = pair.second;

        // emplace is optimized. push makes copy
        minHeap.push({count, num});

        if (minHeap.size() > k)
            minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}
