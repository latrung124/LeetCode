#include <bits/stdc++.h>

using namespace std;
//Description:
// Given an array of integers temperatures represents the daily temperatures,
//  return an array answer such that answer[i] is the number of days 
// you have to wait after the ith day to get a warmer temperature. 
// If there is no future day for which this is possible, keep answer[i] == 0 instead.
// 
//Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1, 1, 4, 2, 1, 1, 0, 0]
// 
//Example 2:
//Input: temperatures = [30, 40, 50, 60]
//Output : [1, 1, 1, 0]

class Solution {
public:
//Solution 1: brute force// time limited exceed
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        vector<int> result;
//        if (temperatures.empty()) return result;
//        int start = 0;
//        int second = 1;
//        for (int i = 1; i < temperatures.size() && start < temperatures.size(); ++i) {
//            if (temperatures.at(start) < temperatures.at(i)) {
//                result.push_back(i - start);
//                start = start+1;
//                i = start;
//            } else {
//                if (i == temperatures.size() - 1) {
//                    result.push_back(0);
//                    start = start + 1;
//                    i = start;
//                }
//            }
//        }
//        result.push_back(0);
//        return result;
//    }

//Solution 2:// stack // time limited exceed
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int current = temperatures.size();
        if (!current) return {};
        else if (current == 1) return  {0};
        stack<int> st;
        vector<int> result(current,0);
        while (current --) {
            while(!st.empty() && temperatures.at(current) >= temperatures.at(st.top())) {
                st.pop();
            }
            if (st.empty()) result[current] = 0;
            else {
                result[current] = st.top() - current;
            }
            st.push(current);
        }
        return result;
    }
    //native
//    vector<int> dailyTemperatures(vector<int>& T)
//    {
//        int n = T.size();

//        // To store the answer
//        vector<int> daysOfWait(n, 0);
//        stack<int> s;

//        // Traverse all the temperatures
//        for (int i = 0; i < n; i++) {

//            // Check if current index is the
//            // next warmer temperature of
//            // any previous indexes
//            while (!s.empty()
//                   && T[s.top()] < T[i]) {

//                daysOfWait[s.top()]
//                    = i - s.top();

//                // Pop the element
//                s.pop();
//            }

//            // Push the current index
//            s.push(i);
//        }
//        // Print waiting days
//    return daysOfWait;
//    }
};
int main() {
    Solution s;
    vector<int> input = {73,74,75,71,69,72,76,73};
    vector<int> result = s.dailyTemperatures(input);
    for (auto& i : result) {
        cout <<i << " ";
    }
    return 0;
}
