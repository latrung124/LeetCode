#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int in1ex = 0;
        int ex1ex = 0;

        for (int i = 1; i < nums.size(); ++i) {
            int tempin = ex1ex + nums[i];
            int tempex = max(ex1ex, in1ex);

            in1ex = tempin;
            ex1ex = tempex;
            cout << "in1ex " << in1ex<< "ex1ex " << ex1ex<< endl;
        }

        int ans1 = max(in1ex, ex1ex);

        int in1in = nums[0];
        int ex1in = nums[0];


        for (int i = 2; i < nums.size(); ++i) {
            int tempin = ex1in + nums[i];
            int tempex = max(ex1in, in1in);

            in1in = tempin;
            ex1in = tempex;
        }

        int ans2 = ex1in;

        return max(ans1, ans2);



    }
};

//int main() {
//    Solution s;
//    vector<int> input = { 1,2,3,1 };
//    cout << s.rob(input) << endl;
//    return 0;
//}