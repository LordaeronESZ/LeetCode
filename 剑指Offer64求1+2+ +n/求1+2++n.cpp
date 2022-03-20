#include<iostream>
using namespace std;
class Solution {
public:
    int sumNums(int n) {
        int res = 0;
        if (!n)
            return n;
        res = sumNums(n - 1) + n;
        return res;
    }
};
int main() {
    Solution S;
    auto res = S.sumNums(100);
    cout << res << endl;
    return 0;
}