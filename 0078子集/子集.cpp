#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = { {} };
        for (auto it = nums.cbegin(); it < nums.cend(); it++) {
            vector<int> temp = { *it };
            res.emplace_back(temp);
            if (it == nums.cbegin())
                continue;
            else {
                int size = res.size();
                for (size_t i = 1; i < size - 1; i++) {
                    vector<int> temp_v = res[i];
                    temp_v.emplace_back(*it);
                    res.emplace_back(temp_v);
                }
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,2,3 };
    vector<int> nums2 = { 0 };
    auto res = S.subsets(nums);
    for (auto const& re : res) {
        for (auto const& r : re)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}
