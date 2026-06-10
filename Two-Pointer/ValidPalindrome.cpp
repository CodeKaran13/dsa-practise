//
// Created by Karan Nandkar on 10/06/26.
//

#include <string>
#include <cctype>

bool isPalindrome(const std::string& s)
{
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;

    while (left < right)
    {
        while (left < right && !std::isalnum(s[left]))
            left++;
        while (left < right && !std::isalnum(s[right]))
            right--;

        if (std::tolower(s[left]) != std::tolower(s[right]))
            return false;

        left++;
        right--;
    }

    return true;
}


// custom helper methods
bool IsAlphaNumeric(const char& c)
{
    return (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9');
}

char ToLower(const char& c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }

    return c;
}
