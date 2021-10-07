#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        bool started = false;
        for (auto const& ch : s) {
            if (ch == ' ') {
                if (started) {
                    started = false;
                    res++;
                }
            }
            else {
                started = true;
            }
        }
        return started ? res + 1 : res;
    }
};
int main() {
    Solution S;
    string s = "Hello, my name is John, and I'm going to test my program that calculates the count of words.";
    string s2;
    auto res = S.countSegments(s2);
    cout << res << endl;
    return 0;
}