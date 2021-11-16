#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = INT32_MIN, sum = INT32_MIN;
        for (const auto& n : nums) {
            if (sum > 0)
                sum += n;
            else
                sum = n;
            if (sum > max_sum)
                max_sum = sum;
        }
        int min_sum = INT32_MAX;
        int sumVal = 0;
        sum = INT32_MAX;
        for (const auto& n : nums) {
            sumVal += n;
            if (sum < 0)
                sum += n;
            else
                sum = n;
            if (sum < min_sum)
                min_sum = sum;
        }
        if (sumVal == min_sum)
            return max_sum;
        return max(max_sum, sumVal - min_sum);
    }
};
int main() {
    Solution S;
    vector<int> nums = { -5,-3,-5,1 };
    auto res = S.maxSubarraySumCircular(nums);
    cout << res << endl;
    return 0;
}