#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int val = 0, ind = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') --val;
            else if (s[i] == ')') ++val;
            if (!val) {
                string temp = s.substr(ind, i - ind);
                ind = i + 2;
                res += temp;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    string s = "(()())(())";
    auto res = S.removeOuterParentheses(s);
    cout << res << endl;
}