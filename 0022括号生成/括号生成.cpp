#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        Func(res, 2 * n, n, n, "");
        return res;
    }
    //res:结果    height:深度   l，r:左右括号的剩余个数
    void Func(vector<string>& res, int deep, int l, int r, string s) {
        if (deep == 0) {
            res.push_back(s);
            return;
        }
        if (l > 0)
            Func(res, deep - 1, l - 1, r, s + "(");
        if (r > l)
            Func(res, deep - 1, l, r - 1, s + ")");
    }
};
int main() {
    int n = 4;
    Solution S;
    vector<string> res = S.generateParenthesis(n);
    for (auto r : res)
        cout << r << endl;
    return 0;
}