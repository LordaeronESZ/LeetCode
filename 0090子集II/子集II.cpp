#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = { {} };
        int l, r, len = 0;
        for (auto it = nums.cbegin(); it < nums.cend(); it++) {
            if (it != nums.cbegin() && *it == *(it - 1))
                l = res.size() - len;
            else
                l = 0;
            r = res.size();
            len = r - l;
            for (size_t i = l; i < r; i++) {
                vector<int> temp_v = res[i];
                temp_v.emplace_back(*it);
                res.emplace_back(temp_v);
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,1 };
    auto res = S.subsetsWithDup(nums);
    for (const auto& re : res) {
        for (const auto& r : re)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}