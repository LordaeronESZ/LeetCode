#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRow(n);
        vector<int> maxCol(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != maxRow[i] && grid[i][j] != maxCol[j]) {
                    res += min(maxRow[i], maxCol[j]) - grid[i][j];
                }
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> grid = { {3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0} };
    auto res = S.maxIncreaseKeepingSkyline(grid);
    cout << res << endl;
    return 0;
}