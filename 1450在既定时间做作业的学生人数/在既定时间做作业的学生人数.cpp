#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0, n = startTime.size();
        for (int i = 0; i < n; ++i) {
            if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> startTime = { 1,2,3 };
    vector<int> endTime = { 3,2,7 };
    int queryTime = 4;
    auto res = S.busyStudent(startTime, endTime, queryTime);
    cout << res << endl;
}