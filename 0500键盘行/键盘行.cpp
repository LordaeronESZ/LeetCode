#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> wordMap = { {'q',1},{'w',1},{'e',1},{'r',1},{'t',1},{'y',1},{'u',1},{'i',1},{'o',1},{'p',1},
            {'a',2},{'s',2},{'d',2},{'f',2},{'g',2},{'h',2},{'j',2},{'k',2},{'l',2},
            {'z',3},{'x',3},{'c',3},{'v',3},{'b',3},{'n',3},{'m',3} };
        vector<string> res;
        for (const auto& word : words) {
            int type_alpha = (word.front() >= 'A' && word.front() <= 'Z') ? wordMap[word.front() + ('a' - 'A')] : wordMap[word.front()];
            size_t i = 1;
            for (i = 1; i < word.size(); i++) {
                int type = (word[i] >= 'A' && word[i] <= 'Z') ? wordMap[word[i] + ('a' - 'A')] : wordMap[word[i]];
                if (type != type_alpha)
                    break;
            }
            if (i == word.size())
                res.emplace_back(word);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<string> words = { "Hello","Alaska","Dad","Peace" };
    auto res = S.findWords(words);
    for (const auto& element : res)
        cout << element << endl;
    return 0;
}