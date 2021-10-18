#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        int res = 0, n = 0;
        while (num) {
            if (num % 2 == 0)
                res += pow(2, n);
            num /= 2;
            n++;
        }
        return res;
    }
};
int main() {
    Solution S;
    int num = 10;
    auto res = S.findComplement(num);
    cout << res << endl;
    return 0;
}