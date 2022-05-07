#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
private:
    bool isLegal(const string& s1, const string& s2) {
        int diffs = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i])
                ++diffs;
        }
        return diffs == 1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int res = 0;
        queue<string> open;
        unordered_set<string> close;
        open.emplace(start);
        while (!open.empty()) {
            string op = open.front();
            open.pop();
            if (op == end)
                return res;
            close.emplace(op);
            ++res;
            for (const auto& trans : bank) {
                if (isLegal(op, trans) && !close.count(trans)) {
                    if (trans == end)
                        return res;
                    open.emplace(trans);
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution S;
    string start = "AACCGGTT";
    string end = "AAACGGTA";
    vector<string> bank = { "AACCGGTA","AACCGCTA","AAACGGTA" };
    auto res = S.minMutation(start, end, bank);
    cout << res << endl;
}