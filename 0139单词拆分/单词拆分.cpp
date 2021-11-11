#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string>::iterator wordFind(vector<string>& wordDict, string subStr) {
        auto it = wordDict.begin();
        for (; it < wordDict.end(); it++) {
            if (*it == subStr)
                break;
        }
        return it;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> res(s.size() + 1, false);
        res[0] = true;
        for (size_t i = 1; i <= s.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (res[j] && wordFind(wordDict, s.substr(j, i - j)) != wordDict.end())
                    res[i] = true;
            }
        }
        return res.back();
    }
};
int main() {
    Solution S;
    string s = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    auto res = S.wordBreak(s, wordDict);
    cout << res << endl;
    return 0;
}