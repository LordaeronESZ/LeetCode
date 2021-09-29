#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = { intervals.front() };
        for (auto it = intervals.begin() + 1; it < intervals.end(); it++) {
            //¸²¸Ç
            if (res.back().back() >= it->back())
                continue;
            //ºÏ²¢
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
    vector<vector<int>> intervals = { {1,3},{2,6},{6,10},{11,18} };
    vector<vector<int>> intervals2 = { {1,4},{2,3} };
    vector<vector<int>> intervals3 = { {1,5},{2,7} };
    auto res = S.merge(intervals3);
    for (auto r : res)
        cout << r.front() << " " << r.back() << '\t';
    return 0;
}