#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    int popCnt(int num) {
        int res = 0;
        while (num >= 1) {
            if (num % 2)
                res++;
            num /= 2;
        }
        return num ? res + 1 : res;
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (popCnt(h) + popCnt(m) == turnedOn) {
                    res.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    int turnedOn = 1;
    auto res = S.readBinaryWatch(turnedOn);
    for (const auto& re : res) {
        cout << re << endl;
    }
    return 0;
}
