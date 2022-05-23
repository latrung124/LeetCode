#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //moi diem deu ke voi 1 va 2
    int climbStairs(int n) {
        if(n == 0) return 0;
        else if (n == 1) return 1;
        int tmp = n;
        int first = 0;
        int second = 0;
        while(tmp >= 0) {
            if (tmp == n) {
                first = 1;
            } else if (tmp == n-1) {
                second = 1;
            } else {
                int tmp = first;
                first = first + second;
                second = tmp;
            }
            tmp--;
        }
        return first;
    }
};
//Input: n = 3
//Output: 3
//Explanation: There are three ways to climb to the top.
//1. 1 step + 1 step + 1 step
//2. 1 step + 2 steps
//3. 2 steps + 1 step
int main() {
    Solution s;
    cout << s.climbStairs(5) << endl;
    return 0;
}
