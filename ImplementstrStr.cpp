#include <iostream> 
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.empty() || needle.empty()) return 0;
		char fN = needle[0];
		int i = 0;
		for (auto& c : haystack) {
			if (c == fN && haystack.length() - i >= needle.length()) {
				string sub = haystack.substr(i, needle.length());
				if (strcmp(sub.c_str(), needle.c_str()) == 0) {
					return i;
				}
			}
			++i;
		}
		return -1;
	}
};
int main() {
	string s = "trungla";
	string m = "la";
	Solution so;
	cout << so.strStr(s, m);
	return 0;
}