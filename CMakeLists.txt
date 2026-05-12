cmake_minimum_required(VERSION 4.2)
project(dsa_pratise)

set(CMAKE_CXX_STANDARD 20)

add_executable(dsa_pratise main.cpp
        array/TwoSum.cpp
        array/ShortestSubArray.cpp
        array/LongestSubstring.cpp
        stack/ValidParentheses.cpp
        stack/DailyTemperature.cpp
        tree/TreeTraversal.cpp)
