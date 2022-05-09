#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> res(n + 1, 0);
        int minVal = 0, maxVal = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I')
                res[i] = minVal++;
            else if (s[i] == 'D')
                res[i] = maxVal--;
        }
        res.back() = minVal;
        return res;
    }
};

int main() {
    Solution S;
    string s = "IDID";
    auto res = S.diStringMatch(s);
    for (const auto& re : res) {
        cout << re << " ";
    }
}