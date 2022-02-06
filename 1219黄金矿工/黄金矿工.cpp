#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    const vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int& maxVal, int& curVal) {
        visited[i][j] = true;
        for (const auto& dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] && !visited[ni][nj]) {
                curVal += grid[ni][nj];
                dfs(grid, visited, ni, nj, maxVal, curVal);
                visited[ni][nj] = false;
                curVal -= grid[ni][nj];
            }
        }
        maxVal = max(maxVal, curVal);
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0, curVal = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                curVal = grid[i][j];
                if (curVal)
                    dfs(grid, visited, i, j, res, curVal);
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> grid = { {1,6,1},{5,8,7},{1,9,1} };
    auto res = S.getMaximumGold(grid);
    cout << res << endl;
    return 0;
}