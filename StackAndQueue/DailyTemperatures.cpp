#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        size_t size = temperatures.size();
        std::vector<int> result(size, 0);
        std::stack<int> stack;
        for (int i = 0; i < size; ++i) {
            int temp = temperatures[i];
            while (!stack.empty() && temp > temperatures[stack.top()]) {
                int topIndex = stack.top();
                result[topIndex] = i - topIndex;
                stack.pop();
            }
            stack.push(i);
        }
        return result;
    }
};