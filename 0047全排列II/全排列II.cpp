#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        Func(res, nums, 0, nums.size() - 1);
        return res;
    }
    void Func(vector<vector<int>>& res, vector<int>& nums, int p, int  q) {
        if (p == q)
            res.push_back(nums);
        else {
            for (int i = p; i <= q; i++) {
                //若存在k之前已经交换过，则跳过
                int k;
                for (k = p; k <= i; k++) {
                    if (nums[k] == nums[i])
                        break;
                }
                if (k != i)
                    continue;
                swap(nums[p], nums[i]);
                Func(res, nums, p + 1, q);
                swap(nums[p], nums[i]);
            }
        }
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,2,2,2 };
    auto res = S.permuteUnique(nums);
    for (auto re : res) {
        for (auto r : re)
            cout << r << " ";
        cout << endl;
    }
    return 0;
}