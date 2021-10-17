#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    bool areNumbersAscending(string s) {
        bool hasStarted = false;
        string temp;
        int lastValue = -1;
        for (auto it = s.begin(); it < s.end(); it++) {
            if (*it >= '0' && *it <= '9') {
                if (!hasStarted) {
                    temp.push_back(*it);
                    hasStarted = true;
                }
                else {
                    temp.push_back(*it);
                }
            }
            else {
                if (hasStarted) {
                    int tempValue = toInt(temp);
                    if (tempValue <= lastValue)
                        return false;
                    else
                        lastValue = tempValue;
                    temp.clear();
                }
                hasStarted = false;
            }
        }
        if (hasStarted) {
            int tempValue = toInt(temp);
            if (tempValue <= lastValue)
                return false;
            temp.clear();
        }
        return true;
    }
    int toInt(string& s) {
        int n = s.size();
        int res = 0;
        for (const auto& ch : s) {
            res += (ch - '0') * pow(10, n - 1);
            n--;
        }
        return res;
    }
};
int main() {
    Solution S;
    string s3("3213");
    cout << S.toInt(s3) << endl;
    string s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
    string s2 = "5 5";
    auto res = S.areNumbersAscending(s2);
    cout << res << endl;
    return 0;
}