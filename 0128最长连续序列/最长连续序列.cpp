#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int res = 1;
        int curLength = 1;
        int lastVal = nums.front();
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                continue;
            if (nums[i] == lastVal + 1)
                curLength++;
            else
                curLength = 1;
            if (curLength > res)
                res = curLength;
            lastVal = nums[i];
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 100,4,200,1,3,2 };
    vector<int> nums1 = { 1,2,0,1,1,1,0,0,2,2,2,2 };
    auto res = S.longestConsecutive(nums1);
    cout << res << endl;
    return 0;
}