//
// Created by Karan Nandkar on 09/05/26.
//

/*
 * Problem: Find the length of the LONGEST substring without repeating characters.
 *
 * Given a string:
 * "abcabcbb"
 *
 * Answer:
 * 3
 *
 * Because: "abc"
 */

#include <string>
#include <unordered_map>
#include <unordered_set>

int LengthOfLongestSubstring(const std::string& s)
{
    std::unordered_set<char> seen;
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.size(); right++)
    {
        char c = s[right];
        while (seen.contains(c))
        {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(c);
        maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
}

int LengthOfLongestSubstringOptimized(const std::string& s)
{
    std::unordered_map<char, int> lastSeen;
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.size(); right++)
    {
        char c = s[right];
        if (lastSeen.find(c) != lastSeen.end())
        {
            left = std::max(left, lastSeen[c] + 1);
        }
        lastSeen[c] = right;
        maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
}
