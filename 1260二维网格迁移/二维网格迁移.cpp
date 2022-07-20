#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res = grid;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = (i * n + j + k) % (m * n);
                int ni = num / n, nj = num % n;
                res[ni][nj] = grid[i][j];
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    // vector<vector<int>> grid = { {3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13} };
    vector<vector<int>> grid = { {1}, {2}, {3}, {4}, {7}, {6}, {5} };
    int k = 23;
    auto res = S.shiftGrid(grid, k);
    for (const auto& re : res) {
        for (const auto& r : re) {
            cout << r << " ";
        }
        cout << endl;
    }
}