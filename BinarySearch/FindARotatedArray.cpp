#include <bits/stdc++.h>

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = 5000;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                result = std::min(result, nums[right]);
                left = mid + 1;
            } else {
                result = std::min(result, nums[mid]);
                right = mid - 1;
            }
        }
        return result;
    }
};