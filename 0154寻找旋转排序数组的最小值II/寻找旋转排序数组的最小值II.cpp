#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1])
                return nums[i];
        }
        return nums[0];
    }
};

int main() {
    Solution S;
    vector<int> nums = { 2,2,2,0,1 };
    auto res = S.findMin(nums);
    cout << res << endl;
}