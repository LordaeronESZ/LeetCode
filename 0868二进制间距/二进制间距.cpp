#include<iostream>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int res = 0, lastInd = INT32_MAX;
        for (int i = 0; n > 0; ++i, n >>= 1) {
            int bit = n & 1;
            if (bit) {
                res = max(res, i - lastInd);
                lastInd = i;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    int n = 22;
    auto res = S.binaryGap(n);
    cout << res << endl;
}