#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    vector<vector<bool>> dp;
    vector<vector<string>> res;
    vector<string> temp;
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.assign(n, vector<bool>(n, true));
        //dpÔ¤´¦Àí
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) { //i >= j Ê± dp[i][j] = true
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        dfs(s, 0);
        return res;
    }
    void dfs(const string& s, int i) {
        if (i == s.size()) {
            res.emplace_back(temp);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (dp[i][j]) {
                temp.emplace_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                temp.pop_back();
            }
        }
    }
};
int main() {
    Solution S;
    string s = "abbab";
    auto res = S.partition(s);
    for (const auto& re : res) {
        for (const auto& r : re)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}