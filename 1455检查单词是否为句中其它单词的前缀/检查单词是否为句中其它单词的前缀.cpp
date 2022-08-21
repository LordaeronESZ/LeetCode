#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        for (int i = 0; ss >> word; ++i) {
            if (searchWord.size() > word.size()) {
                continue;
            }
            bool flag = true;
            for (int j = 0; j < searchWord.size(); ++j) {
                if (word[j] != searchWord[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution S;
    string sentence = "love errichto jonathan dumb";
    string searchWord = "dumb";
    auto res = S.isPrefixOfWord(sentence, searchWord);
    cout << res << endl;
}