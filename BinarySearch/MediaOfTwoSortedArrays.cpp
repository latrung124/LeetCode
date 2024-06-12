#include <bits/stdc++.h>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        std::sort(nums1.begin(), nums1.end());
        if (nums1.size()%2 == 0) {
            int middle = nums1.size()/2;
            return (double)(nums1[middle -1] + nums1[middle])/2;
        } else {
            int middle = nums1.size()/2;
            return nums1[middle];
        }
    }
};