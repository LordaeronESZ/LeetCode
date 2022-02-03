#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 1, res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid)
                    cnt++;
            }
            if (cnt <= mid) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                res = mid;
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 3,1,3,4,2 };
    auto res = S.findDuplicate(nums);
    cout << res << endl;
    return 0;
}