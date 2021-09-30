#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m);
        for (auto& mat : matrix) {
            mat.resize(n);
            mat.front() = 1;
            if (mat == matrix.front()) {
                for (auto& m : mat)
                    m = 1;
            }  
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
        }
        return matrix[m - 1][n - 1];
    }
};
int main() {
    Solution S;
    auto res = S.uniquePaths(23, 12);
    cout << res << endl;
    return 0;
}