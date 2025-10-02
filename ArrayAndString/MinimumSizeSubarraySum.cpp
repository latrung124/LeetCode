#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        long long sum = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                minLength = std::min(minLength, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};