#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rowSet;
        unordered_set<int> colSet;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rowSet.emplace(i);
                    colSet.emplace(j);
                }
            }
        }
        for (const auto& row : rowSet) {
            for (int j = 0; j < matrix[row].size(); ++j) {
                matrix[row][j] = 0;
            }
        }
        for (const auto& col : colSet) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][col] = 0;
            }
        }
    }
};

int main() {
    Solution S;
    vector<vector<int>> matrix = { {0, 1, 2, 0} ,{3, 4, 5, 2},{1, 3, 1, 5} };
    S.setZeroes(matrix);
    for (const auto& mat : matrix) {
        for (const auto& m : mat) {
            cout << m << " ";
        }
        cout << endl;
    }
}