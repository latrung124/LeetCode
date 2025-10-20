#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> setNums(nums.begin(), nums.end());
        return setNums.size() != nums.size();
    }
};