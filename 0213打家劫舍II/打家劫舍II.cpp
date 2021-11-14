#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> res1(nums.size() - 1);
        vector<int> res2(nums.size() - 1);
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        //从nums[0]到nums[num.size() - 2]
        res1[0] = nums[0];
        res1[1] = max(nums[0], nums[1]);
        for (size_t i = 2; i < nums.size() - 1; i++) {
            res1[i] = max(res1[i - 2] + nums[i], res1[i - 1]);
        }
        //从nums[1]到nums[nums.size() - 1]
        res2[0] = nums[1];
        res2[1] = max(nums[1], nums[2]);
        for (size_t i = 2; i < nums.size() - 1; i++) {
            res2[i] = max(res2[i - 2] + nums[i + 1], res2[i - 1]);
        }
        return max(res1.back(), res2.back());
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,7,9,2 };
    auto res = S.rob(nums);
    cout << res << endl;
    return 0;
}