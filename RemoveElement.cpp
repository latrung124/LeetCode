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
            if (nums.at(last) == nums.at(first)) {
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
    int removeElement(vector<int>& nums, int val) {
        int result = 0;
        if (nums.empty()) return result;
        int start = 0;
        int end = nums.size()-1;
        result = nums.size();
        if (result == 1) {
            if (nums.at(0) == val) {
                nums.erase(nums.begin() + start, nums.begin() + start + 1);
                return 0;
            }
            else return result;
        }
        while (start <= end) {
            if (start >= nums.size()) return result;
            if (nums.at(start) == val) {
                nums.erase(nums.begin() + start, nums.begin() + start + 1);
                result = nums.size();
                end = result - 1;
            }
            else {
                start++;
            }
            if (end < 0) return result;
            if (nums.at(end) == val) {
                nums.erase(nums.begin() + end, nums.begin() + end+1);
                result = nums.size();
                end = result - 1;
            }
            else {
                end--;
            }
        }
        return result;
    }
};
//int main() {
//    vector<int> v = { 3,3 };
//    Solution s;
//    cout << s.removeElement(v,3) << endl;
//    for (auto& n : v) {
//        cout << n << " ";
//    }
//    cout << endl;
//    return 0;
//}