#include <string>
#include <cmath>

using namespace std;

class Solution {
    public:
        int titleToNumber(string columnTitle) {
            int result = 0;
            for (int i = 0; i < columnTitle.size(); ++i) {
                int t = columnTitle[i] - 'A' + 1;
                result += t * (pow(26, columnTitle.size() - i - 1));
            }
            return result;
        }
};