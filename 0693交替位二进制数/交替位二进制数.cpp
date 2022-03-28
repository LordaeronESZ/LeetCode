#include<iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastVal = n % 2;
        n /= 2;
        while (n) {
            int curVal = n % 2;
            n /= 2;
            if (curVal == lastVal)
                return false;
            lastVal = curVal;
        }
        return true;
    }
};
int main() {
    Solution S;
    int n = 5;
    auto res = S.hasAlternatingBits(n);
    cout << res << endl;
    return 0;
}