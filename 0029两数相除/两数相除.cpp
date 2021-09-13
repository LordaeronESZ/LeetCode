#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if ((dividend == INT32_MAX || dividend == INT32_MIN) && divisor == -1)
            return INT32_MAX;
        long res = 0;
        int flag = dividend ^ divisor;
        long l_dividend = abs(long(dividend));
        long l_divisor = abs(long(divisor));
        for (int i = 31; i >= 0; i--) {
            if ((l_dividend >> i) >= l_divisor) {
                res += 1 << i;
                l_dividend -= l_divisor << i;
            }
        }
        return flag >= 0 ? res : -res;
    }
};
int main() {
    int dividend = 1;
    int divisor = 1;
    Solution S;
    int res = S.divide(dividend, divisor);
    cout << res << endl;
    return 0;
}