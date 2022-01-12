#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        int first = nums[0], second = INT32_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > second)
                return true;
            else if (nums[i] > first)
                second = nums[i];
            else
                first = nums[i];
        }
        return false;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 2,1,5,0,4,6 };
    vector<int> nums2 = { 5,4,3,2,1 };
    auto res = S.increasingTriplet(nums2);
    cout << res << endl;
    return 0;
}