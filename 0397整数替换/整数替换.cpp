#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1)
            return 0;
        else if ((n & 1) == 0)
            return 1 + integerReplacement(n / 2);
        else
            return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    }
};
int main() {
    Solution S;
    int n = 3;
    auto res = S.integerReplacement(n);
    cout << res << endl;
    return 0;
}