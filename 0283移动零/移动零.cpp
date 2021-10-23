#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i++) {
            if (!nums[i]) {
                for (size_t j = i + 1; j < nums.size(); j++) {
                    if (nums[j]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};
int main() {
    Solution S;
    vector<int> nums = { 0,1,0,3,12,3,5,0,0,0,32,1,0,1,0 };
    S.moveZeroes(nums);
    for (const auto& num : nums)
        cout << num << " ";
    return 0;
}