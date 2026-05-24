cmake_minimum_required(VERSION 4.2)
project(dsa_pratise)

set(CMAKE_CXX_STANDARD 20)

add_executable(dsa_pratise main.cpp
        array/TwoSum.cpp
        array/ShortestSubArray.cpp
        string/LongestSubstring.cpp
        stack/ValidParentheses.cpp
        stack/DailyTemperature.cpp
        tree/TreeTraversal.cpp
        tree/ValidBST.cpp
        tree/BFS.cpp
        graph/NumberOfIslands.cpp
        array/ContainsDuplicate.cpp
        string/ValidAnagram.cpp
        string/GroupAnagram.cpp
        array/ProductExceptSelf.cpp
        array/LongestConsecutiveSequence.cpp
        binary-search/RotatedSortedArray.cpp
        binary-search/FindMinimum.cpp
        binary-search/KokoEatingBananas.cpp
        backtracking/Subset.cpp
        backtracking/Permutations.cpp
        raii/File.cpp
        raii/Buffer.cpp)
