#include<iostream>
#include<vector>
#include<string>
#include<numeric>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;
        for (const auto& op : ops) {
            if (op == "C") {
                res.pop_back();
            }
            else if (op == "D") {
                res.emplace_back(res.back() * 2);
            }
            else if (op == "+") {
                int n = res.size();
                res.emplace_back(res[n - 1] + res[n - 2]);
            }
            else {
                res.emplace_back(stoi(op));
            }
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};
int main() {
    Solution S;
    vector<string> ops = { "5","2","C","D","+" };
    auto res = S.calPoints(ops);
    cout << res << endl;
    return 0;
}