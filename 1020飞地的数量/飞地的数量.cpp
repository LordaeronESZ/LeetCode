#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
private:
    vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        queue<pair<int, int>> Q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    Q.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }
        while (!Q.empty()) {
            int x = Q.front().first, y = Q.front().second;
            Q.pop();
            for (const auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny]) {
                    Q.emplace(nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !visited[i][j])
                    res++;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> grid = { {0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0} };
    auto res = S.numEnclaves(grid);
    cout << res << endl;
    return 0;
}