//  Copyright (c) 2026 CodeKaranGames. All rights reserved.
//  This file contains original source code owned by CodeKaranGames.
//  Unauthorized copying, modification, distribution, or use is
//  prohibited unless explicitly permitted.
//

#include <vector>


int RemoveDuplicates(std::vector<int>& nums)
{
    if (nums.empty())
        return 0;

    int left = 0;
    for (int right = left + 1; right < nums.size(); right++)
    {
        if (nums[left] == nums[right])
            continue;

        nums[++left] = nums[right];
    }

    return left + 1;
}
