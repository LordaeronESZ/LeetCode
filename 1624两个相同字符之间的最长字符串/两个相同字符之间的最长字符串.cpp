#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        unordered_map<int, int> chInd;
        for (int i = 0; i < s.size(); ++i) {
            if (chInd.count(s[i]) != 0) {
                res = max(res, i - chInd[s[i]] - 1);
            }
            else {
                chInd[s[i]] = i;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    string s = "cabbac";
    auto res = S.maxLengthBetweenEqualCharacters(s);
    cout << res << endl;
}