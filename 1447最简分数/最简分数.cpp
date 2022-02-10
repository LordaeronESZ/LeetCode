#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    inline string getStr(int numerator, int denominator) {
        return to_string(numerator) + '/' + to_string(denominator);
    }
    int getGcd(int a, int b) {
        return (a % b == 0) ? b : getGcd(b, a % b);
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (getGcd(j, i) == 1) {
                    string newRes = getStr(j, i);
                    res.emplace_back(newRes);
                }
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    int n = 6;
    auto res = S.simplifiedFractions(n);
    for (const auto& re : res) {
        cout << re << "\t";
    }
    return 0;
}