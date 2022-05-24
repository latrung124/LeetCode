#include <iostream>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        if (n == 1) return 5;
        else if (n == 0) return 0;
        else if (n == 2) return 15;
        int arr[5] = {5,4,3,2,1};
        int i = 3;
        int result = 0;        
        while (i <= n) {
            int dem = 5;
            int vitri = 0;
            while (dem > 0) {
                int tmp = 0;
                for (int j = vitri; j < 5; ++j) {
                    tmp += arr[j];
                }
                arr[vitri] = tmp;
                vitri++;
                dem--;
            }
            i++;
        }
        for (int m = 0; m < 5; ++m) {
            result += arr[m];
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.countVowelStrings(4) << endl;
	return 0;
}