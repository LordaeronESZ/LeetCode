#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maxLength = 0;
        //positive[i](negtive[i])表示开头到nums[i]的乘积为正数(负数)的最长子数组长度
        vector<int> positive(nums.size());
        vector<int> negtive(nums.size());
        if (nums[0] > 0) {
            positive[0] = 1;
            maxLength = 1;
        }
        else if (nums[0] < 0)
            negtive[0] = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                positive[i] = 0;
                negtive[i] = 0;
            }
            else if (nums[i] > 0) {
                positive[i] = positive[i - 1] + 1;
                negtive[i] = negtive[i - 1] > 0 ? negtive[i - 1] + 1 : 0;
            }
            else {
                positive[i] = negtive[i - 1] > 0 ? negtive[i - 1] + 1 : 0;
                negtive[i] = positive[i - 1] + 1;
            }
            maxLength = max(maxLength, positive[i]);
        }
        return maxLength;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1 };
    auto res = S.getMaxLen(nums);
    cout << res << endl;
    return 0;
}