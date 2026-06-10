//
// Created by Karan Nandkar on 10/05/26.
//

/*
 * Problem: Daily Temperatures
 * Given: [73,74,75,71,69,72,76,73]
 * Return: [1,1,4,2,1,1,0,0]
 * Example:
 * 73 -> warmer temp at 74 next day
 * answer = 1
 *
 * 75 -> warmer temp at 76 after 4 days
 * answer = 4
 */

#include <stack>
#include <vector>

std::vector<int> dailyTemperatures(const std::vector<int> &temperatures)
{
	std::vector<int> result(temperatures.size(), 0);
	std::stack<int> st;

	for (int i = 0; i < temperatures.size(); i++)
	{
		while (!st.empty() && temperatures[i] > temperatures[st.top()])
		{
			int previousDay = st.top();
			st.pop();
			result[previousDay] = i - previousDay;
		}

		st.push(i);
	}

	return result;
}
