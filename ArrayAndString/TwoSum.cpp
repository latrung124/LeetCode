#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        std::unordered_map<int, int> posMap;

        for (int i = 0; i < size; ++i) {
            int num = nums[i];
            int minusNum = target - num;
            const auto it = posMap.find(minusNum);
            if (it != posMap.end()) {
                if (i == posMap[minusNum]) continue;
                return {i, posMap[minusNum]};
            }
            posMap[num] = i;
        }

        return {0, 0};
    }
};