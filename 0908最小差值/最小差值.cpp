#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minVal = INT32_MAX, maxVal = INT32_MIN;
        for (const auto& num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        return maxVal - minVal <= 2 * k ? 0 : maxVal - minVal - 2 * k;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 0,10 };
    int k = 2;
    int res = S.smallestRangeI(nums, k);
    cout << res << endl;
}