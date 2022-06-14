#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int arr[10003];
        memset(arr, 0, sizeof(arr));
        vector<int> m(10001, 0);
        for (auto& i : nums) {
            m[i] += i;
        }
        int j = 10001;
        while (j--) {
            arr[j] = max(m[j] + arr[j + 2], arr[j + 1]);
        }
        int result = arr[0];

        return result;
    }
};
int main() {
    Solution s;
    vector<int> input = { 8,3,4,7,6,6,9,2,5,8,2,4,9,5,9,1,5,7,1,4 };
    cout << s.deleteAndEarn(input) << endl;
	return 0;
}