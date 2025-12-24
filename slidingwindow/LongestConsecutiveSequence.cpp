#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());

        int result = 0;
        for (int num : set) {
            if (!set.contains(num - 1)) {
                int curr = 0;
                int index = num;
                while (set.contains(index)) {
                    ++index;
                    ++curr;
                }
                result = std::max(curr, result);
            }
        }
        return result;
    }
};