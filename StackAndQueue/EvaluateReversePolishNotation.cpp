#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> nums;
        for (const auto& token : tokens) {
            if (token == "*" || token == "/" || token == "-" || token == "+") {
                int first = nums.top();
                nums.pop();
                int second = nums.top();
                nums.pop();
                if (token == "*") {
                   nums.push(second * first);
                } else if (token == "/") {
                    nums.push(second / first);
                } else if (token == "-") {
                    nums.push(second - first);
                } else if (token == "+") {
                    nums.push(second + first);
                }
            } else {
                nums.push(std::stoi(token));
            }
        }
        return nums.top();
    }
};