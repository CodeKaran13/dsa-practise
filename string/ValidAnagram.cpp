//
// Created by Karan Nandkar on 14/05/26.
//

/**
 * Given:
 * s = "anagram"
 * t = "nagaram"
 *
 * Return: true
 */


/*
 * Assuming string contains all lowercase English letters
 */

#include <string>

bool isAnagram(const std::string& s, const std::string& t)
{
    if (s.size() != t.size())
    {
        return false;
    }

    int frequency[26] = {0};

    for (char c : s)
    {
        frequency[c - 'a']++;
    }

    for (char c : t)
    {
        frequency[c - 'a']--;
    }

    for (int count : frequency)
    {
        if (count != 0)
        {
            return false;
        }
    }

    return true;
}
