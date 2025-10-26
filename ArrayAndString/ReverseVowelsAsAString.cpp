#include <string>
#include <unordered_set>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        std::unordered_set<char> vowels;
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            int leftCount = vowels.count(s[left]);
            int rightCount = vowels.count(s[right]);
            if (leftCount&& rightCount) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
            } else if (leftCount && !rightCount) {
                --right;
                continue;
            } else if (rightCount && !leftCount) {
                ++left;
                continue;
            }
            --right;
            ++left;
        }
        return s;
    }
};