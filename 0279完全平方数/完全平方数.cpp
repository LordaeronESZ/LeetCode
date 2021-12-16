#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++) {
            int minVal = INT32_MAX;
            for (int j = 1; j * j <= i; j++) {
                minVal = min(minVal, res[i - j * j] + 1);
            }
            res[i] = minVal;
        }
        return res.back();
    }
};
int main() {
    Solution S;
    int n = 12;
    for (int i = 0; i <= n; i++) {
        cout << i << ": " << S.numSquares(i) << endl;
    }
    return 0;
}