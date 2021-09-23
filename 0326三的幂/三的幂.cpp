#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};
int main() {
    Solution S;
    int n = 1;
    cout << S.isPowerOfThree(n) << endl;
    return 0;
}