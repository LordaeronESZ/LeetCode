#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int minDis = INT32_MAX;
        char res;
        for (int i = 0; i < letters.size(); ++i) {
            int dis = target <= letters[i] ? letters[i] - target : 26 - (target - letters[i]);
            if (dis && dis < minDis) {
                minDis = dis;
                res = letters[i];
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<char> letters = { 'c','f','j' };
    char target = 'c';
    auto res = S.nextGreatestLetter(letters, target);
    cout << res << endl;
}