#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s) {
        int left = 0;
        int maxLen = 0;
        std::unordered_set<char> charSet;

        for (int right = 0; right < s.size(); ++right) {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                ++left;
            }
            charSet.insert(s[right]);
            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};