#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            if (i % 2 == 0)
                res[i] = res[i / 2];
            else
                res[i] = res[i / 2] + 1;
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 20;
    auto res = S.countBits(n);
    for (const auto& re : res)
        cout << re << " ";
    return 0;
}