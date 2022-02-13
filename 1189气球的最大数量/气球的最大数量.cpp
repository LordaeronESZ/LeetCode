#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> alphaMap;
        for (const auto& chr : text) {
            alphaMap[chr]++;
        }
        vector<int> numVec = { alphaMap['b'], alphaMap['a'], alphaMap['l'] / 2, alphaMap['o'] / 2, alphaMap['n'] };
        return *min_element(numVec.begin(), numVec.end());
    }
};
int main() {
    Solution S;
    string text = "loonbalxballpoon";
    auto res = S.maxNumberOfBalloons(text);
    cout << res << endl;
    return 0;
}