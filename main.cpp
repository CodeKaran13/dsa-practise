#include <iostream>

std::vector<int> twoSum(const std::vector<int> &nums, int target);

bool isValid(const std::string &s);

bool isValidOptimized(const std::string &s);

int main()
{
	std::string s = "()[]{}";
	std::cout << std::boolalpha << isValidOptimized(s) << std::endl;
}
