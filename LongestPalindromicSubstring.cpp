#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool resultArr[2000][2000];
class Solution {  
public:
    bool isPalindrome(string s) {
        size_t l = s.size();
        if (l == 0) return false;
        else if (l == 1) return true;
        else {
            if (l % 2 == 0) {
                string tmp1 = s.substr(0, l / 2);
                string tmp2 = s.substr(l / 2, l);
                std::reverse(tmp2.begin(), tmp2.end());
                return strcmp(tmp2.c_str(), tmp1.c_str()) == 0;
            }
            else {
                string tmp1 = s.substr(0, l / 2);
                string tmp2 = s.substr((l / 2) + 1, l);
                std::reverse(tmp2.begin(), tmp2.end());
                return strcmp(tmp2.c_str(), tmp1.c_str()) == 0;
            }
            return true;
        }
    }

    string longestPalindrome(string s) {       
        if (s.empty()) return "";
        else if (s.size() == 1) return s;    
        if (isPalindrome(s)) {
            return s;
        }       
        memset(resultArr, false, sizeof(resultArr));
        string result = "";
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < s.length(); ++j) {
                string tmp = s.substr(i, j);
                if (resultArr[i][j]) continue;
                if (isPalindrome(tmp)) {
                    if (result.length() < tmp.length()) result = tmp;
                    resultArr[i][j] = true;
                }
            }
        }
        return result;
    }
};
//Input: s = "babad"
//Output : "bab"
//Explanation : "aba" is also a valid answer.
int main() {
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    //string sub1 = s.substr(0, s.size() / 2);
    //string sub2 = s.substr((s.size() / 2) + 1, s.size());
    //cout << "s: " << s << " sub1: " << sub1 <<" sub2: " << sub2 << endl;
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
	return 0;
}