#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        if (!n)
            return 0;
        else if (n == 1 || n == 2)
            return 1;
        vector<int> res(n + 1);
        res[0] = 0;
        res[1] = 1;
        res[2] = 1;
        for (size_t i = 3; i <= n; i++)
            res[i] = res[i - 1] + res[i - 2] + res[i - 3];
        return res.back();
    }
};
int main() {
    Solution S;
    int n = 25;
    auto res = S.tribonacci(n);
    cout << res << endl;
    return 0;
}