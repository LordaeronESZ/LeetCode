#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.back() == nums.size() - 1)
            return nums.size();
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == mid)
                left = mid + 1;
            else if(nums[mid] > mid)
                right = mid - 1;
        }
        return left;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 9,6,4,2,3,5,7,0,1 };
    vector<int> nums1 = { 0,2,3 };
    auto res = S.missingNumber(nums1);
    cout << res << endl;
    return 0;
}