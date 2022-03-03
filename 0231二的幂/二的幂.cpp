#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long sum = 1;
        while (sum <= n) {
            if (sum == n)
                return true;
            sum <<= 1;
        }
        return false;
    }
};
int main() {
    Solution S;
    int n = 5;
    auto res = S.isPowerOfTwo(n);
    cout << res << endl;
    return 0;
}