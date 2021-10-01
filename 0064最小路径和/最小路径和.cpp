#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> res(m);
        for (int i = 0; i < m; i++) {
            res[i].resize(n);
            if (!i)
                res[i][0] = grid[i][0];
            else
                res[i][0] = res[i - 1][0] + grid[i][0];
            if (!i) {
                for (int j = 1; j < n; j++)
                    res[i][j] = res[i][j - 1] + grid[i][j];
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
            }
        }
        return res[m - 1][n - 1];
    }
};
int main() {
    Solution S;
    vector<vector<int>> grid = { {1,3,1},{1,5,1},{2,4,1} };
    vector<vector<int>> grid2 = { {1,2,3},{4,5,6} };
    auto res = S.minPathSum(grid2);
    cout << res << endl;
    return 0;
}