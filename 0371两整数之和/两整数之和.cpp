#include<iostream>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        for (int i = 0; i < b; i++)
            a++;
        for (int i = 0; i > b; i--)
            a--;
        return a;
    }
};
int main() {
    Solution S;
    int a = -12, b = -8;
    auto res = S.getSum(a, b);
    cout << res << endl;
    return 0;
}