#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        //res[i]表示0-i号房间的最优解
        vector<int> res(nums.size());
        if (nums.size() == 1)
            return nums[0];
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        for (size_t i = 2; i < nums.size(); i++) {
            res[i] = max(res[i - 2] + nums[i], res[i - 1]);
        }
        return res.back();
    }
};
int main() {
    Solution S;
    vector<int> nums = { 2,7,9,3,1 };
    auto res = S.rob(nums);
    cout << res << endl;
    return 0;
}