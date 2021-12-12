#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            int lastIndex = i, curLength = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[lastIndex]) {
                    curLength++;
                    lastIndex = j;
                }
                res = max(res, curLength);
                if (curLength + nums.size() - j - 1 < res)
                    break;
            }
        }
        return res; 
    }
};
int main() {
    Solution S;
    vector<int> nums = { 0,1,0,3,2,3 };
    auto res = S.lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}