#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        string newStr;
        for (int i = 0; i < s.size(); i++) {
            newStr += s[i];
            if (newStr.size() == k) {
                res.emplace_back(newStr);
                newStr.clear();
            }
            else if (i == s.size() - 1) {
                for (int j = newStr.size(); j < k; j++) {
                    newStr += fill;
                }
                res.emplace_back(newStr);
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    string s = "abcdefghis";
    int k = 3;
    char fill = 'x';
    auto res = S.divideString(s, k, fill);
    for (const auto& re : res) {
        cout << re << endl;
    }
    return 0;
}