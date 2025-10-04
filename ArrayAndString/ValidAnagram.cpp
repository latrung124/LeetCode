#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int countArr[26] = {0};
        for (auto c : s) ++countArr[c - 'a'];
        for (auto c : t) --countArr[c - 'a'];
    
        for (int i = 0; i < 26; ++i) {
            if (countArr[i] != 0) return false;
        }
    
        return true;
    }
};