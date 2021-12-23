#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    //判断s1是否是s2的子串
    bool isSub(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            int j;
            for (j = i; j - i < s1.size(); j++) {
                if (s1[j - i] != s2[j])
                    break;
            }
            if (j - i == s1.size())
                return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        string temp;
        int i;
        for (i = 0; temp.size() <= 2 * a.size() + b.size(); i++) {
            if (isSub(b, temp))
                return i;
            temp += a;
        }
        return -1;
    }
};
int main() {
    Solution S;
    string a = "abcd";
    string b = "cdabcdab";
    //cout << S.isSub("wxyz", "abcabcabc") << endl;
    auto res = S.repeatedStringMatch(a, b);
    cout << res << endl;
    return 0;
}