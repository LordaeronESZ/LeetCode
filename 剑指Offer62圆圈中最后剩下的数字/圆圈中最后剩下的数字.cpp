#include<iostream>
using namespace std;
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 1)
            return 0;
        int x = lastRemaining(n - 1, m);
        return (x + m) % n;
    }
};
int main() {
    Solution S;
    int n = 5, m = 3;
    auto res = S.lastRemaining(n, m);
    cout << res << endl;
    return 0;
}