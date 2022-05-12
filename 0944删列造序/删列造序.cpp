#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        int res = 0;
        for (int j = 0; j < n; ++j) {
            bool flag = false;
            for (int i = 1; i < m; ++i) {
                if (strs[i][j] < strs[i - 1][j]) {
                    flag = true;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<string> strs = { "abc", "bce", "cae" };
    auto res = S.minDeletionSize(strs);
    cout << res << endl;
}