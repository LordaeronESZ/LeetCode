#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int leastMinutes(int n) {
        int downSpeed = 1;
        int res = 0;
        while (n > 0) {
            float cost1 = 1.0f * n / downSpeed;
            float cost2 = 1 + (1.0f * n) / (downSpeed * 2);
            if (cost1 < cost2) {
                n -= downSpeed;
            }
            else {
                downSpeed *= 2;
            }
            res++;
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 4;
    auto res = S.leastMinutes(n);
    cout << res << endl;
    return 0;
}