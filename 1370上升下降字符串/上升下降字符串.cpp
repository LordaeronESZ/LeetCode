#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        vector<int> chCnt(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++chCnt[(s[i] - 'a') % 26];
        }
        string res;
        while (res.size() != s.size()) {
            for (int i = 0; i < chCnt.size(); ++i) {
                if (chCnt[i]-- > 0) {
                    res += ('a' + i);
                }
            }
            for (int i = chCnt.size() - 1; i >= 0; --i) {
                if (chCnt[i]-- > 0) {
                    res += ('a' + i);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    string s = "aaaabbbbcccc";
    auto res = S.sortString(s);
    cout << res << endl;
}