#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (const auto& num : nums) {
            int ind = abs(num) - 1;
            if (nums[ind] < 0) {
                nums[ind] *= -1;
                res.emplace_back(ind + 1);
            }
            else {
                nums[ind] *= -1;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 10,2,5,10,9,1,1,4,3,7 };
    auto res = S.findDuplicates(nums);
    for (const auto& re : res) {
        cout << re << " ";
    }
}