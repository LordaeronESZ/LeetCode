#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
int main() {
    Solution S;
    string s = "anagram";
    string t = "nagaram";
    auto res = S.isAnagram(s, t);
    cout << res << endl;
    return 0;
}