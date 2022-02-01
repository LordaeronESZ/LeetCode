#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
private:
    bool isLegal(string s) {
        vector<bool> upperVec(26, false);
        vector<bool> lowerVec(26, false);
        for (const auto& ch : s) {
            if (islower(ch)) {
                lowerVec[ch - 'a'] = true;
            }
            else if (isupper(ch)) {
                upperVec[ch - 'A'] = true;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (upperVec[i] ^ lowerVec[i])
                return false;
        }
        return true;
    }
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        if (n < 2)
            return "";
        string res;
        for (int length = n; length >= 2; length--) {
            for (int i = 0; i + length - 1 < n; i++) {
                string curStr = s.substr(i, length);
                if (isLegal(curStr))
                    return curStr;
            }
        }
        return "";
    }
};
int main() {
    Solution S;
    string s = "YazaAay";
    auto res = S.longestNiceSubstring(s);
    cout << res << endl;
    return 0;
}