#include<iostream>
#include<string>
using namespace std;
class Solution {
private:
    bool isLegal(string token) {
        if (token.empty() || token[0] == ' ')
            return false;
        bool hasAppeared = false;
        for (int i = 0; i < token.size(); i++) {
            if (token[i] == '-') {
                if (hasAppeared || i == 0 || i == token.size() - 1 || !islower(token[i - 1]) || !islower(token[i + 1]))
                    return false;
                hasAppeared = true;
            }
            else if (token[i] == '!' || token[i] == '.' || token[i] == ',') {
                if (i != token.size() - 1)
                    return false;
            }
            else if (token[i] >= '0' && token[i] <= '9')
                return false;
        }
        return true;
    }
public:
    int countValidWords(string sentence) {
        int res = 0;
        string curStr;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                if (curStr.empty())
                    continue;
                if (isLegal(curStr))
                    res++;
                curStr.clear();
            }
            else {
                curStr += sentence[i];
            }
        }
        return isLegal(curStr) ? res + 1 : res;
    }
};
int main() {
    Solution S;
    string sentence = "!g 3 !sy ";
    auto res = S.countValidWords(sentence);
    cout << res << endl;
    return 0;
}