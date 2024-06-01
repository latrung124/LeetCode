#include <bits/stdc++.h>
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        // std::sort(nums.begin(), nums.end());
        int  left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int middle = (right - left)/2 + left;
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else return middle;
        }
        return -1;
    }
};