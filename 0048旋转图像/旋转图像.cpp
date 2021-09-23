#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int in_size = matrix.size();
        for (int i = 0; i < matrix.size() / 2; i++) {
            if(i)
                in_size -= 2;
            for (int j = 0; j < in_size - 1; j++) {
                int i1 = i, j1 = i + j;
                int i2 = matrix.size() - 1 - i - j, j2 = i;
                int i3 = matrix.size() - 1 - i, j3 = matrix.size() - 1 - i - j;
                int i4 = i + j, j4 = matrix.size() - 1 - i;
                swap(matrix[i1][j1], matrix[i2][j2]);
                swap(matrix[i2][j2], matrix[i3][j3]);
                swap(matrix[i3][j3], matrix[i4][j4]);
            }
        }
    }
};
int main() {
    Solution S;
    vector<vector<int>> matrix = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
    S.rotate(matrix);
    for (auto mat : matrix) {
        for (auto m : mat)
            cout << m << " ";
        cout << endl;
    }
    return 0;
}