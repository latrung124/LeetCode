#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        std::sort(happiness.begin(), happiness.end(), std::greater<int>());
        long long result = 0;
        for (int i = 0; i < k; ++i) {
            long long temp = happiness[i] - i;
            if (temp <= 0) return result;
            result += temp;
        }
        return result;
    }
};