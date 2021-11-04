#include<iostream>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long temp1;
        long long temp2;
        switch (num % 10)
        {
        case 0:
            temp1 = 0;
            temp2 = 10; break;
        case 1:
            temp1 = 1;
            temp2 = 9; break;
        case 4:
            temp1 = 2;
            temp2 = 8; break;
        case 9:
            temp1 = 3;
            temp2 = 7; break;
        case 6:
            temp1 = 4;
            temp2 = 6; break;
        case 5:
            temp1 = 5;
            temp2 = 15; break;
        default:
            break;
        }
        while (temp1 <= num || temp2 <= num) {
            if (temp1 * temp1 == num)
                return true;
            if (temp2 * temp2 == num)
                return true;
            if (temp2 - temp1 == 10) {
                temp1 += 20;
                temp2 += 20;
            }
            else {
                temp1 += 10;
                temp2 += 10;
            }
        }
        return false;
    }
};
int main() {
    Solution S;
    int num = 1;
    auto res = S.isPerfectSquare(num);
    cout << res << endl;
    return 0;
}