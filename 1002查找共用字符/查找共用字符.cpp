#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> chCnt(26, 0);
        vector<int> minCnt(26, INT32_MAX);
        for (int i = 0; i < words.size(); ++i) {
            chCnt.assign(26, 0);
            for (int j = 0; j < words[i].size(); ++j) {
                int ind = words[i][j] - 'a';
                ++chCnt[ind];
            }
            for (int i = 0; i < 26; ++i) {
                minCnt[i] = min(minCnt[i], chCnt[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i < minCnt.size(); ++i) {
            string ch(1, 'a' + i);
            while (minCnt[i]-- > 0) {
                res.emplace_back(ch);
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<string> words = { "bella","label","roller" };
    auto res = S.commonChars(words);
    for (const auto& re : res) {
        cout << re << " ";
    }
}