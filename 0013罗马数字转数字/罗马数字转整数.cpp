#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
private:
    map<char, int> mapRoman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        int res = 0;
        for (auto it = s.begin(); it < s.end(); it++) {
            if (it == s.end() - 1) {
                res += mapRoman[*it];
                break;
            }
            if (mapRoman[*it] >= mapRoman[*(it + 1)])
                res += mapRoman[*it];
            else
                res -= mapRoman[*it];
        }
        return res;
    }
};
int main() {
    string s;
    Solution S;
    while (true) {
        cin >> s;
        if (s == "exit")
            break;
        int res = S.romanToInt(s);
        cout << res << endl;
    }
    return 0;
}