#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        vector<string> list;
        int frontIndex = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                string newStr = text.substr(frontIndex, i - frontIndex);
                list.emplace_back(newStr);
                frontIndex = i + 1;
            }
            if (i == text.size() - 1) {
                list.emplace_back(text.substr(frontIndex, i - frontIndex + 1));
            }
        }
        for (int i = 2; i < list.size(); i++) {
            if (list[i - 2] == first && list[i - 1] == second) {
                res.emplace_back(list[i]);
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    string text = "alice is a good girl she is a good student";
    string first = "a";
    string second = "good";
    auto res = S.findOcurrences(text, first, second);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}