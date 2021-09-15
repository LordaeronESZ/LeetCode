#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1;
        int first = -1, second = -1;
        while (l <= r) {
            if (target > nums[l])
                l++;
            else if (target == nums[l])
                first = l;
            else
                break;
            if (target < nums[r])
                r--;
            else if (target == nums[r])
                second = r;
            else
                break;
            if (first != -1 && second != -1)
                break;
        }
        vector<int> res = { first,second };
        return res;
    }
};
int main() {
    vector<int> nums = { 5,7,7,8,8,10 };
    vector<int> nums2 = {};
    int target = 10;
    Solution S;
    vector<int> res = S.searchRange(nums2, target);
    for (auto r : res)
        cout << r << " ";
    return 0;
}