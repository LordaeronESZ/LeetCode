#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int k = 2; k <= s.size(); k++) {
            if (s.size() % k)
                continue;
            int n = s.size() / k;
            int i;
            for (i = n; i < s.size(); i++) {
                if (s[i] != s[i - n])
                    break;
            }
            if (i == s.size())
                return true;
        }
        return false;
    }
};
int main() {
    Solution S;
    string s = "abcabcabcabc";
    string s2 = "ababba";
    auto res = S.repeatedSubstringPattern(s2);
    cout << res << endl;
    return 0;
}