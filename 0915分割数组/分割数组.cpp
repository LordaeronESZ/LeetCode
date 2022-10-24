#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n, INT32_MIN);
        vector<int> rightMin(n, INT32_MAX);
        int maxVal = INT32_MIN;
        for (int i = 0; i < n; ++i) {
            maxVal = max(maxVal, nums[i]);
            leftMax[i] = maxVal;
        }
        int minVal = INT32_MAX;
        for (int i = n - 2; i >= 0; --i) {
            minVal = min(minVal, nums[i + 1]);
            rightMin[i] = minVal;
        }
        for (int i = 0; i < n; ++i) {
            if (leftMax[i] <= rightMin[i]) {
                return i + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution S;
    vector<int> nums = { 1,1,1,0,6,12 };
    auto res = S.partitionDisjoint(nums);
    cout << res << endl;
}