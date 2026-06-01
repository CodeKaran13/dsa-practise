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
        raii/Buffer.cpp
        fundamentals/DynamicArray.cpp
        weapon-system/Weapon.cpp
        weapon-system/Weapon.h
        weapon-system/Pistol.cpp
        weapon-system/Pistol.h
        weapon-system/Shotgun.cpp
        weapon-system/Shotgun.h
        weapon-system/RocketLauncher.cpp
        weapon-system/RocketLauncher.h
        weapon-system/WeaponFactory.cpp
        weapon-system/WeaponFactory.h
        weapon-system/Player.cpp
        weapon-system/Player.h
        move-a-to-b/Vector.cpp
        move-a-to-b/Vector.h
        ability-system/Ability.cpp
        ability-system/Ability.h
        tic-tac-toe/Cell.cpp
        tic-tac-toe/Cell.h
        tic-tac-toe/Board.cpp
        tic-tac-toe/Board.h
        tic-tac-toe/Player.cpp
        tic-tac-toe/Player.h
        tic-tac-toe/Game.cpp
        tic-tac-toe/Game.h
)
