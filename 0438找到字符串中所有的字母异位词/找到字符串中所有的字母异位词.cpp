#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size())
            return {};
        int psize = p.size();
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        vector<int> res;
        for (int i = 0; i < p.size(); i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }
        if (pCount == sCount)
            res.emplace_back(0);
        for (int i = 0; i < s.size() - psize; i++) {
            sCount[s[i] - 'a']--;
            sCount[s[i + psize] - 'a']++;
            if (pCount == sCount)
                res.emplace_back(i + 1);
        }
        return res;
    }
};
int main() {
    Solution S;
    string s = "baa";
    string p = "aa";
    auto res = S.findAnagrams(s, p);
    for (const auto& re : res)
        cout << re << " ";
    return 0;
}