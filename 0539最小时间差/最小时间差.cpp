#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    inline int toInt(const string& s) {
        return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    }

    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440)
            return 0;
        sort(timePoints.begin(), timePoints.end());
        int posRes = abs(toInt(timePoints.front()) - toInt(timePoints.back()));
        int res = min(posRes, 1440 - posRes);
        for (int i = 1; i < timePoints.size(); i++) {
            posRes = abs(toInt(timePoints[i]) - toInt(timePoints[i - 1]));
            res = min(res, min(posRes, 1440 - posRes));
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<string> timePoints = { "23:38", "00:00", "12:49", "13:11", "13:02"};
    auto res = S.findMinDifference(timePoints);
    cout << res << endl;
    return 0;
}