#include <vector>
#include <string>

class Solution {
public:
    int characterReplacement(const std::string& s, int k) {
        std::vector<int> count(26, 0);
        int maxCount = 0;
        int left = 0;
        int result = 0;
        for (int right = 0; right < s.size(); ++right) {
            int currentCharIndex = s[right] - 'A';
            ++count[currentCharIndex];
            maxCount = std::max(maxCount, count[currentCharIndex]);
            if (right - left + 1 - maxCount > k) {
                --count[s[left] - 'A'];
                ++left;
            }
            result = std::max(result, right - left + 1);
        }

        return result;
    }

};