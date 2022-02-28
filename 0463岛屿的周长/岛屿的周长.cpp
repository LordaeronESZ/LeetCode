#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    int m, n;
    const vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j])
            return 1;
        else if (grid[i][j] == 2)
            return 0;
        int res = 0;
        grid[i][j] = 2;
        for (const auto& dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            res += dfs(grid, ni, nj);
        }
        return res;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j])
                    res += dfs(grid, i, j);
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> grid = { {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0} };
    auto res = S.islandPerimeter(grid);
    cout << res << endl;
    return 0;
}