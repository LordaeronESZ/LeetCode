#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        vector<char> digits;
        vector<char> alphas;
        for (const auto& ch : s) {
            if (isdigit(ch)) {
                digits.emplace_back(ch);
            }
            else if (isalpha(ch)) {
                alphas.emplace_back(ch);
            }
        }
        string res;
        if (digits.size() == alphas.size()) {
            for (int i = 0; i < digits.size(); ++i) {
                res += digits[i];
                res += alphas[i];
            }
        }
        else if (digits.size() == alphas.size() + 1) {
            for (int i = 0; i < alphas.size(); ++i) {
                res += digits[i];
                res += alphas[i];
            }
            res += digits.back();
        }
        else if (digits.size() + 1 == alphas.size()) {
            for (int i = 0; i < digits.size(); ++i) {
                res += alphas[i];
                res += digits[i];
            }
            res += alphas.back();
        }
        else {
            return "";
        }
        return res;
    }
};

int main() {
    Solution S;
    string s = "ab123";
    auto res = S.reformat(s);
    cout << res << endl;
}