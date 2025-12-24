#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) return false;
        
        std::vector<int> freqS1(26, 0);
        for (auto c : s1) {
            ++freqS1[c - 'a'];
        }

        size_t s1Size = s1.size();
        std::vector<int> currFreq(26, 0);
        for (int i = 0; i < s1Size; ++i) {
            ++currFreq[s2[i] - 'a'];
        }

        if (freqS1 == currFreq) return true;

        for (int right = s1Size; right < s2.size(); ++right) {
            --currFreq[s2[right - s1Size] - 'a'];
            ++currFreq[s2[right] - 'a'];
            if (freqS1 == currFreq) return true;
        }
        return false;
    }
};