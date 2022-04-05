#include<iostream>
using namespace std;

class Solution {
private:
    bool isPrime(int val) {
        if (val < 2)
            return false;
        int tmp = sqrt(val);
        for (int i = 2; i <= tmp; ++i) {
            if (val % i == 0)
                return false;
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for (int i = left; i <= right; ++i) {
            int cnt = 0;
            int curVal = i;
            while (curVal > 0) {
                cnt += curVal & 1;
                curVal >>= 1;
            }
            res += isPrime(cnt);
        }
        return res;
    }
};
int main() {
    Solution S;
    int left = 6, right = 10;
    auto res = S.countPrimeSetBits(left, right);
    cout << res << endl;
}