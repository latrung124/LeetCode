#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int convertRomanChar(char a) {
		if (a == 'I') {
			return 1;
		} 
		else if (a == 'V') {
			return 5;
		}
		else if (a == 'X') {
			return 10;
		}
		else if (a == 'L') {
			return 50;
		}
		else if (a == 'C') {
			return 100;
		}
		else if (a == 'D') {
			return 500;
		}
		else if (a == 'M') {
			return 1000;
		}
		else {
			return 0;
		}
	}
	int romanToInt(string s) {
		int result = 0;
		for (int i = s.size()-1; i >= 0; --i) {
			int j = i - 1 ;
			if (j >= 0) {
				char arr[2];
				arr[0] = s.at(j);
				arr[1] = s.at(i);
				string ss;
				for (auto& c : arr) {
					ss += c;
				}
				if (strcmp(ss.c_str(), "IV") == 0) {
					result += 4;
					i = j;
				}
				else if (strcmp(ss.c_str(), "IX") == 0) {
					result += 9;
					i = j;
				}
				else if (strcmp(ss.c_str(), "XL") == 0) {
					result += 40;
					i = j;
				}
				else if (strcmp(ss.c_str(), "XC") == 0) {
					result += 90;
					i = j;
				}
				else if (strcmp(ss.c_str(), "CD") == 0) {
					result += 400;
					i = j;
				}
				else if (strcmp(ss.c_str(), "CM") == 0) {
					result += 900;
					i = j;
				}
				else {
					result += convertRomanChar(s.at(i));
				}
			}
			else {
				result += convertRomanChar(s.at(i));
			}
		}
		return result;
	}
};


//int main() {
//	Solution s;
//	cout << s.romanToInt("CXLV");
//	return 0;
//}