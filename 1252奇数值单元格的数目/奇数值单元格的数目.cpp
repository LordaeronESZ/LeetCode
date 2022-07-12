#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int res = 0;
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for (const auto& indice : indices) {
            int ri = indice[0], ci = indice[1];
            for (int j = 0; j < n; ++j) {
                ++mat[ri][j];
            }
            for (int i = 0; i < m; ++i) {
                ++mat[i][ci];
            }
        }
        for (const auto& row : mat) {
            for (const auto& num : row) {
                res += num % 2;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    int m = 2, n = 3;
    vector<vector<int>> indices = { {0,1},{1,1} };
    auto res = S.oddCells(m, n, indices);
    cout << res << endl;
}