#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int factorSum = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                factorSum += i;
            }
        }
        if (num == factorSum)
            return true;
        else
            return false;
    }
};
int main() {
    Solution S;
    int num = 28;
    auto res = S.checkPerfectNumber(num);
    cout << res << endl;
    return 0;
}