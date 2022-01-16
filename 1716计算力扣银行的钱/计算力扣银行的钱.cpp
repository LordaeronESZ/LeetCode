#include<iostream>
using namespace std;
class Solution {
public:
    int totalMoney(int n) {
        int res = 0, numWeek = 1;
        for (int i = 1; i <= n; i++) {
            numWeek = (i - 1) / 7 + 1;
            //res += i - 7 * (numWeek - 1) + numWeek - 1;
            res += i - 6 * (numWeek - 1);
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 10;
    auto res = S.totalMoney(n);
    cout << res << endl;
    return 0;
}