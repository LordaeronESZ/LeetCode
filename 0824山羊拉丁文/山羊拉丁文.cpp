#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    string toGoatLatin(string sentence) {
        string res;
        stringstream ss(sentence);
        string temp;
        for (int i = 1; ss >> temp; ++i) {
            char c = tolower(temp[0]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                res += temp;
            }
            else {
                res += temp.substr(1);
                res += temp[0];
            }
            res += "ma";
            res += string(i, 'a');
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};
int main() {
    Solution S;
    string sentence = "I speak Goat Latin";
    auto res = S.toGoatLatin(sentence);
    cout << res << endl;
}