#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posVec;
        vector<int> negVec;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                posVec.emplace_back(nums[i]);
            if (nums[i] < 0)
                negVec.emplace_back(nums[i]);
        }
        vector<int> res;
        for (int i = 0; i < posVec.size(); i++) {
            res.emplace_back(posVec[i]);
            res.emplace_back(negVec[i]);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 3,1,-2,-5,2,-4 };
    auto res = S.rearrangeArray(nums);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}