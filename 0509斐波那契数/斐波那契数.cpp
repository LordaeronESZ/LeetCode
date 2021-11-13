#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        vector<int> res(n + 1);
        res[0] = 0;
        res[1] = 1;
        for (size_t i = 2; i <= n; i++)
            res[i] = res[i - 1] + res[i - 2];
        return res.back();
    }
};
int main() {
    Solution S;
    int n = 0;
    auto res = S.fib(n);
    cout << res << endl;
    return 0;
}