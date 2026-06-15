//
// Created by Karan Nandkar on 03-06-2026.
//


/**
 * Capacity to ship packages
 */

#include <algorithm>
#include <numeric>
#include <vector>

bool CanShip(const std::vector<int>& weights, int days, int capacity)
{
    int daysUsed = 1;
    int currentLoad = 0;

    for (int weight : weights)
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

int ShipWithinDays(const std::vector<int>& weights, int days)
{
    // left is max package weight because that should be minimum capacity to ship in 1 day
    int left = *std::max_element(weights.begin(), weights.end());
    int right = std::accumulate(weights.begin(), weights.end(), 0);

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (CanShip(weights, days, mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}
