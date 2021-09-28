#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto it = intervals.begin();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        while (it < intervals.end() - 1) {
            if (it->back() >= (it + 1)->back()) {
                intervals.erase(it + 1);
            }
            else if (it->back() >= (it + 1)->front()) {
                it->back() = (it + 1)->back();
                intervals.erase(it + 1);
            }
            else
                it++;
        }
        return intervals;
    }
};
int main() {
    Solution S;
    vector<vector<int>> intervals = { {1,3},{2,6},{6,10},{11,18} };
    vector<vector<int>> intervals2 = { {1,4},{2,3} };
    auto res = S.merge(intervals);
    for (auto r : res)
        cout << r.front() << " " << r.back() << '\t';
    return 0;
}