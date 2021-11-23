#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        if (s == goal) {
            unordered_map<char,int> chrMap;
            for (const auto& chr : s) {
                if (chrMap.find(chr) == chrMap.end())
                    chrMap[chr] = 1;
                else
                    return true;
            }
            return false;
        }
        vector<int> indexVec;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i])
                indexVec.emplace_back(i);
        }
        if (indexVec.size() != 2)
            return false;
        swap(s[indexVec[0]], s[indexVec[1]]);
        if (s == goal)
            return true;
        else
            return false;
    }
};
int main() {
    Solution S;
    string s = "abac";
    string goal = "abad";
    auto res = S.buddyStrings(s, goal);
    cout << res << endl;
    return 0;
}