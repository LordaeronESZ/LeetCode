#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int minVal = INT32_MAX, minInd = -1;
            for (int j = 0; j < n; j++) {
                if (minVal > matrix[i][j]) {
                    minVal = matrix[i][j];
                    minInd = j;
                }
            }
            bool isLegal = true;
            for (int k = 0; k < m; k++) {
                if (minVal < matrix[k][minInd]) {
                    isLegal = false;
                    break;
                }
            }
            if (isLegal)
                res.emplace_back(minVal);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> matrix = { {3,7,8},{9,11,13},{15,16,17} };
    auto res = S.luckyNumbers(matrix);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}