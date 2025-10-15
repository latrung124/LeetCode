#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> map;
        std::stack<int> stack;
        for (const int num : nums2) {
            while (!stack.empty() && num > stack.top()) {
                map[stack.top()] = num;
                stack.pop();
            }
            stack.push(num);
        }

        std::vector<int> result;
        result.reserve(nums1.size());
        for (const int num : nums1) {
            if (int nextGreater = map[num]; nextGreater) {
                result.push_back(nextGreater);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};