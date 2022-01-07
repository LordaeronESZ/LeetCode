#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int res = 0, curDepth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                curDepth++;
            }
            else if (s[i] == ')') {
                curDepth--;
            }
            res = max(res, curDepth);
        }
        return res;
    }
};
int main() {
    Solution S;
    string s = "(1+(2*3)+((8)/4))+1";
    auto res = S.maxDepth(s);
    cout << res << endl;
    return 0;
}