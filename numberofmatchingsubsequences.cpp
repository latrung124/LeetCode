#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        cout << s << " " << t <<endl;
        int sizeT = t.size();
        int sizeS = s.size();
        int j = 0;
        for (int i = 0; i < sizeT && j < sizeS; ++i) {
            if (s[j] == t[i]) {
                ++j;
            }
        }
        return j == sizeS;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        unordered_map<string, int> m;
        for (auto& i : words) {
            m[i]++;
        }
        for (auto& j : m) {
            if (isSubsequence(j.first, s)) {
                result += j.second;
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<string> input = {"a","a","bb","acd","ace"};
    string sInput = "abcde";
    cout << s.numMatchingSubseq(sInput, input) <<endl;

//    unordered_map<string, int> m;
//    for (auto& i : input) {
//        m[i]++;
//    }
//    for (auto& tmp : m) {
//        cout << tmp.first << " " << tmp.second;
//    }
//    cout <<endl;
    return 0;
}
