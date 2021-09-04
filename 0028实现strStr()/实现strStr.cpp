#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        auto h = haystack.begin();
        auto n = needle.begin();
        int index = 0;
        while (h < haystack.end() && n < needle.end()) {
            if (*h == *n) {
                if (n == needle.end() - 1)
                    return index;
                h++;
                n++;
            }
            else {
                h = haystack.begin() + ++index;
                n = needle.begin();
            }
        }
        return -1;
    }
};
int main() {
    // string haystack = "hello";
    // string needle = "ll";
    string haystack = "aaaaa";
    string needle = "bba";
    Solution S;
    int index = S.strStr(haystack, needle);
    cout << index << endl;
    return 0;
}