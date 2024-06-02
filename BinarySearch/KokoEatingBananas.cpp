#include <bits/stdc++.h>

class Solution {
public:
    // n piles of bananas, piles = [3, 6, 7, 11]
    // h hours to eat all bananas, h = 8
    // k bananas per hour
    // return the minimum integer k such that you can eat all the bananas within h hours
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        auto canEatAll = [&](int k, std::vector<int>& piles, int h) {
            int hours = 0;
            for (auto& it : piles) {
                hours += it/k + (it%k > 0 ? 1 : 0);
                if (hours > h) {
                    return false;
                }
            }
            return true;
        };
        int minimumK = right;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEatAll(mid, piles, h)) {
                right = mid;
                minimumK = std::min(minimumK, mid);
            } else {
                left = mid + 1;
            }
        }
        return minimumK;       
    }
};