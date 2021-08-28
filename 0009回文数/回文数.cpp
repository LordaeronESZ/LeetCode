#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string str = to_string(x);
        auto p = str.begin();
        auto q = str.end() - 1;
        while (p <= q && p != str.end() - 1 && q != str.begin()) {
            if (*p != *q)
                return false;
            p++, q--;
        }
        return true;
    }
};
int main() {
    Solution S;
    int x;
    cin >> x;
    cout << S.isPalindrome(x) << endl;
    return 0;
}