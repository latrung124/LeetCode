// C++ program for the above approach
#include <iostream>
using namespace std;

// Function to count the number of
// substrings of equal length which
// differ by a single character
int countSubstrings(string s, string t)
{
	int result = 0;
	int l1 = s.length();
	int l2 = t.length();
	for (int i = 1; i <= l1; i++) { //both length of string s and t
		for (int j = 0; j + i <= l1; ++j) { // length of string s
			string s1 = s.substr(j, i);
			for (int k = 0; k + i <= l2; ++k) { // length of string t
				string t1 = t.substr(k, i);
				int f = 1; // variable to check string t and s
				for (int p = 0; p <= i; ++p) {
					if (s1[p] != t1[p]) f--; // check string t and s differ only 1 character
				}
				if (f == 0) result++; // increase result by 1 if f value only decreases one time
			}
		}
	}
	return result;
}

// Driver Code
int main()
{
	string S = "aba";
	string T = "baba";

	// Function Call
	cout << (countSubstrings(S, T));
}
