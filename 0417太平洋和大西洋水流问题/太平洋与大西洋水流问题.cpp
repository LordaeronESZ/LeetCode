#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    const vector<vector<int>> dirs = { {-1,0}, {1,0}, {0,-1},{0,1} };
    struct point
    {
        int x, y;
        point(int x, int y) : x(x), y(y) {}
    };
public:
    // ³¬Ê±
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                queue<point> Q;
                Q.emplace(i, j);
                bool pacific = false, atlantic = false;
                while (!Q.empty()) {
                    point p = Q.front();
                    Q.pop();
                    if (p.x == 0 || p.y == 0)
                        pacific = true;
                    if (p.x == m - 1 || p.y == n - 1)
                        atlantic = true;
                    for (const auto& dir : dirs) {
                        int nx = p.x + dir[0], ny = p.y + dir[1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && heights[nx][ny] <= heights[p.x][p.y]) {
                            Q.emplace(nx, ny);
                            visited[nx][ny] = true;
                        }
                    }
                }
                if (pacific && atlantic)
                    res.push_back({ i, j });
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> heights = { {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4} };
    auto res = S.pacificAtlantic(heights);
    for (const auto& re : res) {
        cout << re[0] << " " << re[1] << endl;
    }
}