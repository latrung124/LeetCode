#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string t;		
		if (!strs.empty()) {

			for (int i = 0; i < strs.at(0).size(); ++i) {
				char a[1];
				a[0] = strs.at(0).at(i);
				t = t + a[0];
				for (int j = 1; j < strs.size(); ++j) {
					string sub = strs.at(j).substr(0, t.size());
					if (strcmp(sub.c_str(), t.c_str()) != 0) {
						return t.substr(0, t.size() -1);
					}
				}
			}
		}
		return t;
	}
};
//int main() {
//	vector<string> strs = {"flower","flow","flight" };
//	Solution s;
//	cout << s.longestCommonPrefix(strs) << endl;;
//	return 0;
//}