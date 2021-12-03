#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int bestIndex = 0, bestVal = INT32_MIN;
        int sum = 0;
        for (const auto& num : nums)
            sum += num;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (sum - 2 * nums[j] > bestVal) {
                    bestVal = sum - 2 * nums[j];
                    bestIndex = j;
                }
            }
            sum -= 2 * nums[bestIndex];
            nums[bestIndex] *= -1;
            bestVal = INT32_MIN;
        }
        return sum;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 5,6,9,-3,3 };
    int k = 2;
    auto res = S.largestSumAfterKNegations(nums, k);
    cout << res << endl;
    return 0;
}