#include<iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)
            return 1;
        int l = 0, r = x;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if ((long)mid * mid == x)
                return mid;
            else if ((long)mid * mid < x)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};
int main() {
    int x = 224;
    Solution S;
    int res = S.mySqrt(x);
    cout << res << endl;
    return 0;
}