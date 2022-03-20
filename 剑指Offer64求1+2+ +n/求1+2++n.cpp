#include<iostream>
using namespace std;
class Solution {
public:
    int sumNums(int n) {
        return !n ? 0 : sumNums(n - 1) + n;
    }
};
int main() {
    Solution S;
    auto res = S.sumNums(100);
    cout << res << endl;
    return 0;
}