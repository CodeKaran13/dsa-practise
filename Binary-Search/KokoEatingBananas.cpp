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


#include <vector>

bool canFinish(const std::vector<int>& piles, int speed, int h)
{
    long long hoursNeeded = 0;
    for (int bananas : piles)
    {
        hoursNeeded += std::ceil((double)bananas / speed);
    }

    return hoursNeeded <= h;
}

int minEatingSpeed(const std::vector<int>& piles, int speed, int h)
{
    int left = 1;
    int right = *std::max_element(piles.begin(), piles.end());

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (canFinish(piles, mid, h))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}
