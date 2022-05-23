#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (n == 2) return 1;
        int T1 = 1;
        int T2 = 1;
        int T3 = 2;
        for (int i = 4; i <= n; ++i) {
            int tmp = T3;
            T3 = T1 + T2 + T3;
            T2 = tmp;
            T1 = T3 - T1 - tmp;
//            cout << T1 << T2 << T3 << endl;
        }
        return T3;
    }
};

//int main() {
//    Solution s;
//    cout << s.tribonacci(5) << endl;
//    return 0;
//}
