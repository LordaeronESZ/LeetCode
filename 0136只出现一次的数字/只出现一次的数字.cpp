#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums.front();
        for (size_t i = 1; i < nums.size(); i++)
            res ^= nums[i];
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 2,2,1 };
    auto res = S.singleNumber(nums);
    cout << res << endl;
    return 0;
}