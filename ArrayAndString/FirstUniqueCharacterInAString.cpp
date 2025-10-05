#include <string>

class Solution {
public:
    int firstUniqChar(std::string s) {
        if (s.empty()) return -1;
        int countArr[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++countArr[(int)(s[i] - 'a')];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (countArr[(int)(s[i] - 'a')] == 1) return i;
        }
        return -1;
    }
};