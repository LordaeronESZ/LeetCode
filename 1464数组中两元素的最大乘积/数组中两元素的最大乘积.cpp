#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal = INT32_MIN, subMaxVal = INT32_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (maxVal < nums[i]) {
                subMaxVal = maxVal;
                maxVal = nums[i];
            }
            else if (subMaxVal < nums[i]) {
                subMaxVal = nums[i];
            }
        }
        return (maxVal - 1) * (subMaxVal - 1);
    }
};

int main() {
    Solution S;
    vector<int> nums = { 3,4,5,2 };
    auto res = S.maxProduct(nums);
    cout << res << endl;
}