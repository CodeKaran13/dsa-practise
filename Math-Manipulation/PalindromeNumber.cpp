//
// Created by Karan Nandkar on 10/06/26.
//


bool IsPalindrome(int x)
{
    if (x < 0)
        return false;

    if (x != 0 && x % 10 == 0)
        return false;

    int reversedHalf = 0;
    while (x > reversedHalf)
    {
        const int digit = x % 10;
        reversedHalf = reversedHalf * 10 + digit;
        x /= 10;
    }
    return x == reversedHalf || x == reversedHalf / 10;
}
