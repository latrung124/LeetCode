#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string result;
        std::stringstream ss(s);
        std::string temp;
        while (ss >> temp) {
            std::reverse(temp.begin(), temp.end());
            result += temp + " "; // remember this operation, this would take so much overhead if we separate the " " to next line.
        }
        result.pop_back();
        return result;
    }
};