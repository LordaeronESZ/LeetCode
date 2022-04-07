#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        for (int i = 0; i < s.size(); ++i) {
            s = s.substr(1) + s.front();
            if (s == goal)
                return true;
        }
        return false;
    }
};
int main() {
    Solution S;
    string s = "abcde", goal = "cdeab";
    auto res = S.rotateString(s, goal);
    cout << res << endl;
}