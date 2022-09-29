#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        s2 += s2;
        if (s2.find(s1) == s2.npos) return false;
        return true;
    }
};

int main() {
    Solution S;
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    auto res = S.isFlipedString(s1, s2);
    cout << res << endl;
}