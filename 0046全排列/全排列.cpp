#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        Func(res, nums, 0, nums.size() - 1);
        return res;
    }
    void Func(vector<vector<int>>& res, vector<int>& nums, int p, int  q) {
        if (p == q)
            res.push_back(nums);
        else {
            for (int i = p; i <= q; i++) {
                swap(nums[p], nums[i]);
                Func(res, nums, p + 1, q);
                swap(nums[p], nums[i]);
            }
        }
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,2,3 };
    auto res = S.permute(nums);
    for (auto re : res) {
        for (auto r : re)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}