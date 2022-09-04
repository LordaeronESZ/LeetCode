#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res = 0;
        vector<int> rowNums(mat.size());
        vector<int> colNums(mat[0].size());
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                rowNums[i] += mat[i][j];
                colNums[j] += mat[i][j];
            }
        }
        for (int i = 0; i < rowNums.size(); ++i) {
            for (int j = 0; j < colNums.size(); ++j) {
                if (rowNums[i] == 1 && colNums[j] == 1 && mat[i][j] == 1) {
                    ++res;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> mat = { {1,0,0},{0,0,1},{1,0,0} };
    auto res = S.numSpecial(mat);
    cout << res << endl;
}