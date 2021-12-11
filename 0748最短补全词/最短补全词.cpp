#include<string>
#include<iostream>
#include<vector>
#include<array>
using namespace std;
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        array<int, 26> cnt{};
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                ++cnt[tolower(ch) - 'a'];
            }
        }
        int idx = -1;
        for (int i = 0; i < words.size(); ++i) {
            array<int, 26> c{};
            for (char ch : words[i]) {
                ++c[ch - 'a'];
            }
            bool ok = true;
            for (int j = 0; j < 26; ++j) {
                if (c[j] < cnt[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok && (idx < 0 || words[i].length() < words[idx].length())) {
                idx = i;
            }
        }
        return words[idx];
    }
};
int main() {
    Solution S;
    string licensePlate = "Ah71752";
    vector<string> words = { "suggest","letter","of","husband","easy","education","drug","prevent","writer","old" };
    auto res = S.shortestCompletingWord(licensePlate, words);
    cout << res << endl;
    return 0;
}