#include<iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        // µÝ¹é·¨£¬³¬Ê±
        // return climbStairs(n - 1) + climbStairs(n - 2);
        int r1 = 1, r2 = 2, temp;
        for (int i = 3; i <= n; i++) {
            temp = r1 + r2;
            r1 = r2;
            r2 = temp;
        }
        return r2;
    }
};
int main() {
    Solution S;
    int n = 3;
    int res = S.climbStairs(45);
    cout << res << endl;
    return 0;
}