#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res;
        for (int j = 0; j < n; j++) {
            pair<int, int> pos = make_pair(0, j);
            bool isBlocked = false;
            for (int i = 0; i < m; i++) {
                int& x = pos.first, & y = pos.second;
                if (grid[x][y] == 1 && y + 1 < n && grid[x][y + 1] == 1) {
                    x++;
                    y++;
                }
                else if (grid[x][y] == -1 && y - 1 >= 0 && grid[x][y - 1] == -1) {
                    x++;
                    y--;
                }
                else {
                    isBlocked = true;
                    break;
                }
            }
            if (isBlocked)
                res.emplace_back(-1);
            else
                res.emplace_back(pos.second);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> grid = { {1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1} };
    auto res = S.findBall(grid);
    for (const auto& re : res) {
        cout << re << " ";
    }
    cout << endl;
    return 0;
}