#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		else if (x < 10 && x >= 0) return true;
		else {
			string xstring = std::to_string(x);
			cout << xstring << endl;
			string s = xstring.substr(0, xstring.size() / 2);
			string e;
			if (xstring.size() % 2 != 0)
				e = xstring.substr(xstring.size() / 2 + 1, xstring.size());
			else {
				e = xstring.substr(xstring.size() / 2, xstring.size());
			}
			std::reverse(e.begin(), e.end());
			if (strcmp(s.c_str(), e.c_str()) == 0) return true;
			return false;
		}
	}
};


int main() {
	Solution s;
	bool i = s.isPalindrome(111111);
	cout << i ? "true" : "false";
	return 0;
}