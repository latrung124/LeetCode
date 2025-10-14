#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stk;
        for (const auto c : s) {
            if (c == '[' || c == '{' || c == '(') {
                stk.push(c);
            } else {
                if (!stk.empty()) {
                    char temp = stk.top();
                    if (temp == '[' && c == ']') {
                        stk.pop();
                    } else if (temp == '{' && c == '}') {
                        stk.pop();
                    } else if (temp == '(' && c == ')') {
                        stk.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};