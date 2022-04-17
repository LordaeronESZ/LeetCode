#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> strCnt;
        int p = 0;
        string tempStr;
        for (int i = 0; i < paragraph.size(); ++i) {
            if (isalpha(paragraph[i]))
                tempStr += tolower(paragraph[i]);
            else if (!tempStr.empty()) {
                ++strCnt[tempStr];
                tempStr.clear();
            }
        }
        if (!tempStr.empty())
            ++strCnt[tempStr];
        for (const auto& bannedStr : banned) {
            strCnt[bannedStr] = INT32_MIN;
        }
        string res;
        int resNum = INT32_MIN;
        for (const auto& sc : strCnt) {
            if (sc.second > resNum) {
                res = sc.first;
                resNum = sc.second;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    string paragraph = "Bob";
    vector<string> banned = {};
    auto res = S.mostCommonWord(paragraph, banned);
    cout << res << endl;
}