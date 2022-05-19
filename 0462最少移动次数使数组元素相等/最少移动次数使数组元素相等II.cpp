#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int avg = n % 2 ? nums[n / 2] : (nums[n / 2] + nums[n / 2 - 1]) / 2;
        int res = 0;
        for (const auto& num : nums) {
            res += abs(num - avg);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 1,10,2,9 };
    auto res = S.minMoves2(nums);
    cout << res << endl;
}