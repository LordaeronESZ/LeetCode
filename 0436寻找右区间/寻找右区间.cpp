#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startInd;
        for (int i = 0; i < intervals.size(); ++i) {
            startInd.emplace_back(intervals[i][0], i);
        }
        sort(startInd.begin(), startInd.end());
        vector<int> res;
        for (int i = 0; i < intervals.size(); ++i) {
            int end = intervals[i][1];
            auto it = lower_bound(startInd.begin(), startInd.end(), make_pair(end, 0));
            if (it == startInd.end()) {
                res.emplace_back(-1);
            }
            else {
                res.emplace_back(it->second);
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> intervals = { {1, 4}, {2, 3}, {3, 4} };
    auto res = S.findRightInterval(intervals);
    for (const auto& re : res) {
        cout << re << " ";
    }
}