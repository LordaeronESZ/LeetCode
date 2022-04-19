#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> cInd;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c)
                cInd.emplace_back(i);
        }
        vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            int minDis = INT32_MAX;
            for (int j = 0; j < cInd.size(); ++j) {
                if (minDis > abs(cInd[j] - i))
                    minDis = abs(cInd[j] - i);
                else
                    break;
            }
            res.emplace_back(minDis);
        }
        return res;
    }
};
int main() {
    Solution S;
    string s = "loveleetcode";
    char c = 'e';
    auto res = S.shortestToChar(s, c);
    for (const auto& re : res) {
        cout << re << " ";
    }
}