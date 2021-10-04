#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        for (auto const& chr : s) {
            if (chr != '-') {
                if (chr >= 'a' && chr <= 'z')
                    res.push_back(chr - ('a' - 'A'));
                else
                    res.push_back(chr);
            }
        }
        for (int it = static_cast<int>(res.size()) - k; it > 0; it -= k) {
            res.insert(it, "-");
            if (it < k)
                break;
        }
        return res;
    }
};
int main() {
    Solution S;
    string s = "0123456789";
    string s1 = "2";
    int k = 1;
    int k1 = 2;
    auto res = S.licenseKeyFormatting(s1, k1);
    cout << res << endl;
    return 0;
}