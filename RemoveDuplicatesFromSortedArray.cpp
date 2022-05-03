#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k = nums.size();
        if (nums.empty()) return 0;
        int last = 0;
        for (int first = 0; first < nums.size(); ++first) {
            last = first + 1;
            if (last >= nums.size()) return k;
            if (nums.at(last) == nums.at(first) ) {               
                nums.erase(nums.begin() + last, nums.begin() + last + 1);
                k = nums.size();
                first--;
            }
            else {
                //do nothing
            }
        }
        return k;
    }
};
//int main() {
//    vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
//    Solution s;
//    cout << s.removeDuplicates(v) << endl;
//    for (auto& n : v) {
//        cout << n << " ";
//    }
//    cout << endl;
//    return 0;
//}