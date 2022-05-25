#include<iostream>
#include<string>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> dp(26);
        int cstNum = 1;
        for (int i = 0; i < n; ++i) {
            if (!i) {
                dp[p[i] - 'a'] = 1;
                continue;
            }
            int strip = p[i] - p[i - 1];
            if (strip == 1 || strip == -25) {
                ++cstNum;
            }
            else {
                cstNum = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], cstNum);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main() {
    Solution S;
    string p = "zaba";
    auto res = S.findSubstringInWraproundString(p);
    cout << res << endl;
}