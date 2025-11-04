#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> findXSum(std::vector<int>& nums, int k, int x) {
        if (nums.empty()) return {};
        std::vector<int> result;
        size_t size = nums.size() - k;
        result.reserve(size);
        for (int i = 0; i <= size; ++i) {
            std::unordered_map<int, int> freq;
            for (int j = i; j < i + k; ++j) {
                ++freq[nums[j]];
            }
            std::vector<std::pair<int, int>> elements(freq.begin(), freq.end());
            std::sort(elements.begin(), elements.end(), [] (auto& a, auto& b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            int sum = 0;
            for (int m = 0; m < x && m < elements.size(); ++m) {
                sum += elements[m].first * elements[m].second;
            }
            result.push_back(sum);
        }
        return result;
    }
};