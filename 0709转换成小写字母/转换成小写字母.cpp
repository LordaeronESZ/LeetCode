#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
        for (auto& ch : s) {
            if (ch >= 'A' && ch <= 'Z')
                ch = tolower(ch);
        }
        return s;
    }
};
int main() {
    Solution S;
    string s = "LOVELY";
    auto res = S.toLowerCase(s);
    cout << res << endl;
    return 0;
}