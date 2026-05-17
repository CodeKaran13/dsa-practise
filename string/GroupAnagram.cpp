//
// Created by Karan Nandkar on 14/05/26.
//


/**
 * Input: ["eat","tea","tan","ate","nat","bat"]
 *
 * Expected Output:
 * [
 *   ["eat","tea","ate"],
 *   ["tan","nat"],
 *   ["bat"]
 * ]
 */


#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> group;

    for (const std::string& word : strs)
    {
        std::string key = word;
        std::sort(key.begin(), key.end());

        group[key].push_back(word);
    }

    std::vector<std::vector<std::string>> result;
    for (auto& pair : group)
    {
        result.reserve(group.size());
        result.push_back(pair.second);
    }

    return result;
}
