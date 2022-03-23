#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool winnerOfGame(string colors) {
        int cntA = 0, cntB = 0;
        for (int i = 1; i < colors.size() - 1; ++i) {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
                ++cntA;
            if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
                ++cntB;
        }
        return cntA > cntB;
    }
};
int main() {
    Solution S;
    string colors = "AAABABB";
    auto res = S.winnerOfGame(colors);
    cout << res << endl;
    return 0;
}