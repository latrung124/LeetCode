#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        size_t size = nums.size() / 2;
        for (auto num : nums) {
            if (map[num] < size) {
                ++map[num];
            } else return num;
        }
        return -1;
    }
};