#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = m, col = n;
        for (const auto& op : ops) {
            if (row > op[0])
                row = op[0];
            if (col > op[1])
                col = op[1];
        }
        return row * col;
    }
};
int main() {
    Solution S;
    int m = 3, n = 3;
    vector<vector<int>> ops = { {2,2},{3,3} };
    auto res = S.maxCount(m, n, ops);
    cout << res << endl;
    return 0;
}