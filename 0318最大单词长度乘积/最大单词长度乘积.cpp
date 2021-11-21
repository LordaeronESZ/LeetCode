#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isLegal(const string& s1, const string& s2) {
        for (const auto& ch1 : s1) {
            for (const auto& ch2 : s2) {
                if (ch1 == ch2)
                    return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& x, const string& y) { return x.size() > y.size(); });
        int maxRes = 0;
        for (size_t i = 0; i < words.size(); i++) {
            for (size_t j = i + 1; j < words.size(); j++) {
                if (maxRes >= words[i].size() * words[j].size())
                    break;
                if (isLegal(words[i], words[j]))
                    maxRes = words[i].size() * words[j].size();
            }
        }
        return maxRes;
    }
};
int main() {
    Solution S;
    vector<string> words = { "abcw","baz","foo","bar","xtfn","abcdef" };
    auto res = S.maxProduct(words);
    cout << res << endl;
    return 0;
}