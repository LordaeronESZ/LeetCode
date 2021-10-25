#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (size_t i = 0; i < matrix.size(); i++) {
            if (matrix[i].front() > target)
                break;
            size_t left = 0, right = matrix[i].size() - 1;
            while (left <= right) {
                size_t mid = (left + right) / 2;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};
int main() {
    Solution S;
    vector<vector<int>> matrix = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
    int target = 5;
    auto res = S.searchMatrix(matrix, target);
    cout << res << endl;
    return 0;
}