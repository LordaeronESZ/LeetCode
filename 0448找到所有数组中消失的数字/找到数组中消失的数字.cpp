#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (const auto& num : nums) {
            int x = (num - 1) % nums.size();
            nums[x] += nums.size();
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= nums.size())
                res.emplace_back(i + 1);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 4,3,2,7,9,2,3,1,9 };
    vector<int> nums1 = { 1,1,1,1,1,1,1 };
    auto res = S.findDisappearedNumbers(nums);
    for (const auto& element : res)
        cout << element << " ";
    return 0;
}