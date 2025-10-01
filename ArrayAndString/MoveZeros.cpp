#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos1 = 0; // track new array without zero
        int pos2 = 0; // track array
        for (int pos2 = 0; pos2 < nums.size(); ++pos2) {
            if (nums[pos2] != 0) {
                nums[pos1] = nums[pos2];
                ++pos1;
            }
        }
        for (int i = pos1; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};