#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxIndex = 0, maxTimes = 0;
        for (int i = 0; i < releaseTimes.size(); i++) {
            if (!i) {
                maxTimes = releaseTimes[i];
                maxIndex = i;
            }
            else if (releaseTimes[i] - releaseTimes[i - 1] > maxTimes) {
                maxTimes = releaseTimes[i] - releaseTimes[i - 1];
                maxIndex = i;
            }
            else if (releaseTimes[i] - releaseTimes[i - 1] == maxTimes) {
                if (keysPressed[i] > keysPressed[maxIndex]) {
                    maxTimes = releaseTimes[i] - releaseTimes[i - 1];
                    maxIndex = i;
                }
            }
        }
        return keysPressed[maxIndex];
    }
};
int main() {
    Solution S;
    vector<int> releaseTimes = { 12,23,36,46,62 };
    string keysPressed = "spuda";
    auto res = S.slowestKey(releaseTimes, keysPressed);
    cout << res << endl;
    return 0;
}