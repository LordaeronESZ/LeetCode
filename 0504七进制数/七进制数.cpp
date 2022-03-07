#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        if (!num)
            return "0";
        string res;
        bool isNegtive = false;
        if (num < 0) {
            isNegtive = true;
            num *= -1;
        }
        while (num >= 0) {
            int rem = num % 7;
            res += to_string(rem);
            num /= 7;
        }
        reverse(res.begin(), res.end());
        return isNegtive ? "-" + res : res;
    }
};
int main() {
    Solution S;
    int num = -70;
    auto res = S.convertToBase7(num);
    cout << res << endl;
    return 0;
}