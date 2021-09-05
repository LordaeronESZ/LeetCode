#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size();
        int l = -1, r = i - 1;
        bool flag = false;
        while (i--)
        {
            if (s[i] != 32 && !flag) {
                r = i;
                flag = true;
            }
            if (s[i] == 32 && flag) {
                l = i;
                break;
            }
        }
        return r - l;
    }
};
int main() {
    string s1 = "HelloWorld";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";
    Solution S;
    int res = S.lengthOfLastWord(s3);
    cout << res << endl;
    return 0;
}