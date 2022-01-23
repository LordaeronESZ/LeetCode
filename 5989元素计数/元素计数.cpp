#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countElements(vector<int>& nums) {
        int minVal = INT32_MAX, maxVal = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > minVal && nums[i] < maxVal)
                res++;
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 11, 7, 2, 15 };
    auto res = S.countElements(nums);
    cout << res << endl;
    return 0;
}