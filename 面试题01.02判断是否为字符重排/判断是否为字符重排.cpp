#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        unordered_map<char, int> chCnt;
        for (int i = 0; i < s1.size(); ++i) {
            ++chCnt[s1[i]];
        }
        for (int i = 0; i < s2.size(); ++i) {
            --chCnt[s2[i]];
            if (chCnt[s2[i]] == 0) {
                chCnt.erase(s2[i]);
            }
        }
        return chCnt.empty();
    }
};

int main() {
    Solution S;
    string s1 = "abc";
    string s2 = "bca";
    auto res = S.CheckPermutation(s1, s2);
    cout << res << endl;
}