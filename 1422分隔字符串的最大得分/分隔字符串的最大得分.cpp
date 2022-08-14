#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int points = s[0] == '0';
        for (int i = 1; i < s.size(); ++i) {
            points += s[i] == '1';
        }
        int res = points;
        for (int i = 1; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                ++points;
            }
            else {
                --points;
            }
            res = max(res, points);
        }
        return res;
    }
};

int main() {
    Solution S;
    string s = "00111";
    auto res = S.maxScore(s);
    cout << res << endl;
}