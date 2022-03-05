#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b)
            return -1;
        return max(a.size(), b.size());
    }
};
int main() {
    Solution S;
    string a = "aa", b = "ccc";
    auto res = S.findLUSlength(a, b);
    cout << res << endl;
    return 0;
}