#include<iostream>
#include<string>
using namespace std;
class Solution {
private:
    pair<int, int> transComplex(string s) {
        auto str2int = [](string snum) {
            int sizeStr = snum.size();
            int res = 0;
            if (snum[0] == '-') {
                for (int i = 1; i < sizeStr; i++) {
                    res -= (snum[i] - '0') * pow(10, sizeStr - i - 1);
                }
            }
            else {
                for (int i = 0; i < sizeStr; i++) {
                    res += (snum[i] - '0') * pow(10, sizeStr - i - 1);
                }
            }
            return res;
        };

        int n = s.size();
        pair<int, int> transNum = make_pair(0, 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+') {
                string snum1 = s.substr(0, i);
                string snum2 = s.substr(i + 1, n - i - 2);
                transNum.first = str2int(snum1);
                transNum.second = str2int(snum2);
                break;
            }
        }
        return transNum;
    }
public:
    string complexNumberMultiply(string num1, string num2) {
        auto transNum1 = transComplex(num1);
        auto transNum2 = transComplex(num2);
        int token1 = transNum1.first * transNum2.first - transNum1.second * transNum2.second;
        int token2 = transNum1.first * transNum2.second + transNum1.second * transNum2.first;
        string res = to_string(token1) + "+" + to_string(token2) + "i";
        return res;
    }
};
int main() {
    Solution S;
    string num1 = "78+-76i";
    string num2 = "-86+72i";
    auto res = S.complexNumberMultiply(num1, num2);
    cout << res << endl;
    return 0;
}