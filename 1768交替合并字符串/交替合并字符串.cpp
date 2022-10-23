#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int p = 0, q = 0;
        while (p < word1.size() && q < word2.size()) {
            res += word1[p++];
            res += word2[q++];
        }
        while (p < word1.size()) {
            res += word1[p++];
        }
        while (q < word2.size()) {
            res += word2[q++];
        }
        return res;
    }
};

int main() {
    Solution S;
    string s1 = "abcd";
    string s2 = "pq";
    auto res = S.mergeAlternately(s1, s2);
    cout << res << endl;
}