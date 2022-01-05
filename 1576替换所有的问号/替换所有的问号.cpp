#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                s[i] = 'a';
                if (i > 0 && s[i - 1] == s[i])
                    s[i] = char((s[i] - 'a' + 1) % 26 + 'a');
                if(i < s.size() && s[i + 1] == s[i])
                    s[i] = char((s[i] - 'a' + 1) % 26 + 'a');
                if (i > 0 && s[i - 1] == s[i])
                    s[i] = char((s[i] - 'a' + 1) % 26 + 'a');
            }
        }
        return s;
    }
};
int main() {
    Solution S;
    string s = "j?qg??b";
    string s2 = "b?a";
    auto res = S.modifyString(s2);
    cout << res << endl;
    return 0;
}