#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> i_set;
        set<int> j_set;
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; !matrix.empty() && j < matrix[0].size(); j++)
            {
                if (!matrix[i][j]) {
                    i_set.insert(i);
                    j_set.insert(j);
                }
            }
        }
        for (auto const& it : i_set) {
            for (size_t j = 0; j < matrix[it].size(); j++) {
                matrix[it][j] = 0;
            }
        }
        for (auto const& jt : j_set) {
            for (size_t i = 0; i < matrix.size(); i++) {
                matrix[i][jt] = 0;
            }
        }
    }
};
int main() {
    Solution S;
    vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
    S.setZeroes(matrix);
    for (auto const& mat : matrix) {
        for (auto const& m : mat) {
            cout << m << " ";
        }
        cout << endl;
    }
}