#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxAvg = 0;
        int currentTracking = 0;
        for (int i = 0; i < k; ++i) {
            maxAvg += nums[i];
        }

        currentTracking = maxAvg;
        for (int i = k; i < nums.size(); ++i) {
            currentTracking += nums[i];
            currentTracking -= nums[i - k];
            maxAvg = std::max(currentTracking, maxAvg);
        }

        return (double)maxAvg/k;
    }
};