#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch : s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};
int main() {
    Solution S;
    string s = "A man, a plan, a canal: Panama";
    string s1 = "OP";
    auto res = S.isPalindrome(s1);
    cout << res << endl;
    return 0;
}