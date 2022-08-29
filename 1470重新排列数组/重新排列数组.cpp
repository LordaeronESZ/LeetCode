#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            res.emplace_back(nums[i]);
            res.emplace_back(nums[i + n]);
        }
        return res;
    }
};

int main() {
    Solution S;
    int n = 3;
    vector<int> nums = { 2,5,1,3,4,7 };
    auto res = S.shuffle(nums, n);
    for (const auto& re : res) {
        cout << re << " ";
    }
}