#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                else
                    dp[i][j] = 0;
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
int main() {
    Solution S;
    vector<vector<char>> matrix = { {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
    vector<vector<char>> matrix2 = { {'0','1'},{'1','0'} };
    auto res = S.maximalSquare(matrix2);
    cout << res << endl;
    return 0;
}