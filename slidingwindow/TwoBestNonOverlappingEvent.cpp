#include <vector>
#include <algorithm>

class Solution {
public:
    int maxTwoEvents(std::vector<std::vector<int>>& events) {
        size_t size = events.size();
        
        //sort event by start time        
        std::sort(events.begin(), events.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        std::vector<int> dp(size, 0);
        dp[size - 1] = events[size - 1][2];
        for (int i = size - 2; i >= 0; --i) {
            dp[i] = std::max(dp[i + 1], events[i][2]);
        }

        int maxVal = 0;
        for (size_t i = 0; i < size; ++i) {
            int left = i + 1;
            int right = size - 1;
            int nextIndex = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (nextIndex != -1) {
                maxVal = std::max(maxVal, events[i][2] + dp[nextIndex]);
            } else {
                maxVal = std::max(maxVal, events[i][2]);
            }
        }
        return maxVal;
    }
};