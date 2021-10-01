#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> res(obstacleGrid.size());
        bool isBlockedRows = false;
        for (int i = 0; i < res.size(); i++) {
            res[i].resize(obstacleGrid.front().size());
            if (obstacleGrid[i][0]) {
                res[i][0] = 0;
                isBlockedRows = true;
            }
            else if (isBlockedRows)
                res[i][0] = 0;
            else
                res[i][0] = 1;
            if (!i) {
                bool isBlockedCol = false;
                for (int j = 0; j < res.front().size(); j++) {
                    if (obstacleGrid[i][j]) {
                        res[i][j] = 0;
                        isBlockedCol = true;
                    }
                    else if (isBlockedCol)
                        res[i][j] = 0;
                    else
                        res[i][j] = 1;
                }
            }
        }
        for (int i = 1; i < res.size(); i++) {
            for (int j = 1; j < res.front().size(); j++) {
                if (obstacleGrid[i][j])
                    res[i][j] = 0;
                else
                    res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }
        return res[res.size() - 1][res.front().size() - 1];
    }
};
int main() {
    Solution S;
    vector<vector<int>> obstacleGrid = { {0,0,0},{0,1,0},{0,0,0} };
    vector<vector<int>> obstacleGrid2 = { {0}, {1} };
    auto res = S.uniquePathsWithObstacles(obstacleGrid2);
    cout << res << endl;
    return 0;
}