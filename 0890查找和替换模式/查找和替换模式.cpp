#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        unordered_map<char, char> wordMap;
        unordered_map<char, char> patternMap;
        for (const auto& word : words) {
            wordMap.clear();
            patternMap.clear();
            bool isValid = true;
            for (int i = 0; i < word.size(); ++i) {
                if (!wordMap.count(word[i]) && !patternMap.count(pattern[i])) {
                    wordMap.emplace(word[i], pattern[i]);
                    patternMap.emplace(pattern[i], word[i]);
                }
                else if (wordMap.count(word[i]) && patternMap.count(pattern[i])){
                    if (wordMap[word[i]] != pattern[i]) {
                        isValid = false;
                        break;
                    }
                }
                else {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                res.emplace_back(word);
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<string> words = { "abc","deq","mee","aqq","dkd","ccc" };
    string pattern = "abb";
    auto res = S.findAndReplacePattern(words, pattern);
    for (const auto& re : res) {
        cout << re << " ";
    }
}