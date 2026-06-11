//
// Created by Karan Nandkar on 03-06-2026.
//

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

bool canShip(const vector<int>& weights, int days, int capacity)
{
    int daysUsed = 1;
    int currentLoad = 0;

    for (const int weight : weights)
    {
        if (currentLoad + weight > capacity)
        {
            daysUsed++;
            currentLoad = 0;
        }
        currentLoad += weight;
    }
    return daysUsed <= days;
}

int shipWithinDays(const vector<int>& weights, int days)
{
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (canShip(weights, days, mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}