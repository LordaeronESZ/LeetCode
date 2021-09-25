#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        bool isPos = n > 0 ? true : false;
        n = abs(n);
        double res = 1.0;
        for (int i = n; i; i /= 2) {
            if (i % 2)
                res *= x;
            x *= x;
        }
        return isPos ? res : 1 / res;
    }
};
int main() {
    Solution S;
    double x = 2;
    int n = 4;
    double res = S.myPow(x, n);
    cout << res << endl;
    return 0;
}