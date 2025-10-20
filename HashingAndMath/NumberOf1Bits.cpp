#include <bitset>

class Solution {
public:
    int hammingWeight(int n) {
        std::bitset<32> bitset(n);
        return bitset.count();
    }
};