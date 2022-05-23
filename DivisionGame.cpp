#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        bool result = false;
        if (n % 2 == 0) return true;
        else return false;
    }
};
//int main() {
//    Solution s;
//    cout << s.divisorGame(9) << endl;
//	return 0;
//}