#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char, int> chSeq;
    bool judge(const string& s1, const string& s2) {
        for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
            if (chSeq[s1[i]] == chSeq[s2[i]])
                continue;
            return chSeq[s1[i]] < chSeq[s2[i]];
        }
        return s1.size() <= s2.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); ++i) {
            chSeq[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            if (!judge(words[i], words[i + 1]))
                return false;
        }
        return true;
    }
};

int main() {
    Solution S;
    vector<string> words = { "hello","leetcode" };
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    auto res = S.isAlienSorted(words, order);
    cout << res << endl;
}