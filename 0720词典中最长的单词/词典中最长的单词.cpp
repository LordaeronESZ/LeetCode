#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
    string longestWord(vector<string>& words) {
        auto cmp = [](const string& s1, const string& s2) {
            if (s1.size() == s2.size())
                return s1 < s2;
            return s1.size() > s2.size();
        };
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> strSet;
        for (int i = 0; i < words.size(); ++i) {
            strSet.emplace(words[i]);
        }
        for (int i = 0; i < words.size(); ++i) {
            string str = words[i];
            while (true) {
                str.pop_back();
                if (str.empty()) {
                    return words[i];
                }
                else if (strSet.find(str) == strSet.end()) {
                    break;
                }
            }
        }
        return "";
    }
};
int main() {
    Solution S;
    vector<string> words = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    auto res = S.longestWord(words);
    cout << res << endl;
    return 0;
}