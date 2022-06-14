#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int i = nums.size();
        if (i == 0) return 0;
        else if (i == 1) return nums[0];
        else if (i == 2) return max(nums[1], nums[2]);
        vector<int> arrRob;
        //arrRob.push_back(nums[0]);
        //arrRob.push_back(nums[1]);
        int result = 0;
        while (i--) {
            int tmp = nums[i];
            int maxV = tmp;
            for (int j = arrRob.size() - 2; j >= 0; --j) {
                //cout <<"i: "<< i << " j: " << j << endl;
                 maxV = max(tmp + arrRob[j], maxV);                
            }
            result = max(maxV,result);
            //cout << "maxV: " << result << endl;
            arrRob.push_back(maxV);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> input = { 1,3,1 };
    cout << s.rob(input) << endl;
	return 0;
}