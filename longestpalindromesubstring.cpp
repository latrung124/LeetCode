#include <bits/stdc++.h>
#include <chrono>
using namespace std;

class Solution {
public:
    string longestPalSubstr(string s)
    {
        if (s.size() == 0) return "";
        else if (s.size() == 1) return s;
        string result(1, s[0]);
        int maxR = result.size();
        size_t n = s.size();
        bool arr[n][n];
        memset(arr, false, sizeof(arr));
        for (int i = 0; i < n; ++i) {
            arr[i][i] = true;
        }
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i < n - k; ++i) {
                int j = i+k;
                if (s[i] == s[j] && j-i == 1) {
                    arr[i][j] = true;
                    if (maxR < 2) {
                        maxR = 2;
                        cout << i <<" "<< j << endl;
                        result = s.substr(i,2);
                    }
                }
                else {
                    if (arr[i+1][j-1] && s[i] == s[j]) {
                        arr[i][j] = true;
                        if (maxR < j - i + 1) {
                            maxR = j - i + 1;
                            cout << i <<" "<< j << endl;
                            result = s.substr(i,maxR);
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    //string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    string s = "babad";
    //string sub1 = s.substr(0, s.size() / 2);
    //string sub2 = s.substr((s.size() / 2) + 1, s.size());
    //cout << "s: " << s << " sub1: " << sub1 <<" sub2: " << sub2 << endl;
    Solution solution;
    cout << solution.longestPalSubstr(s) << endl;
    return 0;
}

