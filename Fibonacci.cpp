#include <iostream>
#include <chrono>
using namespace std;
typedef long long ll;
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 2 || n == 1) return 1;
        int first = 1; //f1
        int second = first - 1;//f0
        for (int i = 2; i <= n; ++i) {
            first = first + second;
            second = first - second;
        }
        return first;
        /*return fib(n - 1) + fib(n - 2);*/
    }
};

//int main() {
//    Solution s;
//    auto start_time = std::chrono::high_resolution_clock::now();
//    cout << s.fib(6) << endl;
//    auto end_time = std::chrono::high_resolution_clock::now();
//    auto time = end_time - start_time;
//    cout << "took : " << time/std::chrono::milliseconds(1) << endl;
//	return 0;
//}