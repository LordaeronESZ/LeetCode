#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int index = 1;
        while (index < nums.size())
        {
            if (nums[index] == nums[index - 1]) {
                auto it = nums.begin() + index;
                nums.erase(it);
            }
            else {
                index++;
            }
        }
        return nums.size();
    }
};
int main() {
    // vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
    // vector<int> nums = { 1,1,2 };
    vector<int> nums = { 1,2 };
    Solution S;
    S.removeDuplicates(nums);
    for (auto n : nums)
        cout << n << " ";
    return 0;
}