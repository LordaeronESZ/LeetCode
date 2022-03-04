#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int minVal = INT_MAX, maxVal = INT_MIN;
            for (int j = i; j < n; j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                res += maxVal - minVal;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,2,3 };
    auto res = S.subArrayRanges(nums);
    cout << res << endl;
    return 0;
}