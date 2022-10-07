#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
            }
            else {
                sum = nums[i];
            }
            res = max(res, sum);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 12,17,15,13,10,11,12 };
    auto res = S.maxAscendingSum(nums);
    cout << res << endl;
}