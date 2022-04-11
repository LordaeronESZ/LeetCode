#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n < 2)
            return pow(10, n);
        vector<int> res(n + 1, 0);
        res[0] = 1, res[1] = 10;
        for (int i = 2; i <= n; ++i) {
            res[i] = res[i - 1] + (res[i - 1] - res[i - 2]) * (10 - (i - 1));
        }
        return res.back();
    }
};
int main() {
    Solution S;
    int n = 2;
    auto res = S.countNumbersWithUniqueDigits(n);
    cout << res << endl;
}