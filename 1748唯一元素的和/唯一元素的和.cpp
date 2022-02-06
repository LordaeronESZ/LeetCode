#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 && nums[i] != nums[i + 1])
                res += nums[i];
            else if (i == nums.size() - 1 && nums[i] != nums[i - 1])
                res += nums[i];
            else if (i > 0 && i < nums.size() - 1 && nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                res += nums[i];
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,1,3,6,4,2,4,7 };
    auto res = S.sumOfUnique(nums);
    cout << res << endl;
    return 0;
}