#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLength = 1;
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    res[i] = max(res[i], res[j] + 1);
                maxLength = max(maxLength, res[i]);
            }
        }
        return maxLength;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,3,6,7,9,4,10,5,6 };
    auto res = S.lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}