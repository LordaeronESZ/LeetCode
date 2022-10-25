#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution { // Wrong Answer
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> dirs = { {0, 1},{0,-1},{1,0},{-1,0} };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    que.emplace(make_pair(i, j));
                    while (!que.empty()) {
                        int oi = que.front().first, oj = que.front().second;
                        que.pop();
                        grid[oi][oj] = -1;
                        for (const auto& dir : dirs) {
                            int ni = oi + dir[0], nj = oj + dir[1];
                            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                                que.emplace(make_pair(ni, nj));
                            }
                        }
                    }
                    break;
                }
            }
        }

        for (const auto& gr : grid) {
            for (const auto& g : gr) {
                cout << g << " ";
            }
            cout << endl;
        }

        int res = INT32_MAX, dis = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == -1) {
                    dis = 0;
                    que.emplace(make_pair(i, j));
                    while (!que.empty()) {
                        ++dis;
                        int oi = que.front().first, oj = que.front().second;
                        que.pop();
                        if (grid[oi][oj] == 1) {
                            res = min(res, dis);
                            while (!que.empty()) {
                                que.pop();
                            }
                            break;
                        }
                        grid[oi][oj] = -1;
                        for (const auto& dir : dirs) {
                            int ni = oi + dir[0], nj = oj + dir[1];
                            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 0) {
                                que.emplace(make_pair(ni, nj));
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> grid = { {1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1} };
    auto res = S.shortestBridge(grid);
    cout << res << endl;
}