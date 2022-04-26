#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.size();
        int x = 0, y = 0, z = 0;
        vector<int> maxZ(n, 0);
        for (int i = 0; i < m; ++i) {
            int maxY = 0;
            for (int j = 0; j < n; ++j) {
                x += grid[i][j] > 0;
                maxY = max(maxY, grid[i][j]);
                maxZ[j] = max(maxZ[j], grid[i][j]);
            }
            y += maxY;
        }
        z = accumulate(maxZ.begin(), maxZ.end(), 0);
        return x + y + z;
    }
};

int main() {
    Solution S;
    vector<vector<int>> grid = { {1,2},{3,4} };
    auto res = S.projectionArea(grid);
    cout << res << endl;
}