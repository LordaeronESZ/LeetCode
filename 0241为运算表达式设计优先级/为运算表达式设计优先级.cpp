#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                char ch = expression[i];
                auto res1 = diffWaysToCompute(expression.substr(0, i));
                auto res2 = diffWaysToCompute(expression.substr(i + 1));
                for (const auto r1 : res1) {
                    for (const auto r2 : res2) {
                        switch (ch)
                        {
                        case '+':
                            res.emplace_back(r1 + r2); break;
                        case '-':
                            res.emplace_back(r1 - r2); break;
                        case '*':
                            res.emplace_back(r1 * r2); break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
        if (res.empty())
            res.emplace_back(stoi(expression));
        return res;
    }
};
int main() {
    Solution S;
    string expression = "2*3-4*5";
    auto res = S.diffWaysToCompute(expression);
    for (const auto& re : res) {
        cout << re << endl;
    }
    return 0;
}