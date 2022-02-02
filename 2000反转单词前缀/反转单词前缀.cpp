#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                for (int p = 0, q = i; p < q; p++, q--) {
                    swap(word[p], word[q]);
                }
                break;
            }
        }
        return word;
    }
};
int main() {
    Solution S;
    string word = "xyxzxe";
    char ch = 'z';
    auto res = S.reversePrefix(word, ch);
    cout << res << endl;
    return 0;
}