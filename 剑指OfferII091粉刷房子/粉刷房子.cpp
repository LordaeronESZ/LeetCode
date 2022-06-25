#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> dp(3);
        for (int j = 0; j < 3; j++) {
            dp[j] = costs[0][j];
        }
        for (int i = 1; i < n; i++) {
            vector<int> dpNew(3);
            for (int j = 0; j < 3; j++) {
                dpNew[j] = min(dp[(j + 1) % 3], dp[(j + 2) % 3]) + costs[i][j];
            }
            dp = dpNew;
        }
        return *min_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution S;
    vector<vector<int>> costs = { {17, 2, 17}, {16, 16, 5}, {14, 3, 19} };
    auto res = S.minCost(costs);
    cout << res << endl;
}