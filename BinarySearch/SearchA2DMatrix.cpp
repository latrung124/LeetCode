#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool binarySearch(std::vector<int>& _temp, int target) {
        int left = 0;
        int right = _temp.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (_temp[mid] == target) {
                return true;
            } else if (_temp[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::vector<int> temp;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                temp.push_back(matrix[i][j]);
            }
        }

        return binarySearch(temp, target);
    }
};