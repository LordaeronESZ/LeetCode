#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            n /= 5;
            res += n;
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 14;
    auto res = S.trailingZeroes(n);
    cout << res << endl;
    return 0;
}