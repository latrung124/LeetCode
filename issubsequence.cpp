#include <iostream>
using namespace std;

//Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
//A subsequence of a string is a new string that is formed from the original string
//by deleting some (can be none) of the characters without disturbing
//the relative positions of the remaining characters.
//(i.e., "ace" is a subsequence of "abcde" while "aec" is not).
//Ex1:
//Input: s = "abc", t = "ahbgdc"
//Output: true
//Ex2:
//Input: s = "axc", t = "ahbgdc"
//Output: false
class Solution {
public:
//    bool isSubsequence(string s, string t) {
//        size_t sizeS = s.size();
//        size_t sizeT = t.size();
//        if (sizeS == 0 && sizeT != 0) return true;
//        else if (sizeS != 0 && sizeT == 0) return false;
//        else if (sizeS == 0 && sizeT == 0) return true;
//        int dem = sizeT-1;
//        while (sizeS--) {
//            if (dem < 0) break;
//            bool isSame = false;
//            for (int i = dem ; i >= 0; --i) {
//                if (s[sizeS] == t[i]) {
//                    dem = --i;
//                    isSame = true;
//                    break;
//                }
//            }
//            if (!isSame) return false;
//        }
//        return true;
//    }
    bool isSubsequence(string s, string t) {
            int n = s.length(),m=t.length();
            int j = 0;
        // For index of s (or subsequence

        // Traverse s and t, and
        // compare current character
        // of s with first unmatched char
        // of t, if matched
        // then move ahead in s
        for (int i = 0; i < m and j < n; i++)
            if (s[j] == t[i])
                j++;

        // If all characters of s were found in t
        return (j == n);
        }
};
//int main() {
//    Solution s;
//    cout << s.isSubsequence("axc", "ahbgdc") << endl;
//    return 0;
//}
