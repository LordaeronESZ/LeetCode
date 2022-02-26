#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minVal = nums[0];
        int res = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minVal)
                res = max(res, nums[i] - minVal);
            minVal = min(minVal, nums[i]);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 7,1,5,4 };
    auto res = S.maximumDifference(nums);
    cout << res << endl;
    return 0;
}