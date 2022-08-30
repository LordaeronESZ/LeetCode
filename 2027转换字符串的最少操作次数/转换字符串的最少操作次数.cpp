#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'X') {
                ++res;
                i += 2;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    string s = "XXOX";
    auto res = S.minimumMoves(s);
    cout << res << endl;
}