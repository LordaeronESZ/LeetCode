#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        int avg = sum / k;
        sort(nums.begin(), nums.end());
        if (nums.back() > avg) return false;
        
        vector<bool> dp(1 << n, false);
        vector<int> curSum(1 << n, 0);
        dp[0] = true;
        for (int i = 0; i < (1 << n); ++i) {
            if (!dp[i]) continue;
            for (int j = 0; j < n; ++j) {
                if (curSum[i] + nums[j] > avg) break;
                if (((i >> j) & 1) == 0) {
                    int next = i | (1 << j);
                    if (!dp[next]) {
                        curSum[next] = (curSum[i] + nums[j]) % avg;
                        dp[next] = true;
                    }
                }
            }
        }
        return dp.back();
    }
};

int main() {
    Solution S;
    vector<int> nums = { 4, 3, 2, 3, 5, 2, 1 };
    int k = 4;
    auto res = S.canPartitionKSubsets(nums, k);
    cout << res << endl;
}