#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto cmp = [](const string& s1, const string& s2) {
            int p1 = s1.find(' ');
            int p2 = s2.find(' ');
            string subS1 = s1.substr(p1 + 1);
            string subS2 = s2.substr(p2 + 1);
            if (subS1 != subS2)
                return subS1 < subS2;
            else {
                subS1 = s1.substr(0, p1);
                subS2 = s2.substr(0, p2);
                return subS1 < subS2;
            }
;        };
        
        vector<string> alphaVec;
        vector<string> numVec;
        for (const auto& log : logs) {
            if (isalpha(log.back()))
                alphaVec.emplace_back(log);
            else
                numVec.emplace_back(log);
        }
        sort(alphaVec.begin(), alphaVec.end(), cmp);
        for (const auto& numLog : numVec) {
            alphaVec.emplace_back(numLog);
        }
        return alphaVec;
    }
};

int main() {
    Solution S;
    vector<string> logs = { "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car" };
    auto res = S.reorderLogFiles(logs);
    for (const auto& re : res) {
        cout << re << endl;
    }
}