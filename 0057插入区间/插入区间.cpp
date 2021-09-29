#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        bool hasInserted = false;
        for (auto it = intervals.begin(); it < intervals.end(); it++) {
            if (newInterval.front() <= it->front()) {
                intervals.insert(it, newInterval);
                hasInserted = true;
                break;
            }
        }
        if (!hasInserted)
            intervals.push_back(newInterval);
        vector<vector<int>> res = { intervals.front() };
        for (auto it = intervals.begin() + 1; it < intervals.end(); it++) { 
            if (res.back().back() >= it->back())
                continue;
            else if (res.back().back() >= it->front())
                res.back().back() = it->back();
            else
                res.push_back(*it);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<vector<int>> intervals = { {1,2},{3,5},{6,7},{8,10},{12,16} };
    vector<vector<int>> intervals1 = { {1,5} };
    vector<int> newIntervals = { 4,8 };
    vector<int> newIntervals1 = { 2,7 };
    auto res = S.insert(intervals1, newIntervals1);
    for (auto const& re : res) {
        cout << re.front() << " " << re.back() << '\t';
    }
    return 0;
}