#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxRes(nums.size());
        vector<int> minRes(nums.size());
        maxRes[0] = nums[0];
        minRes[0] = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            maxRes[i] = max(max(maxRes[i - 1] * nums[i], minRes[i - 1] * nums[i]), nums[i]);
            minRes[i] = min(min(maxRes[i - 1] * nums[i], minRes[i - 1] * nums[i]), nums[i]);
        }
        return *max_element(maxRes.begin(), maxRes.end());
    }
};
int main() {
    Solution S;
    vector<int> nums = { 2,-2,1,-2 };
    auto res = S.maxProduct(nums);
    cout << res << endl;
    return 0;
}