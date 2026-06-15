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

using namespace std;

vector<vector<string>> GroupAnagrams(const vector<string>& strs)
{
    unordered_map<string, vector<string>> group;
    for (const string& word : strs)
    {
        string key = word;
        sort(key.begin(), key.end());
        group[key].emplace_back(word);
    }

    vector<vector<string>> result;
    for (auto& pair : group)
        result.emplace_back(pair.second);

    return result;
}
