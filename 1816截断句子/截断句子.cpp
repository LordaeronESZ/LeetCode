#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        int count = 0;
        for (const auto& ch : s) {
            if (ch == ' ') {
                count++;
                if (count == k)
                    break;
            }
            res += ch;
        }
        return res;
    }
};
int main() {
    Solution S;
    string s = "What is the solution to this problem";
    int k = 4;
    auto res = S.truncateSentence(s, k);
    cout << res << endl;
    return 0;
}