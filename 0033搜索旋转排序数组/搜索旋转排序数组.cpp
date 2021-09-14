#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        Func(nums, target, 0, (int)nums.size() - 1, res);
        return res;
    }
    void Func(vector<int>& nums, int target, int l, int r, int& res) {
        if (res != -1)
            return;
        if (l == r) {
            if (target == nums[l])
                res = l;
            return;
        }
        int mid = (l + r) / 2;
        //左半部分有序
        if (nums[l] < nums[mid]) {
            TwoSearch(nums, target, l, mid, res);
            Func(nums, target, mid + 1, r, res);
        }
        //右半部分有序
        else {
            TwoSearch(nums, target, mid + 1, r, res);
            Func(nums, target, l, mid, res);
        }
    }
    void TwoSearch(vector<int>& nums, int target, int l, int r, int& res) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target > nums[mid])
                l = mid + 1;
            else if (target < nums[mid])
                r = mid - 1;
            else {
                res = mid;
                return;
            }
        }
    }
};
int main() {
    vector<int> nums = { 3,4,5,6,7,8,9,0,1,2 };
    vector<int> nums2 = { 1 };
    int target = 0;
    Solution S;
    while (target <= 9) {
        int res = S.search(nums, target);
        cout << res << endl;
        target++;
    }
    return 0;
}