#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = INT32_MAX;
        for (size_t i = 0; i < nums.size() - k + 1; i++) {
            int val = nums[i + k - 1] - nums[i];
            res = min(val, res);
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 9,4,1,7 };
    int k = 2;
    auto res = S.minimumDifference(nums, k);
    cout << res << endl;
    return 0;
}