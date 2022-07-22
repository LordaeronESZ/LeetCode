#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int res = 0;
        for (int i = 1; i * (i + 1) / 2 <= n; ++i) {
            int val = n % i;
            if (i % 2 == 0 && val == i / 2) {
                cout << "i = " << i << "\tn = " << n << endl;
                ++res;
            }
            else if (i % 2 == 1 && val == 0) {
                cout << "i = " << i << "\tn = " << n << endl;
                ++res;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    int n = 85;
    auto res = S.consecutiveNumbersSum(n);
    cout << res << endl;
}