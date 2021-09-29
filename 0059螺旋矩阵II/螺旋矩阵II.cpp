#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n);
        for (auto &r : res)
            r.resize(n);
        int left = 0, up = 0;
        int right = res[0].size() - 1, down = res.size() - 1;
        int i = up, j = left, value = 1;
        while (left <= right && up <= down) {
            for (j = left; j <= right; j++)
                res[up][j] = value++;
            for (i = up + 1; i <= down; i++)
                res[i][right] = value++;
            if (left < right && up < down) {
                for (j = right - 1; j >= left; j--)
                    res[down][j] = value++;
                for (i = down - 1; i >= up + 1; i--)
                    res[i][left] = value++;
            }
            left++; up++; down--; right--;
        }
        return res;
    }
};
int main() {
    Solution S;
    for (int i = 1; i <= 20; i++) {
        auto res = S.generateMatrix(i);
        for (auto const& re : res) {
            for (auto const& r : re) {
                cout << r << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}