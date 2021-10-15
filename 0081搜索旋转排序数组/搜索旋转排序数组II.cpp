#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        size_t l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (l + 1 < nums.size() && r > l) {
                while (nums[l] == nums[l + 1]) {
                    l++;
                    if (l + 1 >= nums.size() && r <= l)
                        break;
                }
            }
            if (r >= 1 && r > l) {
                while (nums[r] == nums[r - 1]) {
                    r--;
                    if (r < 1 && r <= l)
                        break;
                }
            }
            size_t mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            //左半部分有序
            if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            //右半部分有序
            else {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 2,5,6,0,0,1,2 };
    vector<int> nums2 = { 3,1,1 };
    int target = 0;
    auto res = S.search(nums2, target);
    cout << res << endl;
    return 0;
}