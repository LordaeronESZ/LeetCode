#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //int findClosest(vector<string>& words, string word1, string word2) {
    //    unordered_map<string, vector<int>> strMap;
    //    for (int i = 0; i < words.size(); ++i) {
    //        strMap[words[i]].emplace_back(i);
    //    }
    //    int res = INT32_MAX;
    //    auto ind1 = strMap[word1];
    //    auto ind2 = strMap[word2];
    //    for (const auto& i1 : ind1) {
    //        for (const auto& i2 : ind2) {
    //            res = min(res, abs(i1 - i2));
    //        }
    //    }
    //    return res;
    //}
    int findClosest(vector<string>& words, string word1, string word2) {
        int res = INT32_MAX;
        int i1 = -1, i2 = -1;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                i1 = i;
                if (i2 != -1) {
                    res = min(res, i1 - i2);
                }
            }
            else if (words[i] == word2) {
                i2 = i;
                if (i1 != -1) {
                    res = min(res, i2 - i1);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<string> words = { "I","am","a","student","from","a","university","in","a","city" };
    string word1 = "a";
    string word2 = "student";
    auto res = S.findClosest(words, word1, word2);
    cout << res << endl;
}