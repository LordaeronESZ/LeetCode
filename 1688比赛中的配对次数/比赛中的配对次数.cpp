#include<iostream>
using namespace std;
class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n > 1) {
            if (n % 2 == 1) {
                res += (n - 1) / 2;
                n = (n + 1) / 2;
            }
            else {
                res += n / 2;
                n = n / 2;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 14;
    auto res = S.numberOfMatches(n);
    cout << res << endl;
    return 0;
}