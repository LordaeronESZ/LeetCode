#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
private:
    const vector<string> strVec = { ".-","-...","-.-.","-..",".","..-.","--.",
        "....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-","-.--","--.." };
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> strSet;
        int res = 0;
        for (const auto& word : words) {
            string cipther;
            for (const auto& chr : word) {
                cipther += strVec[chr - 'a'];
            }
            if (!strSet.count(cipther)) {
                ++res;
                strSet.emplace(cipther);
            }
            cipther.clear();
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<string> words = { "gin", "zen", "gig", "msg" };
    auto res = S.uniqueMorseRepresentations(words);
    cout << res << endl;
}