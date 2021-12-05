#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        return recursion(a, b, b.size() - 1);
    }
    int recursion(int a, vector<int>& b, int i) {
        if (i < 0)
            return 1;
        return quickPow(recursion(a, b, i - 1), 10, 1337) * quickPow(a, b[i], 1337) % 1337;
    }
    int quickPow(int a, int b, int mod) {
        int res = 1;
        a %= mod;
        while (b > 0) {
            if (b % 2 == 1)
                res = res * a % mod;
            b /= 2;
            a = a * a % mod;
        }
        return res;
    }
};
int main() {
    Solution S;
    int a = 2147483647;
    vector<int> b = { 2,0,0 };
    auto res = S.superPow(a, b);
    cout << res << endl;
    return 0;
}