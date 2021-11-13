#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2)
            return true;
        int wordType;
        if (word[0] >= 'a' && word[0] <= 'z')
            wordType = 3;
        else if (word[1] >= 'a' && word[1] <= 'z')
            wordType = 2;
        else
            wordType = 1;
        for (size_t i = 1; i < word.size(); i++) {
            if (i >= 2 && wordType == 1 && word[i] >= 'a' && word[i] <= 'z')
                return false;
            if (i >= 2 && wordType == 2 && word[i] >= 'A' && word[i] <= 'Z')
                return false;
            if (wordType == 3 && word[i] >= 'A' && word[i] <= 'Z')
                return false;
        }
        return true;
    }
};
int main() {
    Solution S;
    string word = "FlaG";
    auto res = S.detectCapitalUse(word);
    cout << res << endl;
    return 0;
}