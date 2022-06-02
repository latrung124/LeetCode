#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        size_t i = prices.size();
        if (i == 0 || i == 1) return 0;
        int m = prices[0];
        int b = prices[1];
        result = b - m;
        int j = 0;
        while (j < i) {
            if (prices[j] < m) {
                m = prices[j];
                b = j+1 < i ? prices[j + 1] : prices[j];
                result = max(result, b - m);
            }
            else {
                result = max(result, prices[j] - m);
                b = j;
            }
            j++;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = {};
    cout << s.maxProfit(v);
	return 0;
}