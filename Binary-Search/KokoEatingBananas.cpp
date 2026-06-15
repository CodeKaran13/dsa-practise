//
// Created by Karan Nandkar on 18/05/26.
//


/**
 * Problem: Koko Eating Bananas
 *
 * Given: Koko has banana piles
 * [3,6,7,11]
 *
 * Hours available: h = 8
 *
 * Find minimum k bananas / hour speed.
 *
 */


#include <algorithm>
#include <cmath>
#include <vector>

bool CanFinish(const std::vector<int>& piles, int speed, int h)
{
    long long hoursNeeded = 0;
    for (const int bananas : piles)
    {
        hoursNeeded += std::ceil(static_cast<double>(bananas) / speed);
    }

    return hoursNeeded <= h;
}

int MinEatingSpeed(const std::vector<int>& piles, int speed, int h)
{
    int left = 1;
    int right = *std::max_element(piles.begin(), piles.end());

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (CanFinish(piles, mid, h))
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}