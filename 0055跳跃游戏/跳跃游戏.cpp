#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] >= end - i)
                end = i;
        }
        if (!end)
            return true;
        return false;
    }
};
int main() {
    vector<int> nums = { 2,3,1,1,4 };
    vector<int> nums2 = { 3,2,1,0,4 };
    Solution S;
    auto res = S.canJump(nums2);
    cout << res << endl;
    return 0;
}