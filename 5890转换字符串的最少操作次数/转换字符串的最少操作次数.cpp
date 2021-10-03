#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'X') {
                ++ans;
                for (int j = i; j < i + 3 && j < s.size(); ++j) {
                    s[j] = 'O';
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution S;
    string s = "XXX"; // 012
    auto res = S.minimumMoves(s);
    cout << res << endl;
    return 0;
}