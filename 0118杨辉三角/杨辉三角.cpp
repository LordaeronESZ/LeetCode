#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = { {1} };
        for (int i = 2; i <= numRows; i++) {
            vector<int> tempVec(i);
            tempVec.front() = res[i - 2].front();
            tempVec.back() = res[i - 2].back();
            for (int j = 1; j < i - 1; j++) {
                tempVec[j] = res[i - 2][j - 1] + res[i - 2][j];
            }
            res.emplace_back(tempVec);
        }
        return res;
    }
};
int main() {
    Solution S;
    int numRows = 5;
    auto res = S.generate(numRows);
    for (const auto& re : res) {
        for (const auto& r : re) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}