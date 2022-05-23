//Title
//You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
// Once you pay the cost, you can either climb one or two steps.
//You can either start from the step with index 0, or the step with index 1.
//Return the minimum cost to reach the top of the floor.
// 
// Example:
//Input: cost = [10, 15, 20]
//Output : 15
//Explanation : You will start at index 1.
//- Pay 15 and climb two steps to reach the top.
//The total cost is 15.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int result = 0;
        size_t s = cost.size();
        if (s == 0) return 0;
        else if (s == 1) return cost.at(0);
        int tmp = s;
        int firstStep = 0;
        int secondStep = 0;
        while (tmp > 0) {
            if (tmp == s) {
                firstStep = cost[tmp - 1];
                secondStep = 0;
            }
            else if (tmp == s - 1) {
                int temp = firstStep;
                firstStep = cost[tmp - 1];
                secondStep = temp;
            }
            else {
                int minN = firstStep > secondStep ? secondStep : firstStep;
                secondStep = firstStep;
                firstStep = cost[tmp - 1] + minN;
            }
            --tmp;
        }
        return firstStep > secondStep ? secondStep : firstStep;
    }
};

//int main() {
//    Solution s;
//    vector<int> r = { 1,100,1,1,1,100,1,1,100,1 };
//    cout << s.minCostClimbingStairs(r) << endl;
//	return 0;
//}