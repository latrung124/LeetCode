#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> getSneakyNumbers(std::vector<int>& nums) {
        if (nums.empty()) return {};
        std::sort(nums.begin(), nums.end());
        std::vector<int> result;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                result.emplace_back(nums[i]);
            }
        }
        return result;
    }
};