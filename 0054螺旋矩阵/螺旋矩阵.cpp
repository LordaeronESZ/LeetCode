#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        vector<int> res;
        int left = 0, up = 0;
        int right = matrix[0].size() - 1, down = matrix.size() - 1;
        int i = up, j = left;
        while (left <= right && up <= down) {
            for (j = left; j <= right; j++)
                res.emplace_back(matrix[up][j]);
            for (i = up + 1; i <= down; i++)
                res.emplace_back(matrix[i][right]);
            if (left < right && up < down) {
                for (j = right - 1; j >= left; j--)
                    res.emplace_back(matrix[down][j]);
                for (i = down - 1; i >= up + 1; i--)
                    res.emplace_back(matrix[i][left]);
            }
            left++; up++; down--; right--;
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    vector<vector<int>> matrix2 = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    auto res = S.spiralOrder(matrix2);
    for (const auto r : res)
        cout << r << " ";
    return 0;
}