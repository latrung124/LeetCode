#include <cmath>

class Solution {
public:
    int smallestNumber(int n) {
        if (n <= 0) return n;

        int msbIndex = static_cast<int>(std::floor(std::log2(n)));
        return (int)((1 << (msbIndex + 1)) - 1);
    }
};