#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        if (numRows == 1) return { { 1 } };
        else if (numRows == 2) return  { {1}, {1, 1} };
        else if (numRows == 0) return {{}};
        vector<vector<int>> result;
        result.push_back({ 1 });
        result.push_back({ 1, 1 });
        int n = 3;
        while (n <= numRows) {
            int size = result.at(result.size() - 1).size();
            vector<int> tmp;
            tmp.push_back(1);
            vector<int> check = result.at(result.size() - 1);
            for (int i = 0; i < size - 1; ++i) {
                tmp.push_back(check.at(i) + check.at(i + 1));
           }
            tmp.push_back(1);
            result.push_back(tmp);
            n++;
        }
        for (auto& i : result) {
            for (auto& j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        return result;
    }
};
int main() {
    Solution s;
    s.generate(7);
	return 0;
}