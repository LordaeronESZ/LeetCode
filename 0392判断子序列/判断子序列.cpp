#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto it1 = s.begin(), it2 = t.begin();
        while (it1 < s.end() && it2 < t.end()) {
            if (*it1 == *it2)
                it1++;
            it2++;
        }
        return it1 == s.end();
    }
};
int main() {
    Solution S;
    string s = "abc";
    string t = "ahbgdc";
    auto res = S.isSubsequence(s, t);
    cout << res << endl;
    return 0;
}