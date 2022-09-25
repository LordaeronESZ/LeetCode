#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int num = i, rotatedNum = 0;
            bool flag = false;
            for (int j = 0; num > 0; ++j, num /= 10) {
                int digit = num % 10;
                switch (digit) {
                case 0: case 1: case 8: 
                    rotatedNum += pow(10, j) * digit; break;
                case 2:
                    rotatedNum += pow(10, j) * 5; break;
                case 5:
                    rotatedNum += pow(10, j) * 2; break;
                case 6:
                    rotatedNum += pow(10, j) * 9; break;
                case 9:
                    rotatedNum += pow(10, j) * 6; break;
                default: flag = true; break;
                }
                if (flag) break;
            }
            if (!flag && rotatedNum != i) {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    int n = 2;
    auto res = S.rotatedDigits(n);
    cout << res << endl;
}