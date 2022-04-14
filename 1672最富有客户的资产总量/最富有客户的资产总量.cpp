#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size(), n = accounts[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += accounts[i][j];
            }
            res = max(res, sum);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> accounts = { {1,2,3},{3,2,1} };
    auto res = S.maximumWealth(accounts);
    cout << res << endl;
}