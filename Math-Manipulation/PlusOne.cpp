//
// Created by Karan Nandkar on 10/06/26.
//


#include <vector>


std::vector<int> PlusOne(std::vector<int>& digits)
{
    const int n = static_cast<int>(digits.size());
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits;
        }
    }

    digits.insert(digits.begin(), 1);
    return digits;
}
