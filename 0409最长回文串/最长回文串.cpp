#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> chrCnt;
        for (const auto& chr : s) {
            chrCnt[chr]++;
        }
        int res = 0, sum = 0;
        for (const auto& p : chrCnt) {
            int cnt = p.second;
            if (cnt >= 2) {
                res += cnt - cnt % 2;
            }
            sum += cnt;
        }
        return res + (sum != res);
    }
};
int main() {
    Solution S;
    string s = "abccccdd";
    auto res = S.longestPalindrome(s);
    cout << res << endl;
    return 0;
}