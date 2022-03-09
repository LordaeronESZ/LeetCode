#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) return n;
        vector<int> vec(n + 1);
        vec[0] = 0, vec[1] = 1;
        int res = INT32_MIN;
        for (int i = 2; i <= n; ++i) {
            if (i % 2) {
                vec[i] = vec[i / 2] + vec[i / 2 + 1];
            }
            else {
                vec[i] = vec[i / 2];
            }
            res = max(res, vec[i]);
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 2;
    auto res = S.getMaximumGenerated(n);
    cout << res << endl;
    return 0;
}