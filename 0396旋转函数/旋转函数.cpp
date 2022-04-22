#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, F0 = 0, F1 = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            F0 += nums[i] * i;
        }
        int res = F0;
        for (int i = 1; i < n; ++i) {
            F1 = F0 + sum - n * nums[n - i];
            res = max(res, F1);
            F0 = F1;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 4,3,2,6 };
    auto res = S.maxRotateFunction(nums);
    cout << res << endl;
}