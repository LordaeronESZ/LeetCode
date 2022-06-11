#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int num1 = 0, num0 = 0;
        for (const auto& ch : s) {
            num1 += (ch == '1');
            num0 += (ch == '0');
        }
        int left1 = 0, right0 = num0;
        int res = left1 + right0;
        for (const auto& ch : s) {
            if (ch == '1') ++left1;
            else if (ch == '0') --right0;
            res = min(res, left1 + right0);
        }
        return res;
    }
};

int main() {
    Solution S;
    string s = "11011";
    auto res = S.minFlipsMonoIncr(s);
    cout << res << endl;
}