#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count0++;
            else if (nums[i] == 1)
                count1++;
            else if (nums[i] == 2)
                count2++;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i < count0)
                nums[i] = 0;
            else if (i < count0 + count1)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};
int main() {
    Solution S;
    vector<int> nums = { 2,0,2,1,1,0 };
    S.sortColors(nums);
    for (auto const& n : nums)
        cout << n << " ";
    return 0;
}