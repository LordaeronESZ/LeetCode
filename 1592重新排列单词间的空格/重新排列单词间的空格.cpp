#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int spaceCnt = 0;
        for (int i = 0; i < text.size(); ++i) {
            if (text[i] == ' ') {
                ++spaceCnt;
            }
        }
        stringstream ss(text);
        string temp;
        vector<string> wordVec;
        while (ss >> temp) {
            wordVec.emplace_back(temp);
        }
        if (wordVec.size() == 1) {
            return wordVec[0] + string(spaceCnt, ' ');
        }
        int avgCnt = spaceCnt / (wordVec.size() - 1);
        int spsCnt = spaceCnt % (wordVec.size() - 1);
        string res;
        for (int i = 0; i < wordVec.size(); ++i) {
            res += wordVec[i];
            if (i == wordVec.size() - 1) {
                res += string(spsCnt, ' ');
            }
            else {
                res += string(avgCnt, ' ');
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    string text = "a";
    auto res = S.reorderSpaces(text);
    cout << res << endl;
}