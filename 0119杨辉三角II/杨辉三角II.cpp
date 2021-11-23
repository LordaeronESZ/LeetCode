#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rowVector(rowIndex + 1);
        rowVector[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                rowVector[j] += rowVector[j - 1];
            }
        }
        return rowVector;
    }
};
int main() {
    Solution S;
    int rowIndex = 4;
    auto res = S.getRow(rowIndex);
    for (const auto& re : res)
        cout << re << " ";
    return 0;
}