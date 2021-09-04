#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (auto i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= target)
                return i;
        }
        return nums.size();
    }
};
int main() {
    vector<int> nums = { 1, 3, 5 };
    int target = 4;
    Solution S;
    int res = S.searchInsert(nums, target);
    cout << res << endl;
    return 0;
}