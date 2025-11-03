#include <string>
#include <vector>

class Solution {
public:
    int minCost(std::string colors, std::vector<int>& neededTime) {
        if (colors.size() <= 1) return 0;
        int result = 0;
        int curr = 0;
        for (int i = 1; i < colors.size(); ++i) {
            int time1 = neededTime[curr];
            int time2 = neededTime[i];
            if (colors[curr] == colors[i]) {
                if (time2 > time1) {
                    result += time1;
                } else {
                    result += time2;
                    continue;
                }
            }
            curr = i;
        }
        return result;
    }
};