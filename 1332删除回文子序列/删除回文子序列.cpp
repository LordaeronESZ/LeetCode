#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int removePalindromeSub(string s) {
        int p = 0, q = s.size() - 1;
        while (p < q) {
            if (s[p] != s[q])
                return 2;
            p++;
            q--;
        }
        return 1;
    }
};
int main() {
    Solution S;
    string s = "aabaa";
    auto res = S.removePalindromeSub(s);
    cout << res << endl;
    return 0;
}