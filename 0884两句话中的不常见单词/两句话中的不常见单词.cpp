#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
private:
    vector<string> splitStr(string s) {
        vector<string> res;
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                string newRes = s.substr(p, i - p);
                res.emplace_back(newRes);
                p = i + 1;
            }
            else if (i == s.size() - 1) {
                string newRes = s.substr(p, i - p + 1);
                res.emplace_back(newRes);
            }
        }
        return res;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string, int> strMap;
        vector<string> strs1 = splitStr(s1);
        vector<string> strs2 = splitStr(s2);
        for (const auto& str1 : strs1) {
            strMap[str1]++;
        }
        for (const auto& str2 : strs2) {
            strMap[str2]++;
        }
        for (const auto& strm : strMap) {
            if (strm.second == 1)
                res.emplace_back(strm.first);
        }
        return res;
    }
};
int main() {
    Solution S;
    string s1 = "s z z z s";
    string s2 = "s z ejt";
    auto res = S.uncommonFromSentences(s1, s2);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}
